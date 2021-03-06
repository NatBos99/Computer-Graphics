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
#include <QMatrix4x4>
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
    void onMessageLogged(QOpenGLDebugMessage Message);

private:
    QOpenGLDebugLogger debugLogger;
    QTimer timer; // timer used for animation

    QOpenGLShaderProgram *shaderProgram;
    QOpenGLShaderProgram shaderProgramNormal;
    QOpenGLShaderProgram shaderProgramPhong;
    QOpenGLShaderProgram shaderProgramGouraud;
    GLint uniformModelViewTransform;
    GLint uniformProjectionTransform;
    GLint uniformNormalTransform;
    GLint uniformLightPosition;
    GLint uniformLightColor;
    GLint uniformLightIntensity;
    GLint uniformMaterial;
    GLint uniformSampler;

    int shadingMode;

    // Mesh values
    GLuint meshVAO;
    GLuint meshVBO;
    GLuint meshSize;
    GLuint texture;
    QMatrix4x4 meshTransform;

    // Transforms
    float scale = 1.f;
    QVector3D rotation;
    QMatrix4x4 projectionTransform;

    QMatrix3x3 normalTransform;

    // Light and Material
    QVector3D light;
    QVector3D lightColor;
    QVector3D lightIntensity;
    QVector3D material;

    void createNormalShaderProgram();
    void createPhongShaderProgram();
    void createGouraudShaderProgram();
    void setUniforms();
    void loadMesh();
    void loadTexture(QString file);

    void destroyModelBuffers();

    void updateProjectionTransform();
    void updateModelTransforms();
    void updateNormalTransform();
    QVector<quint8> imageToBytes(QImage image);
};

#endif // MAINVIEW_H
