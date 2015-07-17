#include "glwidget.h"
#include "graphics/ObjMesh.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "graphics/materialobj.h"
#include "graphics/ShaderPrimitives/camera.h"
#include "math/quaternion.h"
#include "scene/scene.h"
static bool lbpressed = false;
static bool rbpressed = false;
#define SET_CAM 0
#define SET_OBJECT 1
static float last_x = 0.0;
static float last_y = 0.0;

static float savedCamera[9];
int type = 0;
const GLuint SHADOW_WIDTH = 2*1024, SHADOW_HEIGHT = 2*1024;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers),parent),
          m_camera( new Camera( this ) )
{
    setFocusPolicy(Qt::StrongFocus);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_STENCIL_FUNC);
    simTimer = new QTimer(this);
    connect(simTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    simTimer->start(0);

    // Initialize the camera position and orientation
    m_camera->setPosition( QVector3D( 5.0f, 5.0f, 5.0f ) );
    m_camera->setViewCenter( QVector3D( 0.0f, 0.0f, 0.0f ) );
    m_camera->setUpVector( QVector3D( 0.0f, 1.0f, 0.0f ) );

    QGLFormat glFormat;
    glFormat.setVersion( 3, 3 );
    glFormat.setProfile( QGLFormat::CoreProfile ); // Requires >=Qt-4.8.0
    glFormat.setSampleBuffers( true );
    glFormat.setSamples(16);

    this->setFormat(glFormat);

    scene = new Scene(this);
    scene->setCamera(m_camera);
    withshadow = true;
}

void GLWidget::initializeGL()
{
    // Enable depth testing
    glEnable( GL_DEPTH_TEST );

    // Set the clear color to white
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    scene->initializeShaders();


    glGenFramebuffers(1, &depthMapFBO);

    glGenTextures(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
                 SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);


}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if(withshadow){

    glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
        glClear(GL_DEPTH_BUFFER_BIT);
        renderSceneShadow();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // 2. Render scene as normal
    glViewport(0, 0, winWidth, winHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    renderSceneWithShadow();

    }else{
        renderScene();
    }





}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    winWidth = w;
    winHeight = h;
    float aspect = static_cast<float>( w ) / static_cast<float>( h );
    m_camera->setPerspectiveProjection( 30.0f, aspect, 0.1, 10000.0f );
    scene->setWindow(w,h);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int y = event->pos().y();
    int x = event->pos().x();
    if (lbpressed && !rbpressed) {
        m_camera->rotatex(y,last_y);
        m_camera->rotatey(x,last_x);
    }
    if (!lbpressed && rbpressed) {
        m_camera->translatex(x,last_x);
        m_camera->translatey(y,last_y);
    }
    if (lbpressed && rbpressed) {
        m_camera->zoom(y,last_y);
    }

    last_x = x;
    last_y = y;
    //printf("Moveddd...\n");
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    int y = event->pos().y();
    int x = event->pos().x();
    if (event->button() & Qt::LeftButton) {
        // when the button is pressed
        lbpressed = false;
    }
    // if the left button is pressed
    if (event->button() & Qt::RightButton) {
        // when the button is pressed
        rbpressed = false;
    }
    last_x = x;
    last_y = y;
    update();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    int y = event->pos().y();
    int x = event->pos().x();
    // if the left button is pressed
        if (event->button() & Qt::LeftButton) {
            // when the button is pressed
                lbpressed = true;
        }
        // if the left button is pressed
        if (event->button() & Qt::RightButton) {
            // when the button is pressed
                rbpressed = true;
        }

        last_x = x;
        last_y = y;

        update();

}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_O){
        withshadow = !withshadow;
        update();
    }
}

void GLWidget::renderScene()
{
    Matrix4x4 *transform = new Matrix4x4();
    MaterialObj* mate = new MaterialObj();
    mate->setMaterial(mate,MATERIAL_RUBY);
    //transform->scale(0.5,0.5,0.5);
    transform->setIdentity();
//    scene->drawCylinder(transform,mate);
//    transform->setIdentity();
//    transform->scale(2,1.0,1.5);
//    transform->translate(-2,1,0);
    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(0,1.5,0);
    mate->setMaterial(mate,MATERIAL_RUBY);
    scene->drawCube(transform,mate);


    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(2,0,1);
    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCube(transform,mate);

    transform->setIdentity();

    //transform->scale(0.5,0.5,0.5);
    //transform->setTranslate(Vec4(-1,0,2,1.0));

    transform->scale(0.5,0.5,0.5);
    transform->setRotationX(60);
    transform->setRotationZ(60);
    transform->setTranslate(Vec4(-1,0,2,1.0));

    //transform->setRotationX(60);
    //transform->setRotationZ(60);

    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCube(transform,mate);


//    mate->setMaterial(mate,MATERIAL_EMERALD);
//    scene->drawSphere(transform,mate);
    transform->setIdentity();
    transform->scale(25.0,1.0,25.0);
    transform->translate(0.0,-0.5,0.0);
    mate->setMaterial(mate,MATERIAL_GOLD);
    scene->drawPlane(transform,mate);
    delete transform;
    delete mate;
//    Matrix4x4 *transform = new Matrix4x4();
//    MaterialObj* mate = new MaterialObj();
//    mate->setMaterial(mate,MATERIAL_RUBY);
//    //transform->scale(0.5,0.5,0.5);
//    transform->setIdentity();
////    scene->drawCylinder(transform,mate);
////    transform->setIdentity();
////    transform->scale(2,1.0,1.5);
////    transform->translate(-2,1,0);
//    mate->setMaterial(mate,MATERIAL_COPPER);
//    scene->drawCube(transform,mate);
//    transform->setIdentity();
//    transform->scale(1.0,1.0,1.0);
//    transform->translate(0,0,2.5);
////    mate->setMaterial(mate,MATERIAL_EMERALD);
////    scene->drawSphere(transform,mate);
//    transform->setIdentity();
//    transform->scale(20.0,1.0,20.0);
//    transform->translate(0.0,-1.0,0.0);
//    mate->setMaterial(mate,MATERIAL_GOLD);
//    scene->drawPlane(transform,mate);
//    delete transform;
//    delete mate;
}

void GLWidget::renderSceneShadow()
{
    Matrix4x4 *transform = new Matrix4x4();
    MaterialObj* mate = new MaterialObj();
    mate->setMaterial(mate,MATERIAL_RUBY);
    //transform->scale(0.5,0.5,0.5);
    transform->setIdentity();
//    scene->drawCylinder(transform,mate);
//    transform->setIdentity();
//    transform->scale(2,1.0,1.5);
//    transform->translate(-2,1,0);
    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(0,1.5,0);
    mate->setMaterial(mate,MATERIAL_RUBY);
    scene->drawCubeShader(transform);


    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(2,0,1);
    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCubeShader(transform);

    transform->setIdentity();

    //transform->scale(0.5,0.5,0.5);
    //transform->setTranslate(Vec4(-1,0,2,1.0));

    transform->scale(0.5,0.5,0.5);
    transform->setRotationX(60);
    transform->setRotationZ(60);
    transform->setTranslate(Vec4(-1,0,2,1.0));

    //transform->setRotationX(60);
    //transform->setRotationZ(60);

    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCubeShader(transform);


//    mate->setMaterial(mate,MATERIAL_EMERALD);
//    scene->drawSphere(transform,mate);
    transform->setIdentity();
    transform->scale(25.0,1.0,25.0);
    transform->translate(0.0,-0.5,0.0);
    mate->setMaterial(mate,MATERIAL_GOLD);
    scene->drawPlaneShader(transform);
    delete transform;
    delete mate;
}

void GLWidget::renderSceneWithShadow()
{
    Matrix4x4 *transform = new Matrix4x4();
    MaterialObj* mate = new MaterialObj();
    mate->setMaterial(mate,MATERIAL_RUBY);
    //transform->scale(0.5,0.5,0.5);
    transform->setIdentity();
//    scene->drawCylinder(transform,mate);
//    transform->setIdentity();
//    transform->scale(2,1.0,1.5);
//    transform->translate(-2,1,0);
    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(0,1.5,0);
    mate->setMaterial(mate,MATERIAL_RUBY);
    scene->drawCubeShader2(transform,mate);


    transform->setIdentity();
    transform->scale(1.0,1.0,1.0);
    transform->translate(2,0,1);
    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCubeShader2(transform,mate);

    transform->setIdentity();

    transform->scale(0.5,0.5,0.5);
    transform->setRotationX(60);
    transform->setRotationZ(60);
    transform->setTranslate(Vec4(-1,0,2,1.0));


    //transform->setRotationX(60.f);
    //transform->setRotationZ(60);




    mate->setMaterial(mate,MATERIAL_TURQUOSIE);
    scene->drawCubeShader2(transform,mate);


//    mate->setMaterial(mate,MATERIAL_EMERALD);
//    scene->drawSphere(transform,mate);
    transform->setIdentity();
    transform->scale(25.0,1.0,25.0);
    transform->translate(0.0,-0.5,0.0);
    mate->setMaterial(mate,MATERIAL_GOLD);
    scene->drawPlaneShader2(transform,mate);
    delete transform;
    delete mate;
}


