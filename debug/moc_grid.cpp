/****************************************************************************
** Meta object code from reading C++ file 'grid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/ShaderPrimitives/grid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Grid_t {
    QByteArrayData data[12];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Grid_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Grid_t qt_meta_stringdata_Grid = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 8),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 5),
QT_MOC_LITERAL(4, 21, 9),
QT_MOC_LITERAL(5, 31, 6),
QT_MOC_LITERAL(6, 38, 13),
QT_MOC_LITERAL(7, 52, 10),
QT_MOC_LITERAL(8, 63, 13),
QT_MOC_LITERAL(9, 77, 10),
QT_MOC_LITERAL(10, 88, 6),
QT_MOC_LITERAL(11, 95, 6)
    },
    "Grid\0setWidth\0\0width\0setHeight\0height\0"
    "setXDivisions\0xDivisions\0setYDivisions\0"
    "yDivisions\0create\0render\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grid[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a,
       4,    1,   47,    2, 0x0a,
       6,    1,   50,    2, 0x0a,
       8,    1,   53,    2, 0x0a,
      10,    0,   56,    2, 0x0a,
      11,    0,   57,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Float, 0x00095103,
       5, QMetaType::Float, 0x00095103,
       7, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,

       0        // eod
};

void Grid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grid *_t = static_cast<Grid *>(_o);
        switch (_id) {
        case 0: _t->setWidth((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setHeight((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setXDivisions((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setYDivisions((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->create(); break;
        case 5: _t->render(); break;
        default: ;
        }
    }
}

const QMetaObject Grid::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Grid.data,
      qt_meta_data_Grid,  qt_static_metacall, 0, 0}
};


const QMetaObject *Grid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Grid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Grid.stringdata))
        return static_cast<void*>(const_cast< Grid*>(this));
    return QObject::qt_metacast(_clname);
}

int Grid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = width(); break;
        case 1: *reinterpret_cast< float*>(_v) = height(); break;
        case 2: *reinterpret_cast< int*>(_v) = xDivisions(); break;
        case 3: *reinterpret_cast< int*>(_v) = yDivisions(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setWidth(*reinterpret_cast< float*>(_v)); break;
        case 1: setHeight(*reinterpret_cast< float*>(_v)); break;
        case 2: setXDivisions(*reinterpret_cast< int*>(_v)); break;
        case 3: setYDivisions(*reinterpret_cast< int*>(_v)); break;
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
QT_END_MOC_NAMESPACE
