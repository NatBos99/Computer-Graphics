#include "mainview.h"
#include "math.h"
#include "vertex.h"

#include <QDateTime>
#include <iostream> //debug

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
    // The base matrices are used to calculate a new rotation/scale
    cubeBase = new QMatrix4x4();
    pyramidBase = new QMatrix4x4();
    sphereBase = new QMatrix4x4();

    cubeBase->translate(2, 0, -6);
    pyramidBase->translate(-2, 0, -6);
    sphereBase->translate(0, 0, -10);

    cubeRotate = new QMatrix4x4();
    pyramidRotate = new QMatrix4x4();
    sphereRotate = new QMatrix4x4();

    cubeScale = new QMatrix4x4();
    pyramidScale = new QMatrix4x4();
    sphereScale = new QMatrix4x4();

    projectionTransform = new QMatrix4x4();
    projectionTransform->perspective(60.0f, 1.459f, 0.1f, 10.0f);
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
    glDeleteBuffers(1, &bufferCube);
    glDeleteVertexArrays(1, &vaoCube);
    glDeleteBuffers(1, &bufferPyramid);
    glDeleteVertexArrays(1, &vaoPyramid);
    glDeleteBuffers(1, &bufferSphere);
    glDeleteVertexArrays(1, &vaoSphere);

    debugLogger->stopLogging();

    qDebug() << "MainView destructor";
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

    debugLogger = new QOpenGLDebugLogger();
    connect( debugLogger, SIGNAL( messageLogged( QOpenGLDebugMessage ) ),
             this, SLOT( onMessageLogged( QOpenGLDebugMessage ) ), Qt::DirectConnection );

    if ( debugLogger->initialize() ) {
        qDebug() << ":: Logging initialized";
        debugLogger->startLogging( QOpenGLDebugLogger::SynchronousLogging );
        debugLogger->enableMessages();
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

    // Create cube vertices data
    vertex cubeVertices[36];

    cubeVertices[0] = makeVertex(-1.0f,-1.0f,-1.0f, 1, 0, 0);
    cubeVertices[1] = makeVertex(-1.0f,-1.0f, 1.0f, 0, 1, 0);
    cubeVertices[2] = makeVertex(-1.0f, 1.0f, 1.0f, 0, 0, 1);

    cubeVertices[3] = makeVertex(1.0f, 1.0f,-1.0f, 1, 0, 0);
    cubeVertices[4] = makeVertex(-1.0f,-1.0f,-1.0f, 0, 1, 0);
    cubeVertices[5] = makeVertex(-1.0f, 1.0f,-1.0f, 0, 0, 1);

    cubeVertices[6] = makeVertex(1.0f,-1.0f, 1.0f, 1, 0, 0);
    cubeVertices[7] = makeVertex(-1.0f,-1.0f,-1.0f, 0, 1, 0);
    cubeVertices[8] = makeVertex(1.0f,-1.0f,-1.0f, 0, 0, 1);

    cubeVertices[9] = makeVertex(1.0f, 1.0f,-1.0f, 1, 0, 0);
    cubeVertices[10] = makeVertex(1.0f,-1.0f,-1.0f, 0, 1, 0);
    cubeVertices[11] = makeVertex(-1.0f,-1.0f,-1.0f, 0, 0, 1);

    cubeVertices[12] = makeVertex(-1.0f,-1.0f,-1.0f, 1, 0, 0);
    cubeVertices[13] = makeVertex(-1.0f, 1.0f, 1.0f, 0, 1, 0);
    cubeVertices[14] = makeVertex(-1.0f, 1.0f,-1.0f, 0, 0, 1);

    cubeVertices[15] = makeVertex(1.0f,-1.0f, 1.0f, 1, 0, 0);
    cubeVertices[16] = makeVertex(-1.0f,-1.0f, 1.0f, 0, 1, 0);
    cubeVertices[17] = makeVertex(-1.0f,-1.0f,-1.0f, 0, 0, 1);

    cubeVertices[18] = makeVertex(-1.0f, 1.0f, 1.0f, 1, 0, 0);
    cubeVertices[19] = makeVertex(-1.0f,-1.0f, 1.0f, 0, 1, 0);
    cubeVertices[20] = makeVertex(1.0f,-1.0f, 1.0f, 0, 0, 1);

    cubeVertices[21] = makeVertex(1.0f, 1.0f, 1.0f, 1, 0, 0);
    cubeVertices[22] = makeVertex(1.0f,-1.0f,-1.0f, 0, 1, 0);
    cubeVertices[23] = makeVertex(1.0f, 1.0f,-1.0f, 0, 0, 1);

    cubeVertices[24] = makeVertex(1.0f,-1.0f,-1.0f, 1, 0, 0);
    cubeVertices[25] = makeVertex(1.0f, 1.0f, 1.0f, 0, 1, 0);
    cubeVertices[26] = makeVertex(1.0f,-1.0f, 1.0f, 0, 0, 1);

    cubeVertices[27] = makeVertex(1.0f, 1.0f, 1.0f, 1, 0, 0);
    cubeVertices[28] = makeVertex(1.0f, 1.0f,-1.0f, 0, 1, 0);
    cubeVertices[29] = makeVertex(-1.0f, 1.0f,-1.0f, 0, 0, 1);

    cubeVertices[30] = makeVertex(1.0f, 1.0f, 1.0f, 1, 0, 0);
    cubeVertices[31] = makeVertex(-1.0f, 1.0f,-1.0f, 0, 1, 0);
    cubeVertices[32] = makeVertex(-1.0f, 1.0f, 1.0f, 0, 0, 1);

    cubeVertices[33] = makeVertex(1.0f, 1.0f, 1.0f, 1, 0, 0);
    cubeVertices[34] = makeVertex(-1.0f, 1.0f, 1.0f, 0, 1, 0);
    cubeVertices[35] = makeVertex(1.0f,-1.0f, 1.0f, 0, 0, 1);

    // Create pyramid vertices data
    vertex pyramidVertices[18];

    pyramidVertices[0] = makeVertex(-1, -1, 1, 1, 0, 0);
    pyramidVertices[1] = makeVertex(1, -1, -1, 1, 0, 0);
    pyramidVertices[2] = makeVertex(1, -1, 1, 0, 1, 0);

    pyramidVertices[3] = makeVertex(-1, -1, 1, 1, 0, 0);
    pyramidVertices[4] = makeVertex(-1, -1, -1, 0, 1, 0);
    pyramidVertices[5] = makeVertex(1, -1, -1, 1, 0, 0);

    pyramidVertices[6] = makeVertex(-1, -1, 1, 1, 0, 0);
    pyramidVertices[7] = makeVertex(1, -1, 1, 0, 1, 0);
    pyramidVertices[8] = makeVertex(0, 1, 0, 0, 0, 1);

    pyramidVertices[9] = makeVertex(1, -1, 1, 0, 1, 0);
    pyramidVertices[10] = makeVertex(1, -1, -1, 1, 0, 0);
    pyramidVertices[11] = makeVertex(0, 1, 0, 0, 0, 1);

    pyramidVertices[12] = makeVertex(1, -1, -1, 1, 0, 0);
    pyramidVertices[13] = makeVertex(-1, -1, -1, 0, 1, 0);
    pyramidVertices[14] = makeVertex(0, 1, 0, 0, 0, 1);

    pyramidVertices[15] = makeVertex(-1, -1, -1, 0, 1, 0);
    pyramidVertices[16] = makeVertex(-1, -1, 1, 1, 0, 0);
    pyramidVertices[17] = makeVertex(0, 1, 0, 0, 0, 1);


    //Create array of sphere vertices
    int sphereSize = sphereVector.size();
    vertex *sphereVertices = new vertex[sphereSize];

    //Assign every vertex the value of the model vertices, and random r, g, b values.
    srand (static_cast <unsigned> (time(0)));
    for (int i = 0; i < sphereSize; i++) {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        sphereVertices[i] = makeVertex((sphereVector.at(i)).operator[](0)*0.04, (sphereVector.at(i)).operator[](1)*0.04, (sphereVector.at(i)).operator[](2)*0.04, r, g, b);
    }


    // Set the color of the screen to be black on clear (new frame)
    glClearColor(0.2f, 0.5f, 0.7f, 0.0f);

    createShaderProgram();

    // Create & configure cube buffers
    glGenVertexArrays(1, &vaoCube);
    glGenBuffers(1, &bufferCube);

    glBindVertexArray(vaoCube);
    glBindBuffer(GL_ARRAY_BUFFER, bufferCube);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 36, cubeVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    // Create & configure pyramid buffers
    glGenVertexArrays(1, &vaoPyramid);
    glGenBuffers(1, &bufferPyramid);

    glBindVertexArray(vaoPyramid);
    glBindBuffer(GL_ARRAY_BUFFER, bufferPyramid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 18, pyramidVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    //Create & configure sphere buffers
    glGenVertexArrays(1, &vaoSphere);
    glGenBuffers(1, &bufferSphere);

    glBindVertexArray(vaoSphere);
    glBindBuffer(GL_ARRAY_BUFFER, bufferSphere);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * sphereSize, sphereVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(3 * sizeof(GLfloat)));

}

void MainView::createShaderProgram()
{
    // Create shader program
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader.glsl");
    shaderProgram.link();

    objectTransformLoc = shaderProgram.uniformLocation("objectTransform");
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
    //Do the perspective transform
    glUniformMatrix4fv(projectionTransformLoc, 1, GL_FALSE, projectionTransform->data());


    // Draw here
    //Rotate and scale cube, then draw
    glBindVertexArray(vaoCube);
    for (int i = 0; i < 16; i++) {
        cubeTransform->data()[i] = cubeBase->data()[i];
    }
    *cubeTransform *= *cubeRotate;
    *cubeTransform *= *cubeScale;

    glUniformMatrix4fv(objectTransformLoc, 1, GL_FALSE, cubeTransform->data());
    glDrawArrays(GL_TRIANGLES, 0, 36);

    //Rotate and scale pyramid, then draw
    glBindVertexArray(vaoPyramid);

    for (int i = 0; i < 16; i++) {
        pyramidTransform->data()[i] = pyramidBase->data()[i];
    }
    *pyramidTransform *= *pyramidRotate;
    *pyramidTransform *= *pyramidScale;

    glUniformMatrix4fv(objectTransformLoc, 1, GL_FALSE, pyramidTransform->data());
    glDrawArrays(GL_TRIANGLES, 0, 18);

    //Rotate and scale sphere, then draw
    glBindVertexArray(vaoSphere);

    for (int i = 0; i < 16; i++) {
        sphereTransform->data()[i] = sphereBase->data()[i];
    }
    *sphereTransform *= *sphereRotate;
    *sphereTransform *= *sphereScale;

    glUniformMatrix4fv(objectTransformLoc, 1, GL_FALSE, sphereTransform->data());
    glDrawArrays(GL_TRIANGLES, 0, sphereVector.size());

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
void MainView::resizeGL(int newWidth, int newHeight) 
{
    projectionTransform = new QMatrix4x4();
    projectionTransform->perspective(60.0f, (float)newWidth/(float)newHeight, 1.0f, 10.0f);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ)
{
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << "," << rotateZ << ")";

    cubeRotate = new QMatrix4x4();
    cubeRotate->rotate(rotateX, 1, 0, 0);
    cubeRotate->rotate(rotateY, 0, 1, 0);
    cubeRotate->rotate(rotateZ, 0, 0, 1);

    pyramidRotate = new QMatrix4x4();
    pyramidRotate->rotate(rotateX, 1, 0, 0);
    pyramidRotate->rotate(rotateY, 0, 1, 0);
    pyramidRotate->rotate(rotateZ, 0, 0, 1);

    sphereRotate = new QMatrix4x4();
    sphereRotate->rotate(rotateX, 1, 0, 0);
    sphereRotate->rotate(rotateY, 0, 1, 0);
    sphereRotate->rotate(rotateZ, 0, 0, 1);

    update();
}

void MainView::setScale(int scale)
{
    qDebug() << "Scale changed to " << scale;

    cubeScale = new QMatrix4x4();
    cubeScale->scale((float)scale/float(100));

    pyramidScale = new QMatrix4x4();
    pyramidScale->scale((float)scale/float(100));

    sphereScale = new QMatrix4x4();
    sphereScale->scale(((float)scale/float(100)));

    update();
}

void MainView::setShadingMode(ShadingMode shading)
{
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
