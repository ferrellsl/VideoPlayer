/****************************************************************************
** Meta object code from reading C++ file 'FunctionTransfer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Base/FunctionTransfer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FunctionTransfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FunctionTransfer_t {
    QByteArrayData data[7];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FunctionTransfer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FunctionTransfer_t qt_meta_stringdata_FunctionTransfer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "FunctionTransfer"
QT_MOC_LITERAL(1, 17, 7), // "comming"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "std::function<void()>"
QT_MOC_LITERAL(4, 48, 1), // "f"
QT_MOC_LITERAL(5, 50, 15), // "comming_noBlock"
QT_MOC_LITERAL(6, 66, 8) // "slotExec"

    },
    "FunctionTransfer\0comming\0\0"
    "std::function<void()>\0f\0comming_noBlock\0"
    "slotExec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunctionTransfer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void FunctionTransfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FunctionTransfer *_t = static_cast<FunctionTransfer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comming((*reinterpret_cast< std::function<void()>(*)>(_a[1]))); break;
        case 1: _t->comming_noBlock((*reinterpret_cast< std::function<void()>(*)>(_a[1]))); break;
        case 2: _t->slotExec((*reinterpret_cast< std::function<void()>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FunctionTransfer::*_t)(std::function<void()> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionTransfer::comming)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FunctionTransfer::*_t)(std::function<void()> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionTransfer::comming_noBlock)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FunctionTransfer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FunctionTransfer.data,
      qt_meta_data_FunctionTransfer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FunctionTransfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunctionTransfer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionTransfer.stringdata0))
        return static_cast<void*>(const_cast< FunctionTransfer*>(this));
    return QObject::qt_metacast(_clname);
}

int FunctionTransfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FunctionTransfer::comming(std::function<void()> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FunctionTransfer::comming_noBlock(std::function<void()> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
