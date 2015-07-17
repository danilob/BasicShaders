#-------------------------------------------------
#
# Project created by QtCreator 2013-09-09T17:14:18
#
#-------------------------------------------------

#para os shaders funcionarem corretamente adicionar a biblioteca openglextensions
QT       += core gui opengl widgets openglextensions

TARGET = BaseShaders
TEMPLATE = app
DEFINES += \
           SHADERS_ENABLED \
           GL_GLEXT_PROTOTYPES \

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    graphics/ObjMesh.cpp \
    math/vec4.cpp \
    math/matrix4x4.cpp \
    math/quaternion.cpp \
    graphics/shader.cpp \
    graphics/materialobj.cpp \
    graphics/ShaderPrimitives/material.cpp \
    graphics/ShaderPrimitives/texture.cpp \
    graphics/ShaderPrimitives/sphere.cpp \
    graphics/ShaderPrimitives/sampler.cpp \
    graphics/ShaderPrimitives/plane.cpp \
    graphics/ShaderPrimitives/objloader.cpp \
    graphics/ShaderPrimitives/mesh.cpp \
    graphics/ShaderPrimitives/kdgeometryshader.cpp \
    graphics/ShaderPrimitives/grid.cpp \
    graphics/ShaderPrimitives/cylinder.cpp \
    graphics/ShaderPrimitives/cube.cpp \
    graphics/ShaderPrimitives/camerascene.cpp \
    graphics/ShaderPrimitives/cameracontroller.cpp \
    graphics/ShaderPrimitives/camera.cpp \
    graphics/ShaderPrimitives/axisalignedboundingbox.cpp \
    graphics/ShaderPrimitives/abstractscene.cpp \
    scene/scene.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    graphics/ObjMesh.h \
    math/vec4.h \
    math/matrix4x4.h \
    math/quaternion.h \
    graphics/shader.h \
    graphics/materialobj.h \
    graphics/ShaderPrimitives/texture.h \
    graphics/ShaderPrimitives/sphere.h \
    graphics/ShaderPrimitives/sampler.h \
    graphics/ShaderPrimitives/plane.h \
    graphics/ShaderPrimitives/objloader.h \
    graphics/ShaderPrimitives/mesh.h \
    graphics/ShaderPrimitives/material.h \
    graphics/ShaderPrimitives/kdgeometryshader.h \
    graphics/ShaderPrimitives/grid.h \
    graphics/ShaderPrimitives/cylinder.h \
    graphics/ShaderPrimitives/cube.h \
    graphics/ShaderPrimitives/camerascene.h \
    graphics/ShaderPrimitives/cameracontroller.h \
    graphics/ShaderPrimitives/camera_p.h \
    graphics/ShaderPrimitives/camera.h \
    graphics/ShaderPrimitives/axisalignedboundingbox.h \
    graphics/ShaderPrimitives/abstractscene.h \
    scene/scene.h

FORMS    += mainwindow.ui

LIBS += -lGLU -lglut -lGL -lglut -lgsl -lgslcblas

QMAKE_CXXFLAGS += -o3
