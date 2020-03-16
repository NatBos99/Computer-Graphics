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

#include <memory>

const double PI = 3.14159265359;

class MainView : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

    QOpenGLDebugLogger debugLogger;
    QTimer timer; // Timer used for animation.

    QOpenGLShaderProgram phongShaderProgram;

    // Uniforms for the Phong shader program.
    GLint uniformModelViewTransformPhong;
    GLint uniformProjectionTransformPhong;
    GLint uniformNormalTransformPhong;

    GLint uniformMaterialPhong;
    GLint uniformLightPositionPhong;
    GLint uniformLightColorPhong;

    GLint uniformTextureSamplerPhong;

    // Buffers
    GLuint meshVAO[4];
    GLuint meshVBO[4];
    GLuint meshSize[4];

    // Texture
    GLuint textureName[4];

    // Transforms
    float scale = 1.0F;
    float currentScale = 1.0F;
    int time = 0;
    QVector3D rotation;
    QVector3D objectAxes[4];
    float angle[4];
    QMatrix4x4 rotations[4];
    QVector3D positions[4];
    QMatrix4x4 projectionTransform;
    QMatrix3x3 meshNormalTransform[4];
    QMatrix4x4 meshTransform[4];

    // Phong model constants.
    QVector4D material = {0.5F, 0.5F, 0.5F, 5.0F};
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
    void loadMesh(QString name, int i);

    // Loads texture data into the buffer with the name textureName.
    void loadTextures();
    void loadTexture(QString file, GLuint texturePtr);

    void destroyModelBuffers();

    void updateProjectionTransform();
    void initializeModelTransforms();
    void updateModelTransforms();

    void updatePhongUniforms(int i);

    // Useful utility method to convert image to bytes.
    QVector<quint8> imageToBytes(QImage image);

    // The current shader to use.
    ShadingMode currentShader = PHONG;
};

#endif // MAINVIEW_H
