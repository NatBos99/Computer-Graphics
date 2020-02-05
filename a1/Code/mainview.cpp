#include "mainview.h"
#include "vertex.h"

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
    Vertex v2 = makeVertex(-0.5, 0.0, 0.0, 1.0, 0.0);
    Vertex v3 = makeVertex(0.5, 0.0, 0.0, 0.0, 1.0);

    QVector<Vertex> vertexVector(3);
    vertexVector[0] = v1;
    vertexVector[1] = v2;
    vertexVector[2] = v3;
}

void MainView::resizeGL(int newWidth, int newHeight) {
    Q_UNUSED(newWidth)
    Q_UNUSED(newHeight)
}

void MainView::paintGL() {

}

void MainView::onMessageLogged(QOpenGLDebugMessage Message) {
    qDebug() << " → Log:" << Message;
}
