/****************************************************************************
** Meta object code from reading C++ file 'restdll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../restdll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'restdll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Restdll_t {
    QByteArrayData data[20];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Restdll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Restdll_t qt_meta_stringdata_Restdll = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Restdll"
QT_MOC_LITERAL(1, 8, 12), // "returnvalues"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "recvpostvalues"
QT_MOC_LITERAL(4, 37, 6), // "param1"
QT_MOC_LITERAL(5, 44, 6), // "param2"
QT_MOC_LITERAL(6, 51, 10), // "logingetID"
QT_MOC_LITERAL(7, 62, 8), // "getsaldo"
QT_MOC_LITERAL(8, 71, 8), // "drawraha"
QT_MOC_LITERAL(9, 80, 12), // "saldonmuutos"
QT_MOC_LITERAL(10, 93, 6), // "logout"
QT_MOC_LITERAL(11, 100, 9), // "loginslot"
QT_MOC_LITERAL(12, 110, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 125, 5), // "reply"
QT_MOC_LITERAL(14, 131, 6), // "IDslot"
QT_MOC_LITERAL(15, 138, 6), // "reply1"
QT_MOC_LITERAL(16, 145, 9), // "saldoslot"
QT_MOC_LITERAL(17, 155, 10), // "saldoslot2"
QT_MOC_LITERAL(18, 166, 6), // "reply2"
QT_MOC_LITERAL(19, 173, 8) // "drawslot"

    },
    "Restdll\0returnvalues\0\0recvpostvalues\0"
    "param1\0param2\0logingetID\0getsaldo\0"
    "drawraha\0saldonmuutos\0logout\0loginslot\0"
    "QNetworkReply*\0reply\0IDslot\0reply1\0"
    "saldoslot\0saldoslot2\0reply2\0drawslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Restdll[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   72,    2, 0x0a /* Public */,
       6,    0,   77,    2, 0x0a /* Public */,
       7,    0,   78,    2, 0x0a /* Public */,
       8,    1,   79,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    1,   89,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   15,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   18,
    QMetaType::Void, 0x80000000 | 12,   15,

       0        // eod
};

void Restdll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Restdll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnvalues((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->recvpostvalues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->logingetID(); break;
        case 3: _t->getsaldo(); break;
        case 4: _t->drawraha((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->logout(); break;
        case 6: _t->loginslot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->IDslot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->saldoslot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->saldoslot2((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->drawslot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Restdll::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Restdll::returnvalues)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Restdll::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Restdll.data,
    qt_meta_data_Restdll,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Restdll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Restdll::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Restdll.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Restdll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Restdll::returnvalues(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
