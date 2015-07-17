/****************************************************************************
** Meta object code from reading C++ file 'cameracontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/ShaderPrimitives/cameracontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameracontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraController_t {
    QByteArrayData data[11];
    char stringdata[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CameraController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CameraController_t qt_meta_stringdata_CameraController = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 18),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 16),
QT_MOC_LITERAL(4, 54, 15),
QT_MOC_LITERAL(5, 70, 25),
QT_MOC_LITERAL(6, 96, 10),
QT_MOC_LITERAL(7, 107, 11),
QT_MOC_LITERAL(8, 119, 9),
QT_MOC_LITERAL(9, 129, 8),
QT_MOC_LITERAL(10, 138, 18)
    },
    "CameraController\0linearSpeedChanged\0"
    "\0orbitRateChanged\0lookRateChanged\0"
    "multisampleEnabledChanged\0toggleMSAA\0"
    "linearSpeed\0orbitRate\0lookRate\0"
    "multisampleEnabled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06,
       3,    0,   40,    2, 0x06,
       4,    0,   41,    2, 0x06,
       5,    0,   42,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::Float, 0x00495103,
       8, QMetaType::Float, 0x00495103,
       9, QMetaType::Float, 0x00495103,
      10, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void CameraController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraController *_t = static_cast<CameraController *>(_o);
        switch (_id) {
        case 0: _t->linearSpeedChanged(); break;
        case 1: _t->orbitRateChanged(); break;
        case 2: _t->lookRateChanged(); break;
        case 3: _t->multisampleEnabledChanged(); break;
        case 4: _t->toggleMSAA(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::linearSpeedChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::orbitRateChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CameraController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::lookRateChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (CameraController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::multisampleEnabledChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CameraController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraController.data,
      qt_meta_data_CameraController,  qt_static_metacall, 0, 0}
};


const QMetaObject *CameraController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraController.stringdata))
        return static_cast<void*>(const_cast< CameraController*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< float*>(_v) = linearSpeed(); break;
        case 1: *reinterpret_cast< float*>(_v) = orbitRate(); break;
        case 2: *reinterpret_cast< float*>(_v) = lookRate(); break;
        case 3: *reinterpret_cast< bool*>(_v) = isMultisampleEnabled(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLinearSpeed(*reinterpret_cast< float*>(_v)); break;
        case 1: setOrbitRate(*reinterpret_cast< float*>(_v)); break;
        case 2: setLookRate(*reinterpret_cast< float*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CameraController::linearSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CameraController::orbitRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CameraController::lookRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CameraController::multisampleEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
