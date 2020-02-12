#include "mainview.h"
#include "vertex.h"
#include "iostream"

MainView::MainView(QWidget *parent) : QOpenGLWidget(parent) {
    qDebug() << "MainView constructor";
}

MainView::~MainView() {
    qDebug() << "MainView destructor";

    makeCurrent();
}

void MainView::initializeGL() {
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    connect(&debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)),
            this, SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (debugLogger.initialize()) {
        qDebug() << ":: Logging initialized";
        debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
    }

    QString glVersion;
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    Vertex v1 = makeVertex(0.0, 0.5, 1.0, 0.0, 0.0);
    Vertex v2 = makeVertex(0.5, 0.0, 0.0, 0.0, 1.0);
    Vertex v3 = makeVertex(-0.5, 0.0, 0.0, 1.0, 0.0);

    Vertex vertexVector[3] = {v1, v2, v3};

    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    shaders.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vertshader.glsl");
    shaders.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fragshader.glsl");
    shaders.link();
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*3, vertexVector, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(2 * sizeof(GLfloat)));
}

void MainView::resizeGL(int newWidth, int newHeight) {
    Q_UNUSED(newWidth)
    Q_UNUSED(newHeight)
}

void MainView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(vao);
    shaders.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MainView::onMessageLogged(QOpenGLDebugMessage Message) {
    qDebug() << " → Log:" << Message;
}
