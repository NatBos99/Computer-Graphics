#include "mainview.h"
#include "model.h"
#include <iostream>

/**
 * @brief MainView::MainView
 *
 * Constructor of MainView
 *
 * @param parent
 */
MainView::MainView(QWidget *parent) : QOpenGLWidget(parent) {
    qDebug() << "MainView constructor";

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
}

/**
 * @brief MainView::~MainView
 *
 * Destructor of MainView
 * This is the last function called, before exit of the program
 * Use this to clean up your variables, buffers etc.
 *
 */
MainView::~MainView() {
    qDebug() << "MainView destructor";

    makeCurrent();

    destroyModelBuffers();
}

// --- OpenGL initialization

/**
 * @brief MainView::initializeGL
 *
 * Called upon OpenGL initialization
 * Attaches a debugger and calls other init functions
 */
void MainView::initializeGL() {
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    connect(&debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)),
             this, SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (debugLogger.initialize()) {
        qDebug() << ":: Logging initialized";
        debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
    }

    QString glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.1F, 0.1F, 0.1F, 0.0F);

    createShaderProgram();
    loadMesh(":/models/grid.obj");

    amp[0] = 0.03;
    freq[0] = 3.9;
    phase[0] = 0;

    amp[1] = 0.08;
    freq[1] = 1.3;
    phase[1] = 1;

    amp[2] = 0.02;
    freq[2] = 3.1;
    phase[2] = 2;

    amp[3] = 0.01;
    freq[3] = 7.2;
    phase[3] = -1;

    time = 0.0;

    // Initialize transformations.
    updateProjectionTransform();
    updateModelTransforms();

    // Start timer
    timer.start(1000.0 / 60.0);
}

void MainView::createShaderProgram() {
    // Create Phong shader program.
    phongShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_phong.glsl");
    phongShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_phong.glsl");
    phongShaderProgram.link();

    // Get the uniforms for the Phong shader program.
    uniformModelViewTransformPhong  = phongShaderProgram.uniformLocation("modelViewTransform");
    uniformProjectionTransformPhong = phongShaderProgram.uniformLocation("projectionTransform");
    uniformNormalTransformPhong     = phongShaderProgram.uniformLocation("normalTransform");
    uniformMaterialPhong            = phongShaderProgram.uniformLocation("material");
    uniformMaterialColorPhong       = phongShaderProgram.uniformLocation("materialColor");
    uniformLightPositionPhong       = phongShaderProgram.uniformLocation("lightPosition");
    uniformLightColorPhong          = phongShaderProgram.uniformLocation("lightColor");

    uniformAmp   = phongShaderProgram.uniformLocation("amplitude");
    uniformFreq  = phongShaderProgram.uniformLocation("frequency");
    uniformPhase = phongShaderProgram.uniformLocation("amplitudephase");

    uniformTime = phongShaderProgram.uniformLocation("time");

    // Create Normal shader program.
    normalShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_normal.glsl");
    normalShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_normal.glsl");
    normalShaderProgram.link();

    // Get the uniforms for the Normal shader program.
    uniformModelViewTransformNormal  = normalShaderProgram.uniformLocation("modelViewTransform");
    uniformProjectionTransformNormal = normalShaderProgram.uniformLocation("projectionTransform");
    uniformNormalTransformNormal     = normalShaderProgram.uniformLocation("normalTransform");
    uniformMaterialNormal            = normalShaderProgram.uniformLocation("material");
    uniformLightPositionNormal       = normalShaderProgram.uniformLocation("lightPosition");
    uniformLightColorNormal          = normalShaderProgram.uniformLocation("lightColor");

    uniformAmp   = normalShaderProgram.uniformLocation("amplitude");
    uniformFreq  = normalShaderProgram.uniformLocation("frequency");
    uniformPhase = normalShaderProgram.uniformLocation("amplitudephase");

    uniformTime = normalShaderProgram.uniformLocation("time");
}

void MainView::loadMesh(QString name) {
    Model model(name);
    model.unitize();
    QVector<float> meshData = model.getVNTInterleaved();

    meshSize = model.getVertices().size();

    // Generate VAO
    glGenVertexArrays(1, &meshVAO);
    glBindVertexArray(meshVAO);

    // Generate VBO
    glGenBuffers(1, &meshVBO);
    glBindBuffer(GL_ARRAY_BUFFER, meshVBO);

    // Write the data to the buffer
    glBufferData(GL_ARRAY_BUFFER, meshData.size() * sizeof(float), meshData.data(), GL_STATIC_DRAW);

    // Set vertex coordinates to location 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);

    // Set vertex normals to location 1
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Set vertex texture coordinates to location 2
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// --- OpenGL drawing

/**
 * @brief MainView::paintGL
 *
 * Actual function used for drawing to the screen
 *
 */
void MainView::paintGL() {
    // Clear the screen before rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Choose the selected shader.
    switch (currentShader) {
    case NORMAL:
        normalShaderProgram.bind();

        updateNormalUniforms();

        glBindVertexArray(meshVAO);
        glDrawArrays(GL_TRIANGLES, 0, meshSize);

        normalShaderProgram.release();
        break;
    case GOURAUD:
        qDebug() << "Gouraud shader program not implemented";
        break;
    case PHONG:
        phongShaderProgram.bind();

        updatePhongUniforms();

        glBindVertexArray(meshVAO);
        glDrawArrays(GL_TRIANGLES, 0, meshSize);

        phongShaderProgram.release();
        break;
    }
}

/**
 * @brief MainView::resizeGL
 *
 * Called upon resizing of the screen
 *
 * @param newWidth
 * @param newHeight
 */
void MainView::resizeGL(int newWidth, int newHeight) {
    Q_UNUSED(newWidth)
    Q_UNUSED(newHeight)
    updateProjectionTransform();
}

void MainView::updateNormalUniforms() {
    glUniformMatrix4fv(uniformProjectionTransformNormal, 1, GL_FALSE, projectionTransform.data());
    glUniformMatrix4fv(uniformModelViewTransformNormal, 1, GL_FALSE, meshTransform.data());
    glUniformMatrix3fv(uniformNormalTransformNormal, 1, GL_FALSE, meshNormalTransform.data());

    glUniform1fv(uniformAmp, NWAVES, amp);
    glUniform1fv(uniformFreq, NWAVES, freq);
    glUniform1fv(uniformPhase, NWAVES, phase);

    time += 1.0/60.0;
    glUniform1fv(uniformTime, 1, &time);
}

void MainView::updatePhongUniforms() {
    glUniformMatrix4fv(uniformProjectionTransformPhong, 1, GL_FALSE, projectionTransform.data());
    glUniformMatrix4fv(uniformModelViewTransformPhong, 1, GL_FALSE, meshTransform.data());
    glUniformMatrix3fv(uniformNormalTransformPhong, 1, GL_FALSE, meshNormalTransform.data());

    glUniform4f(uniformMaterialPhong, material[0], material[1], material[2], material[3]);
    glUniform3f(uniformMaterialColorPhong, materialColor[0], materialColor[1], materialColor[2]);
    glUniform3f(uniformLightPositionPhong, lightPosition[0], lightPosition[1], lightPosition[2]);
    glUniform3f(uniformLightColorPhong, lightColor.x(), lightColor.y(), lightColor.z());

    glUniform1fv(uniformAmp, NWAVES, amp);
    glUniform1fv(uniformFreq, NWAVES, freq);
    glUniform1fv(uniformPhase, NWAVES, phase);

    time += 1.0/60.0;
    glUniform1fv(uniformTime, 1, &time);
}

void MainView::updateProjectionTransform() {
    float aspectRatio = static_cast<float>(width()) / static_cast<float>(height());
    projectionTransform.setToIdentity();
    projectionTransform.perspective(60.0F, aspectRatio, 0.2F, 20.0F);
}

void MainView::updateModelTransforms() {
    meshTransform.setToIdentity();
    meshTransform.translate(0.0F, 0.0F, -4.0F);

    meshTransform.rotate(rotation.x(), {1.0F, 0.0F, 0.0F});
    meshTransform.rotate(rotation.y(), {0.0F, 1.0F, 0.0F});
    meshTransform.rotate(rotation.z(), {0.0F, 0.0F, 1.0F});

    meshTransform.scale(scale);

    meshNormalTransform = meshTransform.normalMatrix();

    update();
}

// --- OpenGL cleanup helpers

void MainView::destroyModelBuffers() {
    glDeleteBuffers(1, &meshVBO);
    glDeleteVertexArrays(1, &meshVAO);
    glDeleteBuffers(1, &meshVBO);
    glDeleteVertexArrays(1, &meshVAO);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    rotation = { static_cast<float>(rotateX),
                 static_cast<float>(rotateY),
                 static_cast<float>(rotateZ) };
    updateModelTransforms();
}

void MainView::setScale(int newScale) {
    scale = static_cast<float>(newScale) / 100.0F;
    updateModelTransforms();
}

void MainView::setShadingMode(ShadingMode shading) {
    qDebug() << "Changed shading to" << shading;
    currentShader = shading;
}

// --- Private helpers

/**
 * @brief MainView::onMessageLogged
 *
 * OpenGL logging function, do not change
 *
 * @param Message
 */
void MainView::onMessageLogged( QOpenGLDebugMessage Message ) {
    qDebug() << " → Log:" << Message;
}
