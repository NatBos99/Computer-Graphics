#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "model.h"

#include <QImage>
#include <QKeyEvent>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLDebugLogger>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QVector>
#include <QVector3D>

#include <memory>

#define NWAVES 4

class MainView : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

    QOpenGLDebugLogger debugLogger;
    QTimer timer; // Timer used for animation.

    QOpenGLShaderProgram phongShaderProgram;

    // Time
    GLint uniformTime;
    GLfloat time;

    // Waves
    GLint uniformAmp;
    GLint uniformFreq;
    GLint uniformPhase;

    GLfloat amp[NWAVES];
    GLfloat freq[NWAVES];
    GLfloat phase[NWAVES];

    // Uniforms for the Phong shader program.
    GLint uniformModelViewTransformPhong;
    GLint uniformProjectionTransformPhong;
    GLint uniformNormalTransformPhong;

    GLint uniformMaterialPhong;
    GLint uniformMaterialColorPhong;
    GLint uniformLightPositionPhong;
    GLint uniformLightColorPhong;

    QOpenGLShaderProgram normalShaderProgram;

    // Uniforms for the Normal shader program.
    GLint uniformModelViewTransformNormal;
    GLint uniformProjectionTransformNormal;
    GLint uniformNormalTransformNormal;

    GLint uniformMaterialNormal;
    GLint uniformLightPositionNormal;
    GLint uniformLightColorNormal;

    // Buffers
    GLuint meshVAO;
    GLuint meshVBO;
    GLuint meshSize;

    // Transforms
    float scale = 1.0F;
    QVector3D rotation;
    QMatrix4x4 projectionTransform;
    QMatrix3x3 meshNormalTransform;
    QMatrix4x4 meshTransform;

    // Phong model constants.
    QVector4D material = {0.5F, 0.5F, 0.5F, 5.0F};
    QVector3D materialColor = {0.137F, 0.537F, 0.855F}; // RGB Hex: #2389da
    QVector3D lightPosition = {0.0F, 100.0F, 0.0F};
    QVector3D lightColor = {1.0F, 1.0F, 1.0F};

public:
    enum ShadingMode : GLuint
    {
        PHONG = 0, NORMAL, GOURAUD
    };

    MainView(QWidget *parent = 0);
    ~MainView();

    // Functions for widget input events.
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
    void loadMesh(QString name);

    void destroyModelBuffers();

    void updateProjectionTransform();
    void updateModelTransforms();

    void updatePhongUniforms();
    void updateNormalUniforms();

    // Useful utility method to convert image to bytes.
    QVector<quint8> imageToBytes(QImage image);

    // The current shader to use.
    ShadingMode currentShader = PHONG;
};

#endif // MAINVIEW_H
