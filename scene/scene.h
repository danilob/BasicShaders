#ifndef SCENE_H
#define SCENE_H

#include "math/vec4.h"
#include "graphics/ShaderPrimitives/material.h"
#include <QPointer>

class GLWidget;
class Matrix4x4;
class Ray;
class MaterialObj;
class Cube;
class Cylinder;
class Sphere;
class Camera;
class Plane;
class Scene : public QGLWidget
{
private:
    //physics
    Vec4           viewer[3];  //guarda as posições da camera, eye, at, up
    Vec4           projection;
    Camera         *m_camera;



    //shaders
    Cube           *m_cube;
    Sphere         *m_sphere;
    Cylinder       *m_cylinder;
    Plane          *m_plane;
    QMatrix4x4      m_modelMatrix;


    //interface
    GLWidget *parent;




public:
    int            width,height;


public:
    Scene(GLWidget *parent);
    ~Scene();

    //Shaders
    void        initializeShaders();
    MaterialPtr createMaterial();
    MaterialPtr createMaterial(QString vs, QString fs);
    MaterialPtr createTextureMaterial(const QString &fileName);
    void        setCamera(Camera *cam);
    void        drawCube();
    void        drawCube(Matrix4x4* transform, MaterialObj *mat);
    void        drawCubeShader(Matrix4x4* transform);
    void        drawCubeShader2(Matrix4x4* transform,MaterialObj *mat);



    void        drawSphere();
    void        drawSphere(Matrix4x4* transform, MaterialObj *mat);
    void        drawCylinder();
    void        drawCylinder(Matrix4x4* transform, MaterialObj *mat);
    void        drawPlane();
    void        drawPlane(Matrix4x4* transform, MaterialObj *mat);
    void        drawPlaneShader(Matrix4x4* transform);
    void        drawPlaneShader2(Matrix4x4* transform,MaterialObj *mat);







    //Manipulação dos objetos do cenário
    void                  setViewer(Vec4 eye,Vec4 at,Vec4 up);
    Vec4                  getEye();
    Vec4                  getAt();
    Vec4                  getUp();
    void                  setProjection(Vec4 p);
    void                  setWindow(int width,int height);

};

#endif // SCENE_H
