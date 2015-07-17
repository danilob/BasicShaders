#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLShaderProgram>
#include <QTimer>
#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>

class Camera;
class Scene;
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    QTimer *simTimer;
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    //configure scene
    void renderScene();
    void renderSceneShadow();
    void renderSceneWithShadow();

    //shadow mapping

    GLuint depthMapFBO;
    GLuint depthMap;

    
signals:
    
public slots:

private:
    Camera *m_camera;
    Scene* scene;
    int winWidth,winHeight;
    bool withshadow;
    
};

#endif // GLWIDGET_H
