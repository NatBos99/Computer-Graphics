#include "mainview.h"
#include "model.h"
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

    // Set the lights, light color, material, and light intensity
    light.setX(-10);
    light.setY(10);
    light.setZ(0);
    lightColor.setX(1);
    lightColor.setY(1);
    lightColor.setZ(1);
    material.setX(0.2);
    material.setY(0.9);
    material.setZ(0.9);
    lightIntensity.setX(1);
    lightIntensity.setY(1);
    lightIntensity.setZ(1);

    createNormalShaderProgram();
    createPhongShaderProgram();
    createGouraudShaderProgram();
    setShadingMode(PHONG);
    loadMesh();

    // Initialize transformations
    updateProjectionTransform();
    updateModelTransforms();
    updateNormalTransform();
}

void MainView::createNormalShaderProgram() {
    // Create shader program
    std::cout << "Normal shading" << std::endl;
    shaderProgramNormal.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_normal.glsl");
    shaderProgramNormal.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_normal.glsl");
    shaderProgramNormal.link();
}

void MainView::createPhongShaderProgram() {
    // Create shader program
    std::cout << "Phong shading" << std::endl;
    shaderProgramPhong.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_phong.glsl");
    shaderProgramPhong.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_phong.glsl");
    shaderProgramPhong.link();
}

void MainView::createGouraudShaderProgram() {
    // Create shader program
    std::cout << "Gouraud shading" << std::endl;
    shaderProgramGouraud.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_gouraud.glsl");
    shaderProgramGouraud.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_gouraud.glsl");
    shaderProgramGouraud.link();
}

void MainView::setUniforms() {
    // Get the uniforms
    uniformModelViewTransform = shaderProgram->uniformLocation("modelViewTransform");
    uniformProjectionTransform = shaderProgram->uniformLocation("projectionTransform");
    uniformNormalTransform = shaderProgram->uniformLocation("normalTransform");
}

void MainView::loadMesh() {
    Model model(":/models/cat.obj");

    QVector<QVector3D> vertexCoords = model.getVertices();
    QVector<QVector3D> normalCoords = model.getNormals();
    QVector<QVector2D> texCoords = model.getTextureCoords();

    QVector<float> meshData;
    meshData.reserve((3 * 3 + 2) * vertexCoords.size());

    // Implemented as an easy way to load in objects in the right place
    int baseScale = 10;
    QVector3D baseTranslation(0,-3,0);

    int i = 0;

    for (auto coord : vertexCoords)
    {
        meshData.append((coord.x()*baseScale)+baseTranslation.x());
        meshData.append((coord.y()*baseScale)+baseTranslation.y());
        meshData.append((coord.z()*baseScale)+baseTranslation.z());
        meshData.append(static_cast<float>(rand()) / RAND_MAX);
        meshData.append(static_cast<float>(rand()) / RAND_MAX);
        meshData.append(static_cast<float>(rand()) / RAND_MAX);
        meshData.append(normalCoords[i].x());
        meshData.append(normalCoords[i].y());
        meshData.append(normalCoords[i].z());
        meshData.append(texCoords[i].x());
        meshData.append(texCoords[i].y());
        i++;
    }

    meshSize = vertexCoords.size();

    // Generate VAO
    glGenVertexArrays(1, &meshVAO);
    glBindVertexArray(meshVAO);

    // Generate VBO
    glGenBuffers(1, &meshVBO);
    glBindBuffer(GL_ARRAY_BUFFER, meshVBO);

    // Write the data to the buffer
    glBufferData(GL_ARRAY_BUFFER, meshData.size() * sizeof(float), meshData.data(), GL_STATIC_DRAW);

    // Set vertex coordinates to location 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // Set colour coordinates to location 1
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Set normal coordinates to location 2
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Set texture coordinates to location 3
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(9 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    loadTexture(":/textures/cat_diff.png");
}

void MainView::loadTexture(QString file) {
    QImage image(file);
    QVector<quint8> loadedImage = imageToBytes(image);
    GLsizei imWidth = image.width(), imHeight = image.height();
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imWidth, imHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, loadedImage.data());
    glGenerateMipmap(GL_TEXTURE_2D);                     // Use this if mipmapping
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

    shaderProgram->bind();
    // glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set the projection matrix
    glUniformMatrix4fv(uniformProjectionTransform, 1, GL_FALSE, projectionTransform.data());
    glUniformMatrix4fv(uniformModelViewTransform, 1, GL_FALSE, meshTransform.data());
    glUniformMatrix3fv(uniformNormalTransform, 1, GL_FALSE, normalTransform.data());

    if (shadingMode==PHONG||shadingMode==GOURAUD) {
        glUniform3f(uniformLightPosition, light.x(), light.y(), light.z());
        glUniform3f(uniformLightColor, lightColor.x(), lightColor.y(), lightColor.z());
        glUniform3f(uniformLightIntensity, lightIntensity.x(), lightIntensity.y(), lightIntensity.z());
        glUniform3f(uniformMaterial, material.x(), material.y(), material.z());
        glUniform1i(uniformSampler, 0);
    }

    glBindVertexArray(meshVAO);
    glDrawArrays(GL_TRIANGLES, 0, meshSize);

    shaderProgram->release();
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

void MainView::updateProjectionTransform() {
    float aspect_ratio = static_cast<float>(width()) / static_cast<float>(height());
    projectionTransform.setToIdentity();
    projectionTransform.perspective(60, aspect_ratio, 0.2, 20);
}

void MainView::updateModelTransforms() {
    meshTransform.setToIdentity();
    meshTransform.translate(0, 0, -10);
    meshTransform.scale(scale);
    meshTransform.rotate(QQuaternion::fromEulerAngles(rotation));

    updateNormalTransform();

    update();
}

void MainView::updateNormalTransform() {
    normalTransform = meshTransform.normalMatrix();
}

// --- OpenGL cleanup helpers

void MainView::destroyModelBuffers() {
    glDeleteBuffers(1, &meshVBO);
    glDeleteVertexArrays(1, &meshVAO);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    rotation = { static_cast<float>(rotateX), static_cast<float>(rotateY), static_cast<float>(rotateZ) };
    updateModelTransforms();
}

void MainView::setScale(int newScale) {
    scale = static_cast<float>(newScale) / 100.f;
    updateModelTransforms();
}

void MainView::setShadingMode(ShadingMode shading) {
    switch (shading) {
        case PHONG:
            shaderProgram = &shaderProgramPhong;
            uniformLightPosition = shaderProgram->uniformLocation("light");
            uniformLightColor = shaderProgram->uniformLocation("lightColor");
            uniformLightIntensity = shaderProgram->uniformLocation("lightIntensity");
            uniformMaterial = shaderProgram->uniformLocation("material");
            uniformSampler = shaderProgram->uniformLocation("tex");
            break;
        case NORMAL:
            shaderProgram = &shaderProgramNormal;
            break;
        default: // Gouraud
            shaderProgram = &shaderProgramGouraud;
            uniformLightPosition = shaderProgram->uniformLocation("light");
            uniformLightColor = shaderProgram->uniformLocation("lightColor");
            uniformLightIntensity = shaderProgram->uniformLocation("lightIntensity");
            uniformMaterial = shaderProgram->uniformLocation("material");
            uniformSampler = shaderProgram->uniformLocation("tex");
    }
    shadingMode = shading;
    setUniforms();
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

