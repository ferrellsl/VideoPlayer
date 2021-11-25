/****************************************************************************
** Meta object code from reading C++ file 'VideoSlider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Widget/VideoSlider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoSlider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoSlider_t {
    QByteArrayData data[9];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoSlider_t qt_meta_stringdata_VideoSlider = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoSlider"
QT_MOC_LITERAL(1, 12, 11), // "sig_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "mSec"
QT_MOC_LITERAL(4, 30, 12), // "sig_setStart"
QT_MOC_LITERAL(5, 43, 10), // "sig_setEnd"
QT_MOC_LITERAL(6, 54, 16), // "sig_valueChanged"
QT_MOC_LITERAL(7, 71, 16), // "slotTimerTimeOut"
QT_MOC_LITERAL(8, 88, 25) // "slotMousemoveTimerTimeOut"

    },
    "VideoSlider\0sig_clicked\0\0mSec\0"
    "sig_setStart\0sig_setEnd\0sig_valueChanged\0"
    "slotTimerTimeOut\0slotMousemoveTimerTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VideoSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoSlider *_t = static_cast<VideoSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_clicked((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->sig_setStart((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->sig_setEnd((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->sig_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotTimerTimeOut(); break;
        case 5: _t->slotMousemoveTimerTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoSlider::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoSlider::sig_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoSlider::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoSlider::sig_setStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VideoSlider::*_t)(qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoSlider::sig_setEnd)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (VideoSlider::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoSlider::sig_valueChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject VideoSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_VideoSlider.data,
      qt_meta_data_VideoSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoSlider.stringdata0))
        return static_cast<void*>(const_cast< VideoSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int VideoSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void VideoSlider::sig_clicked(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoSlider::sig_setStart(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoSlider::sig_setEnd(qint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoSlider::sig_valueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
