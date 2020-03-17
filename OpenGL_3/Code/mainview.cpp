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
    for(int i=0; i<4; i++) {
        glDeleteTextures(1, &textureName[i]);
    }

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
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.2F, 0.5F, 0.7F, 0.0F);

    createShaderProgram();
    loadMesh(":/models/sphere.obj", 0);
    loadMesh(":/models/cat.obj", 1);
    loadMesh(":/models/sphere.obj", 2);
    loadMesh(":/models/cube.obj", 3);
    loadTextures();

    // Initialize Angles
    objectAxes[0] = {0.0F, 0.0F, 1.0F};
    objectAxes[1] = {0.0F, 0.0F, 1.0F};
    objectAxes[2] = {0.0F, 0.0F, 1.0F};
    objectAxes[3] = {0.0F, 0.0F, 1.0F};
    angle[0] = 1.0F;
    angle[1] = -1.0F;
    angle[2] = 0.0F;
    angle[3] = 0.0F;

    // Initialize transformations.
    updateProjectionTransform();
    initializeModelTransforms();
    //updateModelTransforms();

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
    uniformLightPositionPhong       = phongShaderProgram.uniformLocation("lightPosition");
    uniformLightColorPhong          = phongShaderProgram.uniformLocation("lightColor");
    uniformTextureSamplerPhong      = phongShaderProgram.uniformLocation("textureSampler");
}

void MainView::loadMesh(QString name, int i) {
    Model model(name);
    model.unitize();
    QVector<float> meshData = model.getVNTInterleaved();

    meshSize[i] = model.getVertices().size();

    // Generate VAO
    glGenVertexArrays(1, &meshVAO[i]);
    glBindVertexArray(meshVAO[i]);

    // Generate VBO
    glGenBuffers(1, &meshVBO[i]);
    glBindBuffer(GL_ARRAY_BUFFER, meshVBO[i]);

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

void MainView::loadTextures() {
    glGenTextures(1, &textureName[0]);
    loadTexture(":/textures/rug_logo.png", textureName[0]);

    glGenTextures(1, &textureName[1]);
    loadTexture(":/textures/cat_diff.png", textureName[1]);

    glGenTextures(1, &textureName[2]);
    loadTexture(":/textures/rug_logo.png", textureName[2]);

    glGenTextures(1, &textureName[3]);
    loadTexture(":/textures/rug_logo.png", textureName[3]);
}

void MainView::loadTexture(QString file, GLuint textureName) {
    // Set texture parameters.
    glBindTexture(GL_TEXTURE_2D, textureName);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Push image data to texture.
    QImage image(file);
    QVector<quint8> imageData = imageToBytes(image);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.width(), image.height(),
                 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());
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

    phongShaderProgram.bind();

    // Set the texture and draw the mesh.
    for(int i=0; i<4; i++) {
        // Choose the selected shader.
        switch (currentShader) {
        case NORMAL:
            qDebug() << "Normal shader program not implemented";
            break;
        case GOURAUD:
            qDebug() << "Gouraud shader program not implemented";
            break;
        case PHONG:
            updatePhongUniforms(i);
            break;
        }
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureName[i]);

        glBindVertexArray(meshVAO[i]);
        glDrawArrays(GL_TRIANGLES, 0, meshSize[i]);
    }
    phongShaderProgram.release();
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

void MainView::updatePhongUniforms(int i) {
    meshTransform[i].rotate(angle[i], objectAxes[i]);
    totalRotation[i] += angle[i]*objectAxes[i];

    time++;

    meshTransform[2].translate(-((int) (time % 100 - 50))/5000.0F, 0.0, 0.0F);
    totalTranslation[2].setX(totalTranslation[2].x() - ((int) (time % 100 - 50)/5000.0));
    meshTransform[3].translate(cos(2*time*PI / 1000.0)/100.0, sin(2*time*PI / 1000.0)/100.0, 0.0F);
    totalTranslation[3].setX(totalTranslation[3].x()+cos(2*time*PI / 1000.0)/100.0);
    totalTranslation[3].setY(totalTranslation[3].y()+sin(2*time*PI / 1000.0)/100.0);

    if (time == 1000) time = 0;

    meshNormalTransform[i] = meshTransform[i].normalMatrix();

    glUniformMatrix4fv(uniformProjectionTransformPhong, 1, GL_FALSE, projectionTransform.data());
    glUniformMatrix4fv(uniformModelViewTransformPhong, 1, GL_FALSE, meshTransform[i].data());
    glUniformMatrix3fv(uniformNormalTransformPhong, 1, GL_FALSE, meshNormalTransform[i].data());
    glUniform4f(uniformMaterialPhong, material[0], material[1], material[2], material[3]);
    glUniform3f(uniformLightPositionPhong, lightPosition[0], lightPosition[1], lightPosition[2]);
    glUniform3f(uniformLightColorPhong, lightColor.x(), lightColor.y(), lightColor.z());

    glUniform1i(uniformTextureSamplerPhong, 0);
}

void MainView::updateProjectionTransform() {
    float aspectRatio = static_cast<float>(width()) / static_cast<float>(height());
    projectionTransform.setToIdentity();
    projectionTransform.perspective(60.0F, aspectRatio, 0.2F, 20.0F);
}

void MainView::initializeModelTransforms() {
    meshTransform[0].translate(-2.0F, -1.0F, -4.0F);
    meshTransform[1].translate(2.0F, -1.0F, -4.0F);
    meshTransform[2].translate(-2.0F, 1.0F, -4.0F);
    meshTransform[3].translate(2.0F, 1.0F, -4.0F);
    positions[0] = {-2.0F, -1.0F, -4.0F};
    positions[1] = {2.0F, -1.0F, -4.0F};
    positions[2] = {-2.0F, 1.0F, -4.0F};
    positions[3] = {2.0F, 1.0F, -4.0F};
    updateModelTransforms();
}

void MainView::updateModelTransforms() {
    QMatrix4x4 rotations;
    rotations.rotate(rotation.x(), {1.0, 0.0, 0.0});
    rotations.rotate(rotation.y(), {0.0, 1.0, 0.0});
    rotations.rotate(rotation.z(), {0.0, 0.0, 1.0});

    for(int i=0; i<4; i++) {
        positions[i] += movement;
        QVector3D newPos = {positions[i].x(), positions[i].y(), positions[i].z()+(8+scale-3)};
        QVector3D vPrime = rotations * newPos;
        vPrime.setZ(vPrime.z()-(8+scale-3));
        meshTransform[i].setToIdentity();
        meshTransform[i].translate(vPrime+totalTranslation[i]);
        totalTranslation[i] = {0.0F, 0.0F, 0.0F};
        meshTransform[i].translate({0, 0, scale-3});
        QVector3D rotationVec = rotation + totalRotation[i];
        totalRotation[i] = {0.0F, 0.0F, 0.0F};
        meshTransform[i].rotate(rotationVec.x(), {1.0, 0.0, 0.0});
        meshTransform[i].rotate(rotationVec.y(), {0.0, 1.0, 0.0});
        meshTransform[i].rotate(rotationVec.z(), {0.0, 0.0, 1.0});
    }

    movement = {0.0F, 0.0F, 0.0F};

    update();
}

// --- OpenGL cleanup helpers

void MainView::destroyModelBuffers() {
    for(int i=0; i<4; i++) {
        glDeleteBuffers(1, &meshVBO[i]);
        glDeleteVertexArrays(1, &meshVAO[i]);
    }
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
