/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/ShaderPrimitives/camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Camera_t {
    QByteArrayData data[45];
    char stringdata[489];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Camera_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Camera_t qt_meta_stringdata_Camera = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 11),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 8),
QT_MOC_LITERAL(4, 29, 11),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 13),
QT_MOC_LITERAL(7, 64, 10),
QT_MOC_LITERAL(8, 75, 19),
QT_MOC_LITERAL(9, 95, 9),
QT_MOC_LITERAL(10, 105, 6),
QT_MOC_LITERAL(11, 112, 23),
QT_MOC_LITERAL(12, 136, 6),
QT_MOC_LITERAL(13, 143, 14),
QT_MOC_LITERAL(14, 158, 6),
QT_MOC_LITERAL(15, 165, 4),
QT_MOC_LITERAL(16, 170, 5),
QT_MOC_LITERAL(17, 176, 3),
QT_MOC_LITERAL(18, 180, 4),
QT_MOC_LITERAL(19, 185, 19),
QT_MOC_LITERAL(20, 205, 18),
QT_MOC_LITERAL(21, 224, 19),
QT_MOC_LITERAL(22, 244, 6),
QT_MOC_LITERAL(23, 251, 1),
QT_MOC_LITERAL(24, 253, 21),
QT_MOC_LITERAL(25, 275, 4),
QT_MOC_LITERAL(26, 280, 10),
QT_MOC_LITERAL(27, 291, 10),
QT_MOC_LITERAL(28, 302, 7),
QT_MOC_LITERAL(29, 310, 7),
QT_MOC_LITERAL(30, 318, 7),
QT_MOC_LITERAL(31, 326, 13),
QT_MOC_LITERAL(32, 340, 9),
QT_MOC_LITERAL(33, 350, 14),
QT_MOC_LITERAL(34, 365, 14),
QT_MOC_LITERAL(35, 380, 9),
QT_MOC_LITERAL(36, 390, 8),
QT_MOC_LITERAL(37, 399, 11),
QT_MOC_LITERAL(38, 411, 11),
QT_MOC_LITERAL(39, 423, 4),
QT_MOC_LITERAL(40, 428, 5),
QT_MOC_LITERAL(41, 434, 6),
QT_MOC_LITERAL(42, 441, 3),
QT_MOC_LITERAL(43, 445, 20),
QT_MOC_LITERAL(44, 466, 21)
    },
    "Camera\0setPosition\0\0position\0setUpVector\0"
    "upVector\0setViewCenter\0viewCenter\0"
    "resetViewToIdentity\0translate\0vLocal\0"
    "CameraTranslationOption\0option\0"
    "translateWorld\0vWorld\0tilt\0angle\0pan\0"
    "roll\0tiltAboutViewCenter\0panAboutViewCenter\0"
    "rollAboutViewCenter\0rotate\0q\0"
    "rotateAboutViewCenter\0zoom\0translatex\0"
    "translatey\0rotatex\0rotatey\0rotatez\0"
    "GetViewMatrix\0glm::mat4\0projectionType\0"
    "ProjectionType\0nearPlane\0farPlane\0"
    "fieldOfView\0aspectRatio\0left\0right\0"
    "bottom\0top\0OrthogonalProjection\0"
    "PerspectiveProjection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
      12,  210, // properties
       1,  246, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x0a,
       4,    1,  132,    2, 0x0a,
       6,    1,  135,    2, 0x0a,
       8,    0,  138,    2, 0x0a,
       9,    2,  139,    2, 0x0a,
       9,    1,  144,    2, 0x2a,
      13,    2,  147,    2, 0x0a,
      13,    1,  152,    2, 0x2a,
      15,    1,  155,    2, 0x0a,
      17,    1,  158,    2, 0x0a,
      18,    1,  161,    2, 0x0a,
      19,    1,  164,    2, 0x0a,
      20,    1,  167,    2, 0x0a,
      21,    1,  170,    2, 0x0a,
      22,    1,  173,    2, 0x0a,
      24,    1,  176,    2, 0x0a,
      25,    2,  179,    2, 0x0a,
      26,    2,  184,    2, 0x0a,
      27,    2,  189,    2, 0x0a,
      28,    2,  194,    2, 0x0a,
      29,    2,  199,    2, 0x0a,
      30,    2,  204,    2, 0x0a,
      31,    0,  209,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QVector3D,    3,
    QMetaType::Void, QMetaType::QVector3D,    5,
    QMetaType::Void, QMetaType::QVector3D,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, 0x80000000 | 11,   10,   12,
    QMetaType::Void, QMetaType::QVector3D,   10,
    QMetaType::Void, QMetaType::QVector3D, 0x80000000 | 11,   14,   12,
    QMetaType::Void, QMetaType::QVector3D,   14,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::Float,   16,
    QMetaType::Void, QMetaType::QQuaternion,   23,
    QMetaType::Void, QMetaType::QQuaternion,   23,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    0x80000000 | 32,

 // properties: name, type, flags
       3, QMetaType::QVector3D, 0x00095103,
       5, QMetaType::QVector3D, 0x00095103,
       7, QMetaType::QVector3D, 0x00095103,
      33, 0x80000000 | 34, 0x00095009,
      35, QMetaType::Float, 0x00095103,
      36, QMetaType::Float, 0x00095103,
      37, QMetaType::Float, 0x00095103,
      38, QMetaType::Float, 0x00095103,
      39, QMetaType::Float, 0x00095103,
      40, QMetaType::Float, 0x00095103,
      41, QMetaType::Float, 0x00095103,
      42, QMetaType::Float, 0x00095103,

 // enums: name, flags, count, data
      34, 0x0,    2,  250,

 // enum data: key, value
      43, uint(Camera::OrthogonalProjection),
      44, uint(Camera::PerspectiveProjection),

       0        // eod
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Camera *_t = static_cast<Camera *>(_o);
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< const QVector3D(*)>(_a[1]))); break;
        case 1: _t->setUpVector((*reinterpret_cast< const QVector3D(*)>(_a[1]))); break;
        case 2: _t->setViewCenter((*reinterpret_cast< const QVector3D(*)>(_a[1]))); break;
        case 3: _t->resetViewToIdentity(); break;
        case 4: _t->translate((*reinterpret_cast< const QVector3D(*)>(_a[1])),(*reinterpret_cast< CameraTranslationOption(*)>(_a[2]))); break;
        case 5: _t->translate((*reinterpret_cast< const QVector3D(*)>(_a[1]))); break;
        case 6: _t->translateWorld((*reinterpret_cast< const QVector3D(*)>(_a[1])),(*reinterpret_cast< CameraTranslationOption(*)>(_a[2]))); break;
        case 7: _t->translateWorld((*reinterpret_cast< const QVector3D(*)>(_a[1]))); break;
        case 8: _t->tilt((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 9: _t->pan((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 10: _t->roll((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 11: _t->tiltAboutViewCenter((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 12: _t->panAboutViewCenter((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 13: _t->rollAboutViewCenter((*reinterpret_cast< const float(*)>(_a[1]))); break;
        case 14: _t->rotate((*reinterpret_cast< const QQuaternion(*)>(_a[1]))); break;
        case 15: _t->rotateAboutViewCenter((*reinterpret_cast< const QQuaternion(*)>(_a[1]))); break;
        case 16: _t->zoom((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 17: _t->translatex((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 18: _t->translatey((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 19: _t->rotatex((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 20: _t->rotatey((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 21: _t->rotatez((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 22: { glm::mat4 _r = _t->GetViewMatrix();
            if (_a[0]) *reinterpret_cast< glm::mat4*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Camera::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Camera.data,
      qt_meta_data_Camera,  qt_static_metacall, 0, 0}
};


const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Camera.stringdata))
        return static_cast<void*>(const_cast< Camera*>(this));
    return QObject::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVector3D*>(_v) = position(); break;
        case 1: *reinterpret_cast< QVector3D*>(_v) = upVector(); break;
        case 2: *reinterpret_cast< QVector3D*>(_v) = viewCenter(); break;
        case 3: *reinterpret_cast< ProjectionType*>(_v) = projectionType(); break;
        case 4: *reinterpret_cast< float*>(_v) = nearPlane(); break;
        case 5: *reinterpret_cast< float*>(_v) = farPlane(); break;
        case 6: *reinterpret_cast< float*>(_v) = fieldOfView(); break;
        case 7: *reinterpret_cast< float*>(_v) = aspectRatio(); break;
        case 8: *reinterpret_cast< float*>(_v) = left(); break;
        case 9: *reinterpret_cast< float*>(_v) = right(); break;
        case 10: *reinterpret_cast< float*>(_v) = bottom(); break;
        case 11: *reinterpret_cast< float*>(_v) = top(); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPosition(*reinterpret_cast< QVector3D*>(_v)); break;
        case 1: setUpVector(*reinterpret_cast< QVector3D*>(_v)); break;
        case 2: setViewCenter(*reinterpret_cast< QVector3D*>(_v)); break;
        case 4: setNearPlane(*reinterpret_cast< float*>(_v)); break;
        case 5: setFarPlane(*reinterpret_cast< float*>(_v)); break;
        case 6: setFieldOfView(*reinterpret_cast< float*>(_v)); break;
        case 7: setAspectRatio(*reinterpret_cast< float*>(_v)); break;
        case 8: setLeft(*reinterpret_cast< float*>(_v)); break;
        case 9: setRight(*reinterpret_cast< float*>(_v)); break;
        case 10: setBottom(*reinterpret_cast< float*>(_v)); break;
        case 11: setTop(*reinterpret_cast< float*>(_v)); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
