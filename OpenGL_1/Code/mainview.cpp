#include "mainview.h"
#include "vertex.h"

#include <QDateTime>
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
    modelCube = new QMatrix4x4();
    modelPyramid = new QMatrix4x4();
    modelSphere = new QMatrix4x4();

    modelCube->translate(2, 0, -6);
    modelPyramid->translate(-2, 0, -6);
    modelSphere->translate(0, 0, -10);

    projection = new QMatrix4x4();
    projection->perspective(60.0f, 1.5f, 0.1f, 10.0f);

    cubeScaling = new QMatrix4x4();
    pyramidScaling = new QMatrix4x4();
    sphereScaling = new QMatrix4x4();

    cubeRotation = new QMatrix4x4();
    pyramidRotation = new QMatrix4x4();
    sphereRotation = new QMatrix4x4();

    Model s(":/models/sphere.obj");
    s.unitize();
    sphere = s.getVertices();
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
    glDeleteVertexArrays(1, &vaoCube);
    glDeleteBuffers(1, &vboCube);
    glDeleteVertexArrays(1, &vaoPyramid);
    glDeleteBuffers(1, &vboPyramid);
    glDeleteVertexArrays(1, &vaoSphere);
    glDeleteBuffers(1, &vboSphere);
    delete projection;
    delete modelCube;
    delete modelPyramid;
    delete modelSphere;
    delete cubeScaling;
    delete pyramidScaling;
    delete sphereScaling;
    delete cubeRotation;
    delete pyramidRotation;
    delete sphereRotation;
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

    connect(&debugLogger, SIGNAL( messageLogged( QOpenGLDebugMessage)),
            this, SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (debugLogger.initialize()) {
        qDebug() << ":: Logging initialized";
        debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
    }

    QString glVersion;
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable backface culling
    glEnable(GL_CULL_FACE);

    // Default is GL_LESS
    glDepthFunc(GL_LEQUAL);

    // Set the color to be used by glClear. This is, effectively, the background color.
    glClearColor(0.2f, 0.5f, 0.7f, 0.0f);

    Vertex v1 = makeVertex(-1.0, 1.0, 1.0, 1.0, 0.0, 0.0);
    Vertex v2 = makeVertex(-1.0, -1.0, 1.0, 0.0, 1.0, 0.0);
    Vertex v3 = makeVertex(1.0, -1.0, 1.0, 0.0, 0.0, 1.0);
    Vertex v4 = makeVertex(1.0, 1.0, 1.0, 1.0, 0.0, 0.0);
    Vertex v5 = makeVertex(-1.0, 1.0, -1.0, 1.0, 0.0, 0.0);
    Vertex v6 = makeVertex(-1.0, -1.0, -1.0, 0.0, 1.0, 0.0);
    Vertex v7 = makeVertex(1.0, -1.0, -1.0, 0.0, 0.0, 1.0);
    Vertex v8 = makeVertex(1.0, 1.0, -1.0, 1.0, 0.0, 0.0);
    Vertex v9 = makeVertex(0.0, 1.0, 0.0, 1.0, 0.0, 0.0);

    Vertex cube[36] = {v1, v2, v3,
                       v3, v4, v1,
                       v1, v4, v5,
                       v4, v8, v5,
                       v1, v5, v6,
                       v1, v6, v2,
                       v2, v6, v7,
                       v2, v7, v3,
                       v4, v3, v7,
                       v4, v7, v8,
                       v5, v8, v7,
                       v5, v7, v6};

    Vertex pyramid[18] = {v2, v6, v7,
                          v2, v7, v3,
                          v9, v2, v3,
                          v9, v3, v7,
                          v9, v7, v6,
                          v9, v6, v2};

    sphereSize = sphere.size();
    Vertex sphereVertices[sphereSize];
    float sphereScale = 1; //0.04 if not using unitize

    for (int i = 0; i < sphereSize; i++) {
        sphereVertices[i] = makeVertex((sphere.at(i)).operator[](0)*sphereScale, (sphere.at(i)).operator[](1)*sphereScale, (sphere.at(i)).operator[](2)*sphereScale, (float) (i % 3 == 0), (float) (i % 3 == 1), (float) (i % 3 == 2));
    }

    glGenBuffers(1, &vboCube);
    glGenVertexArrays(1, &vaoCube);
    glBindVertexArray(vaoCube);
    glBindBuffer(GL_ARRAY_BUFFER, vboCube);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*36, cube, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    glGenBuffers(1, &vboPyramid);
    glGenVertexArrays(1, &vaoPyramid);
    glBindVertexArray(vaoPyramid);
    glBindBuffer(GL_ARRAY_BUFFER, vboPyramid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*18, pyramid, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    glGenBuffers(1, &vboSphere);
    glGenVertexArrays(1, &vaoSphere);
    glBindVertexArray(vaoSphere);
    glBindBuffer(GL_ARRAY_BUFFER, vboSphere);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*sphereSize, sphereVertices, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    createShaderProgram();
}

void MainView::createShaderProgram() {
    // Create shader program
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader.glsl");
    shaderProgram.link();

    modelTransformLoc = shaderProgram.uniformLocation("modelTransform");
    projectionTransformLoc = shaderProgram.uniformLocation("projectionTransform");
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

    shaderProgram.bind();

    glUniformMatrix4fv(projectionTransformLoc, 1, GL_FALSE, projection->data());

    // Draw here
    glBindVertexArray(vaoCube);
    QMatrix4x4 transformedCube = (*modelCube * *cubeRotation * *cubeScaling);
    glUniformMatrix4fv(modelTransformLoc, 1, GL_FALSE, transformedCube.data());
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(vaoPyramid);
    QMatrix4x4 transformedPyramid = (*modelPyramid * *pyramidRotation * *pyramidScaling);
    glUniformMatrix4fv(modelTransformLoc, 1, GL_FALSE, transformedPyramid.data());
    glDrawArrays(GL_TRIANGLES, 0, 18);

    glBindVertexArray(vaoSphere);
    QMatrix4x4 transformedSphere = (*modelSphere * *sphereRotation * *sphereScaling);
    glUniformMatrix4fv(modelTransformLoc, 1, GL_FALSE, transformedSphere.data());
    glDrawArrays(GL_TRIANGLES, 0, sphereSize);

    shaderProgram.release();
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
    // TODO: Update projection to fit the new aspect ratio
    delete projection;
    projection = new QMatrix4x4();
    projection->perspective(60.0f, (float)newWidth/(float)newHeight, 0.1f, 10.0f);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << "," << rotateZ << ")";
    delete cubeRotation;
    cubeRotation = new QMatrix4x4();
    cubeRotation->rotate(rotateX, 1, 0, 0);
    cubeRotation->rotate(rotateY, 0, 1, 0);
    cubeRotation->rotate(rotateZ, 0, 0, 1);

    delete pyramidRotation;
    pyramidRotation = new QMatrix4x4();
    pyramidRotation->rotate(rotateX, 1, 0, 0);
    pyramidRotation->rotate(rotateY, 0, 1, 0);
    pyramidRotation->rotate(rotateZ, 0, 0, 1);

    delete sphereRotation;
    sphereRotation = new QMatrix4x4();
    sphereRotation->rotate(rotateX, 1, 0, 0);
    sphereRotation->rotate(rotateY, 0, 1, 0);
    sphereRotation->rotate(rotateZ, 0, 0, 1);

    update();
}

void MainView::setScale(int scale) {
    qDebug() << "Scale changed to " << scale;
    delete cubeScaling;
    cubeScaling = new QMatrix4x4();
    cubeScaling->scale((float) scale / (float) 100);

    delete pyramidScaling;
    pyramidScaling = new QMatrix4x4();
    pyramidScaling->scale((float) scale / (float) 100);

    delete sphereScaling;
    sphereScaling = new QMatrix4x4();
    sphereScaling->scale((float) scale / (float) 100);

    update();
}

void MainView::setShadingMode(ShadingMode shading) {
    qDebug() << "Changed shading to" << shading;
    Q_UNIMPLEMENTED();
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
