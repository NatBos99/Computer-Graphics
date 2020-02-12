#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "model.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLDebugLogger>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QVector3D>
#include <memory>

class MainView : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

    QOpenGLDebugLogger *debugLogger;
    QTimer timer; // timer used for animation

    QOpenGLShaderProgram shaderProgram;

public:
    enum ShadingMode : GLuint
    {
        PHONG = 0, NORMAL, GOURAUD
    };

    MainView(QWidget *parent = 0);
    ~MainView();

    // Functions for widget input events
    void setRotation(int rotateX, int rotateY, int rotateZ);
    void setScale(int scale);
    void setShadingMode(ShadingMode shading);

protected:
    void initializeGL();
    void resizeGL(int newWidth, int newHeight);
    void paintGL();

    // Functions for keyboard input events
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    // Function for mouse input events
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void wheelEvent(QWheelEvent *ev);

private slots:
    void onMessageLogged( QOpenGLDebugMessage Message );

private:
    void createShaderProgram();

    QMatrix4x4 *cubeBase;
    QMatrix4x4 *pyramidBase;
    QMatrix4x4 *sphereBase;

    QMatrix4x4 *cubeRotate;
    QMatrix4x4 *pyramidRotate;
    QMatrix4x4 *sphereRotate;

    QMatrix4x4 *cubeScale;
    QMatrix4x4 *pyramidScale;
    QMatrix4x4 *sphereScale;

    QMatrix4x4 *cubeTransform = new QMatrix4x4();
    QMatrix4x4 *pyramidTransform = new QMatrix4x4();
    QMatrix4x4 *sphereTransform = new QMatrix4x4();

    QMatrix4x4 *projectionTransform;

    GLint objectTransformLoc;
    GLint projectionTransformLoc;

    GLuint vaoCube;
    GLuint bufferCube;

    GLuint vaoPyramid;
    GLuint bufferPyramid;

    GLuint vaoSphere;
    GLuint bufferSphere;
    Model *sphere = new Model(":/models/sphere.obj");
    QVector<QVector3D> sphereVector = sphere->getVertices();

};

#endif // MAINVIEW_H
