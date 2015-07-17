/****************************************************************************
** Meta object code from reading C++ file 'sphere.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/ShaderPrimitives/sphere.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sphere.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Sphere_t {
    QByteArrayData data[11];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Sphere_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Sphere_t qt_meta_stringdata_Sphere = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 9),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 3),
QT_MOC_LITERAL(4, 22, 8),
QT_MOC_LITERAL(5, 31, 9),
QT_MOC_LITERAL(6, 41, 6),
QT_MOC_LITERAL(7, 48, 6),
QT_MOC_LITERAL(8, 55, 6),
QT_MOC_LITERAL(9, 62, 5),
QT_MOC_LITERAL(10, 68, 6)
    },
    "Sphere\0setRadius\0\0arg\0setRings\0setSlices\0"
    "create\0render\0radius\0rings\0slices\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sphere[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       4,    1,   42,    2, 0x0a,
       5,    1,   45,    2, 0x0a,
       6,    0,   48,    2, 0x0a,
       7,    0,   49,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Float, 0x00095103,
       9, QMetaType::Int, 0x00095103,
      10, QMetaType::Int, 0x00095103,

       0        // eod
};

void Sphere::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sphere *_t = static_cast<Sphere *>(_o);
        switch (_id) {
        case 0: _t->setRadius((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setRings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setSlices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->create(); break;
        case 4: _t->render(); break;
        default: ;
        }
    }
}

const QMetaObject Sphere::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sphere.data,
      qt_meta_data_Sphere,  qt_static_metacall, 0, 0}
};


const QMetaObject *Sphere::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sphere::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sphere.stringdata))
        return static_cast<void*>(const_cast< Sphere*>(this));
    return QObject::qt_metacast(_clname);
}

int Sphere::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = radius(); break;
        case 1: *reinterpret_cast< int*>(_v) = rings(); break;
        case 2: *reinterpret_cast< int*>(_v) = slices(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setRadius(*reinterpret_cast< float*>(_v)); break;
        case 1: setRings(*reinterpret_cast< int*>(_v)); break;
        case 2: setSlices(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
