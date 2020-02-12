#include "mainview.h"
#include "vertex.h"

#include <QDateTime>

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

    modelCube->translate(2, 0, -6);
    modelPyramid->translate(-2, 0, -6);

//    modelCube = new QMatrix4x4(1,  0,  0,  2,
//                               0,  1,  0,  0,
//                               0,  0,  1, -6,
//                               0,  0,  0,  1);
//    modelPyramid = new QMatrix4x4(1,  0,  0,  2,
//                                  0,  1,  0,  0,
//                                  0,  0,  1,  6,
//                                  0,  0,  0,  1);



//    double  n = 0.0,
//            f = 10.0,
//            l = 20.0,
//            r = 20.0,
//            t = 20.0,
//            b = 20.0;
//    projection = new QMatrix4x4(2 * n / (r - l),    0,                  (r + l) / (r - l),      0,
//                               0,                   2 * n / (t - b),    (t + b) / (t - b),      0,
//                               0,                   0,                  (n + f) / (n - f),     2 * f * n / (n - f),
//                               0,                   0,                  -1,                     0);
    projection = new QMatrix4x4();
    projection->perspective(60.0, 1.459f, 0.1f, 10.0f);
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

    delete modelCube;
    delete modelPyramid;
    delete projection;
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

    createShaderProgram();
}

void MainView::createShaderProgram() {
    // Create shader program
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader.glsl");
    shaderProgram.link();

    modelLoc = shaderProgram.uniformLocation("modelTransformation");
    projectionLoc = shaderProgram.uniformLocation("projectionTransformation");
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

    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection->data());

    // Draw here

    glBindVertexArray(vaoCube);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelCube->data());
    glDrawArrays(GL_TRIANGLES, 0, 36);


    glBindVertexArray(vaoPyramid);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelPyramid->data());
    glDrawArrays(GL_TRIANGLES, 0, 18);

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
    projection = new QMatrix4x4();
    projection->perspective(60.0f, (float)newWidth/(float)newHeight, 1.0f, 10.0f);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << "," << rotateZ << ")";
    Q_UNIMPLEMENTED();
}

void MainView::setScale(int scale) {
    qDebug() << "Scale changed to " << scale;
    Q_UNIMPLEMENTED();
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
