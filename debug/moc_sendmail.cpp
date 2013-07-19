/****************************************************************************
** Meta object code from reading C++ file 'sendmail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sendmail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sendmail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Sendmail_t {
    QByteArrayData data[7];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Sendmail_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Sendmail_t qt_meta_stringdata_Sendmail = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 9),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 13),
QT_MOC_LITERAL(4, 34, 16),
QT_MOC_LITERAL(5, 51, 14),
QT_MOC_LITERAL(6, 66, 17)
    },
    "Sendmail\0sendClick\0\0sendMailSlots\0"
    "addFromAddrSlots\0addToAddrSlots\0"
    "recvSendOverSlots\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sendmail[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   48,    2, 0x08,
       4,    0,   49,    2, 0x08,
       5,    0,   50,    2, 0x08,
       6,    0,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Sendmail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sendmail *_t = static_cast<Sendmail *>(_o);
        switch (_id) {
        case 0: _t->sendClick((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 1: _t->sendMailSlots(); break;
        case 2: _t->addFromAddrSlots(); break;
        case 3: _t->addToAddrSlots(); break;
        case 4: _t->recvSendOverSlots(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Sendmail::*_t)(QByteArray , QByteArray , QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sendmail::sendClick)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Sendmail::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sendmail.data,
      qt_meta_data_Sendmail,  qt_static_metacall, 0, 0}
};


const QMetaObject *Sendmail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sendmail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sendmail.stringdata))
        return static_cast<void*>(const_cast< Sendmail*>(this));
    return QWidget::qt_metacast(_clname);
}

int Sendmail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void Sendmail::sendClick(QByteArray _t1, QByteArray _t2, QByteArray _t3, QByteArray _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
