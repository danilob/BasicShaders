#include "scene.h"

#include <stdio.h>

#include "graphics/materialobj.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


glm::vec3 lightPos(-2.0f, 4.0f, -1.0f);
glm::vec3 lightPosUp(0.f,1.f,0.f);

//shaders
#include "math/matrix4x4.h"
#include "graphics/ShaderPrimitives/abstractscene.h"
#include "graphics/ShaderPrimitives/camera.h"
#include "graphics/ShaderPrimitives/cube.h"
#include "graphics/ShaderPrimitives/sphere.h"
#include "graphics/ShaderPrimitives/cylinder.h"
#include "graphics/ShaderPrimitives/plane.h"



Scene::Scene(GLWidget *parent)
{
    //this->setContext(parent->context());//,parent->context(),false);
    QGLFormat glFormat;
    glFormat.setVersion( 3, 3 );
    glFormat.setProfile( QGLFormat::CoreProfile ); // Requires >=Qt-4.8.0
    glFormat.setSampleBuffers( true );
    glFormat.setSamples(32);

    this->setFormat(glFormat);







    //pose_time.start();

//    Object *ramp = addObject(Vec4(1.8,0.7,0.001),Vec4(0.2,0.1,1.5),Quaternion(Vec4(74,0,0)),TYPE_CUBE,1.2);
//    Object *cont = addObject(Vec4(1.8,0.20,0.5),Vec4(0.2,0.1,2.09),Quaternion(Vec4(0,0,0)),TYPE_CUBE,1.2);
//    Object *ramp2= addObject(Vec4(1.8,0.7,0.001),Vec4(0.2,0.1,2.68),Quaternion(Vec4(-74,0,0)),TYPE_CUBE,1.2);

//    objects.push_back(ramp);
//    objects.push_back(cont);
//    objects.push_back(ramp2);

    //objects.push_back(addObject(Vec4(0.2,0.2,0.2),Vec4(0,0.1,1.3),Quaternion(Vec4(0,0,0)),TYPE_CUBE,1.2));
}

Scene::~Scene(){

}

void Scene::initializeShaders()
{
    // Create a material that performs multi-texturing
    MaterialPtr material = createMaterial();
    MaterialPtr materialtex = createTextureMaterial("../texture/wood.png");
    MaterialPtr materialtex2 = createTextureMaterial("../texture/awesomeface.png");


    m_cube = new Cube(this);
    m_cube->setMaterial( material );
    m_cube->create();

    m_sphere = new Sphere(this);
    m_sphere->setMaterial( materialtex );
    m_sphere->create();

    m_cylinder = new Cylinder(this);
    m_cylinder->setMaterial( material );
    m_cylinder->create();

    m_plane = new Plane(this);
    m_plane->setMaterial( material );
    m_plane->create();

}

MaterialPtr Scene::createMaterial()
{
    // Create a material and set the shaders
    MaterialPtr material( new Material );
    material->setShaders( "../shaders/phong.vert",
                          "../shaders/phong.frag" );
    return material;
}

MaterialPtr Scene::createMaterial(QString vs, QString fs)
{
    // Create a material and set the shaders
    MaterialPtr material( new Material );
    material->setShaders( vs,
                          fs );
//    material->setShaders( "../shaders/shadowmap.vert",
//                          "../shaders/shadowmap.frag" );
    return material;
}

MaterialPtr Scene::createTextureMaterial(const QString &fileName)
{
    // Create a material and set the shaders
    MaterialPtr material( new Material );
    material->setShaders( "../shaders/texture.vert",
                          "../shaders/texture.frag" );

    // Create a texture
    TexturePtr texture0( new Texture( Texture::Texture2D ) );
    texture0->create();
    texture0->bind();
    texture0->setImage( QImage( fileName ) );

#if !defined(Q_OS_MAC)
    // Create a sampler. This can be shared by many textures
    SamplerPtr sampler( new Sampler );
    sampler->create();
    sampler->setWrapMode( Sampler::DirectionS, GL_CLAMP_TO_EDGE );
    sampler->setWrapMode( Sampler::DirectionT, GL_CLAMP_TO_EDGE );
    sampler->setMinificationFilter( GL_LINEAR );
    sampler->setMagnificationFilter( GL_LINEAR );

    // Associate the texture with the first texture unit
    material->setTextureUnitConfiguration( 0, texture0, sampler, QByteArrayLiteral( "texture0" ) );
#else
    // OS X does not (yet) support OpenGL 3.3 and Samplers so we set the
    // filtering options on the texture object itself
    texture0->setWrapMode( Texture::DirectionS, GL_CLAMP_TO_EDGE );
    texture0->setWrapMode( Texture::DirectionT, GL_CLAMP_TO_EDGE );
    texture0->setMinificationFilter( GL_LINEAR );
    texture0->setMagnificationFilter( GL_LINEAR );

    // Associate the texture with the first texture unit
    material->setTextureUnitConfiguration( 0, texture0, QByteArrayLiteral( "texture0" ) );
#endif
    return material;
}

void Scene::setCamera(Camera *cam)
{
    this->m_camera = cam;
}

void Scene::drawCube()
{
    m_cube->material()->bind();

    QOpenGLShaderProgramPtr shader = m_cube->material()->shader();

    m_modelMatrix.setToIdentity();
    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * m_modelMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", QVector4D( 5.0f, 5.0f, 5.0f, 1.0f ) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );

    // Set the material properties
    shader->setUniformValue( "material.ka", QVector3D( 0.1f, 0.1f, 0.3f ) );
    shader->setUniformValue( "material.kd", QVector3D( 0.0f, 0.2f, 0.9f ) );
    shader->setUniformValue( "material.ks", QVector3D( 0.4f, 0.4f, 0.4f ) );
    shader->setUniformValue( "material.shininess", 20.0f );

    // Let the mesh setup the remainder of its state and draw itself
    m_cube->render();
}

void Scene::drawCube(Matrix4x4 *transform, MaterialObj *mat)
{
    m_cube->material()->bind();
    QOpenGLShaderProgramPtr shader = m_cube->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSetedQuaternion();


//    printf("\nBegin ------- \n");

//    transform->showMatrix4x4();


    QQuaternion rot(rotate.x(),rotate.y(),rotate.z(),rotate.w());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());
    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rot);


    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( lightPos[0], lightPos[1], lightPos[2], 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128);

    // Let the mesh setup the remainder of its state and draw itself
    m_cube->render();
}

void Scene::drawCubeShader(Matrix4x4 *transform)
{
    MaterialPtr material = createMaterial("../shaders/simpleDepthShader.vert","../shaders/simpleDepthShader.frag");
    MaterialPtr old = m_cube->material();
    m_cube->setMaterial(material);
    m_cube->material()->bind();
    QOpenGLShaderProgramPtr shader = m_cube->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSetedQuaternion();


//    printf("\nBegin ------- \n");

//    transform->showMatrix4x4();


    QQuaternion rot(rotate.x(),rotate.y(),rotate.z(),rotate.w());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());
    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rot);


//    printf("\n");

//    for (int i=0;i<4;i++){
//        for (int j=0;j<4;j++)
//              printf("%d -  %.3f ",(4*i)+j,m_modelMatrix.data()[(4*i)+j]);
//        printf("\n");
//    }

//    printf("\nEnd ------- \n");
    //qDebug() << m_modelMatrix.data();



    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    //QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    //QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    // 1. Render depth of scene to texture (from light's perspective)
    // - Get light projection/view matrix.
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    GLfloat near_plane = 1.0f, far_plane = 17.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lightPos, glm::vec3(0.0f), lightPosUp);
    lightSpaceMatrix = lightProjection * lightView;

//    float dArray[16] = {0.0};

//    //const float *pSource = (const float*) glm::value_ptr(lightSpaceMatrix);
//    for (int i = 0; i < 16; ++i)
//        dArray[i] = pSource[i];



//    QMatrix4x4 lightSpace(dArray);

    // - render scene from light's point of view
    //simpleDepthShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));







    //m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "model", m_modelMatrix );
    //shader->setUniformValue( "lightSpaceMatrix ", lightSpace  );
    //shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    //shader->setUniformValue( "mvp", mvp );

//    // Set the lighting parameters
//    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( 5.0f, 5.0f, -5.0f, 1.0f) );
//    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


//    // Set the material properties
//    Vec4 amb = mat->ambientMaterial();
//    Vec4 diff = mat->diffuseMaterial();
//    Vec4 spe = mat->specularMaterial();
//    float shine = mat->shininessMaterial();


//    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
//    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
//    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
//    shader->setUniformValue( "material.shininess", shine*128);

    // Let the mesh setup the remainder of its state and draw itself
    m_cube->render();
    m_cube->setMaterial(old);
}

void Scene::drawCubeShader2(Matrix4x4 *transform, MaterialObj *mat)
{
    MaterialPtr material = createMaterial("../shaders/shadow_mapping.vert","../shaders/shadow_mapping.frag");
    MaterialPtr old = m_cube->material();
    m_cube->setMaterial(material);
    m_cube->material()->bind();
    QOpenGLShaderProgramPtr shader = m_cube->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSetedQuaternion();


//    printf("\nBegin ------- \n");

//    transform->showMatrix4x4();


    QQuaternion rot(rotate.x(),rotate.y(),rotate.z(),rotate.w());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());
    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rot);


//    printf("\n");

//    for (int i=0;i<4;i++){
//        for (int j=0;j<4;j++)
//              printf("%d -  %.3f ",(4*i)+j,m_modelMatrix.data()[(4*i)+j]);
//        printf("\n");
//    }

//    printf("\nEnd ------- \n");



    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    //QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    // 1. Render depth of scene to texture (from light's perspective)
    // - Get light projection/view matrix.
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    GLfloat near_plane = 1.0f, far_plane = 17.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lightPos, glm::vec3(0.0f), lightPosUp);
    lightSpaceMatrix = lightProjection * lightView;


    glm::mat4 projection = glm::perspective(30.f, (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = m_camera->GetViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "view"), 1, GL_FALSE, glm::value_ptr(view));
    // Set light uniforms
    glUniform3fv(glGetUniformLocation(shader->programId(), "lightPos"), 1, &lightPos[0]);
    glUniform3fv(glGetUniformLocation(shader->programId(), "viewPos"), 1, &m_camera->position()[0]);
    //glUniformMatrix4fv(glGetUniformLocation(shader.Program, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
    // Enable/Disable shadows by pressing 'SPACE'
    glUniform1i(glGetUniformLocation(shader->programId(), "shadows"), true);
//    float dArray[16] = {0.0};

//    //const float *pSource = (const float*) glm::value_ptr(lightSpaceMatrix);
//    for (int i = 0; i < 16; ++i)
//        dArray[i] = pSource[i];



//    QMatrix4x4 lightSpace(dArray);

    // - render scene from light's point of view
    //simpleDepthShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));







    //m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "model", m_modelMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    //shader->setUniformValue( "lightSpaceMatrix ", lightSpace  );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    //shader->setUniformValue( "mvp", mvp );

//    // Set the lighting parameters
    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( lightPos[0], lightPos[1], lightPos[2], 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128);

    // Let the mesh setup the remainder of its state and draw itself
    m_cube->render();
    m_cube->setMaterial(old);
}

void Scene::drawSphere()
{
    m_sphere->material()->bind();
    QOpenGLShaderProgramPtr shader = m_sphere->material()->shader();

    m_modelMatrix.setToIdentity();
    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * m_modelMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", QVector4D( 5.0f, 5.0f, 5.0f, 1.0f ) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );

    // Set the material properties
    shader->setUniformValue( "material.ka", QVector3D( 0.1f, 0.1f, 0.3f ) );
    shader->setUniformValue( "material.kd", QVector3D( 0.0f, 0.2f, 0.9f ) );
    shader->setUniformValue( "material.ks", QVector3D( 0.4f, 0.4f, 0.4f ) );
    shader->setUniformValue( "material.shininess", 20.0f );

    // Let the mesh setup the remainder of its state and draw itself
    m_sphere->render();
}

void Scene::drawSphere(Matrix4x4 *transform, MaterialObj *mat)
{
    m_sphere->material()->bind();
    QOpenGLShaderProgramPtr shader = m_sphere->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSeted();

    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rotate.x(),rotate.y(),rotate.z());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());

    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( 5.0f, 5.0f, -5.0f, 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128 );

    // Let the mesh setup the remainder of its state and draw itself
    m_sphere->render();
}

void Scene::drawCylinder()
{
    m_cylinder->material()->bind();
    QOpenGLShaderProgramPtr shader = m_cylinder->material()->shader();

    m_modelMatrix.setToIdentity();
    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * m_modelMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", QVector4D( 5.0f, 5.0f, 5.0f, 1.0f ) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );

    // Set the material properties
    shader->setUniformValue( "material.ka", QVector3D( 0.1f, 0.1f, 0.3f ) );
    shader->setUniformValue( "material.kd", QVector3D( 0.0f, 0.2f, 0.9f ) );
    shader->setUniformValue( "material.ks", QVector3D( 0.4f, 0.4f, 0.4f ) );
    shader->setUniformValue( "material.shininess", 20.0f );

    // Let the mesh setup the remainder of its state and draw itself
    m_cylinder->render();
}

void Scene::drawCylinder(Matrix4x4 *transform, MaterialObj *mat)
{
    m_cylinder->material()->bind();
    QOpenGLShaderProgramPtr shader = m_cylinder->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSeted();

    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rotate.x(),rotate.y(),rotate.z());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());

    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( 5.0f, 5.0f, -5.0f, 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128 );

    // Let the mesh setup the remainder of its state and draw itself
    m_cylinder->render();
}

void Scene::drawPlane()
{
    m_plane->material()->bind();
    QOpenGLShaderProgramPtr shader = m_plane->material()->shader();

    m_modelMatrix.setToIdentity();
    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * m_modelMatrix;


    m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", m_camera->viewMatrix() * QVector4D( 5.0f, 5.0f, 5.0f, 1.0f ) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );

    // Set the material properties
    shader->setUniformValue( "material.ka", QVector3D( 0.1f, 0.1f, 0.3f ) );
    shader->setUniformValue( "material.kd", QVector3D( 0.0f, 0.2f, 0.9f ) );
    shader->setUniformValue( "material.ks", QVector3D( 0.4f, 0.4f, 0.4f ) );
    shader->setUniformValue( "material.shininess", 20.0f );

    // Let the mesh setup the remainder of its state and draw itself
    m_plane->render();
}

void Scene::drawPlane(Matrix4x4 *transform, MaterialObj *mat)
{
    m_plane->material()->bind();
    QOpenGLShaderProgramPtr shader = m_plane->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSeted();

    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rotate.x(),rotate.y(),rotate.z());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());

    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    shader->setUniformValue( "modelViewMatrix", modelViewMatrix );
    shader->setUniformValue( "normalMatrix", normalMatrix );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    shader->setUniformValue( "mvp", mvp );

    //m_camera->setStandardUniforms( shader, m_modelMatrix );

    // Set the lighting parameters
    shader->setUniformValue( "light.position", QVector4D( lightPos[0], lightPos[1], lightPos[2], 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128 );

//    m_camera->setStandardUniforms( shader, m_modelMatrix );

//    // Set the lighting parameters
//    shader->setUniformValue( "light.position", QVector4D( 0.0f, 0.0f, 0.0f, 1.0f ) );
//    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );

//    // Set the material properties
//    shader->setUniformValue( "material.Ka", QVector3D( 0.7f, 0.7f, 0.7f ) );
//    shader->setUniformValue( "material.Kd", QVector3D( 0.9f, 0.9f, 0.9f ) );
//    shader->setUniformValue( "material.Ks", QVector3D( 0.4f, 0.4f, 0.4f ) );
//    shader->setUniformValue( "material.shininess", 10.0f );

    // Let the mesh setup the remainder of its state and draw itself
    m_plane->render();
}

void Scene::drawPlaneShader(Matrix4x4 *transform)
{
    MaterialPtr material = createMaterial("../shaders/simpleDepthShader.vert","../shaders/simpleDepthShader.frag");
    MaterialPtr old = m_plane->material();
    m_plane->setMaterial(material);
    m_plane->material()->bind();
    QOpenGLShaderProgramPtr shader = m_plane->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSeted();

    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rotate.x(),rotate.y(),rotate.z());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());

    //QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    //QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    //QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    // 1. Render depth of scene to texture (from light's perspective)
    // - Get light projection/view matrix.
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    GLfloat near_plane = 1.0f, far_plane = 17.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lightPos, glm::vec3(0.0f), lightPosUp);
    lightSpaceMatrix = lightProjection * lightView;

//    float dArray[16] = {0.0};

//    //const float *pSource = (const float*) glm::value_ptr(lightSpaceMatrix);
//    for (int i = 0; i < 16; ++i)
//        dArray[i] = pSource[i];



//    QMatrix4x4 lightSpace(dArray);

    // - render scene from light's point of view
    //simpleDepthShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));







    //m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "model", m_modelMatrix );
    //shader->setUniformValue( "lightSpaceMatrix ", lightSpace  );
    //shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    //shader->setUniformValue( "mvp", mvp );

//    // Set the lighting parameters
//    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( 5.0f, 5.0f, -5.0f, 1.0f) );
//    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


//    // Set the material properties
//    Vec4 amb = mat->ambientMaterial();
//    Vec4 diff = mat->diffuseMaterial();
//    Vec4 spe = mat->specularMaterial();
//    float shine = mat->shininessMaterial();


//    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
//    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
//    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
//    shader->setUniformValue( "material.shininess", shine*128);

    // Let the mesh setup the remainder of its state and draw itself
    m_plane->render();
    m_plane->setMaterial(old);
}

void Scene::drawPlaneShader2(Matrix4x4 *transform, MaterialObj *mat)
{
    MaterialPtr material = createMaterial("../shaders/shadow_mapping.vert","../shaders/shadow_mapping.frag");
    MaterialPtr old = m_plane->material();
    m_plane->setMaterial(material);
    m_plane->material()->bind();
    QOpenGLShaderProgramPtr shader = m_plane->material()->shader();

    m_modelMatrix.setToIdentity();

    Vec4 translate = transform->getTranslateSeted();
    Vec4 scale     = transform->getScaleSeted();
    Vec4 rotate  = transform->getRotationSetedQuaternion();


//    printf("\nBegin ------- \n");

//    transform->showMatrix4x4();


    QQuaternion rot(rotate.x(),rotate.y(),rotate.z(),rotate.w());
    m_modelMatrix.translate(translate.x(),translate.y(),translate.z());
    m_modelMatrix.scale(scale.x(),scale.y(),scale.z());
    m_modelMatrix.rotate(rot);


    QMatrix4x4 modelViewMatrix = m_camera->viewMatrix() * m_modelMatrix;
    QMatrix3x3 normalMatrix = modelViewMatrix.normalMatrix();
    //QMatrix4x4 mvp = m_camera->viewProjectionMatrix() * modelViewMatrix;

    // 1. Render depth of scene to texture (from light's perspective)
    // - Get light projection/view matrix.
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    GLfloat near_plane = 1.0f, far_plane = 17.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lightPos, glm::vec3(0.0f), lightPosUp);
    lightSpaceMatrix = lightProjection * lightView;



    glm::mat4 projection = glm::perspective(30.f, (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = m_camera->GetViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "view"), 1, GL_FALSE, glm::value_ptr(view));
    // Set light uniforms
    glUniform3fv(glGetUniformLocation(shader->programId(), "lightPos"), 1, &lightPos[0]);
    glUniform3fv(glGetUniformLocation(shader->programId(), "viewPos"), 1, &m_camera->position()[0]);
    //glUniformMatrix4fv(glGetUniformLocation(shader.Program, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
    // Enable/Disable shadows by pressing 'SPACE'
    glUniform1i(glGetUniformLocation(shader->programId(), "shadows"), true);

//    float dArray[16] = {0.0};

//    //const float *pSource = (const float*) glm::value_ptr(lightSpaceMatrix);
//    for (int i = 0; i < 16; ++i)
//        dArray[i] = pSource[i];

shader->setUniformValue( "normalMatrix", normalMatrix );

//    QMatrix4x4 lightSpace(dArray);

    // - render scene from light's point of view
    //simpleDepthShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shader->programId(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));







    //m_camera->setStandardUniforms( shader, m_modelMatrix );

    shader->setUniformValue( "model", m_modelMatrix );
    //shader->setUniformValue( "lightSpaceMatrix ", lightSpace  );
    shader->setUniformValue( "projectionMatrix", m_camera->projectionMatrix() );
    //shader->setUniformValue( "mvp", mvp );

//    // Set the lighting parameters
//    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( 5.0f, 5.0f, -5.0f, 1.0f) );
//    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );
    shader->setUniformValue( "light.position", modelViewMatrix * QVector4D( lightPos[0], lightPos[1], lightPos[2], 1.0f) );
    shader->setUniformValue( "light.intensity", QVector3D( 1.0f, 1.0f, 1.0f ) );


    // Set the material properties
    Vec4 amb = mat->ambientMaterial();
    Vec4 diff = mat->diffuseMaterial();
    Vec4 spe = mat->specularMaterial();
    float shine = mat->shininessMaterial();


    shader->setUniformValue( "material.ka", QVector3D( amb.x(), amb.y(), amb.z() ) );
    shader->setUniformValue( "material.kd", QVector3D( diff.x(), diff.y(), diff.z() ) );
    shader->setUniformValue( "material.ks", QVector3D( spe.x(), spe.y(), spe.z() ) );
    shader->setUniformValue( "material.shininess", shine*128);

    // Let the mesh setup the remainder of its state and draw itself
    m_plane->render();
    m_plane->setMaterial(old);
}


void Scene::setViewer(Vec4 eye, Vec4 at, Vec4 up)
{
    viewer[0] = eye;
    viewer[1] = at;
    viewer[2] = up;
}

Vec4 Scene::getEye()
{
    return viewer[0];
}

Vec4 Scene::getAt()
{
    return viewer[1];
}

Vec4 Scene::getUp()
{
    return viewer[2];
}

void Scene::setProjection(Vec4 p)
{
    projection = p;
}

void Scene::setWindow(int width, int height)
{
    this->width = width;
    this->height = height;
}

