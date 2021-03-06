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

public:
    enum ShadingMode : GLuint {
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
    QOpenGLDebugLogger debugLogger;
    QTimer timer; // timer used for animation

    QOpenGLShaderProgram shaderProgram;
    GLuint vboCube;
    GLuint vaoCube;
    GLuint vboPyramid;
    GLuint vaoPyramid;
    GLuint vboSphere;
    GLuint vaoSphere;

    int sphereSize;

    QMatrix4x4 *modelCube;
    QMatrix4x4 *modelPyramid;
    QMatrix4x4 *modelSphere;

    QMatrix4x4 *projection;

    QMatrix4x4 *cubeScaling;
    QMatrix4x4 *pyramidScaling;
    QMatrix4x4 *sphereScaling;

    QMatrix4x4 *cubeRotation;
    QMatrix4x4 *pyramidRotation;
    QMatrix4x4 *sphereRotation;

    GLint modelTransformLoc;
    GLint projectionTransformLoc;

    QVector<QVector3D> sphere;

    bool mousePressed = false;
    int initX;
    int initY;

    void createShaderProgram();
};

#endif // MAINVIEW_H
