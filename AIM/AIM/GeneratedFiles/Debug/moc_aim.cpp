/****************************************************************************
** Meta object code from reading C++ file 'aim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../aim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AIM_t {
    QByteArrayData data[9];
    char stringdata[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AIM_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AIM_t qt_meta_stringdata_AIM = {
    {
QT_MOC_LITERAL(0, 0, 3),
QT_MOC_LITERAL(1, 4, 18),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 22),
QT_MOC_LITERAL(4, 47, 28),
QT_MOC_LITERAL(5, 76, 21),
QT_MOC_LITERAL(6, 98, 7),
QT_MOC_LITERAL(7, 106, 22),
QT_MOC_LITERAL(8, 129, 4)
    },
    "AIM\0startButtonClicked\0\0loadImageButtonClicked\0"
    "refreshDatabaseButtonClicked\0"
    "pathToDatabaseChanged\0newPath\0"
    "setCleanAndRebuildFlag\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AIM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void AIM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AIM *_t = static_cast<AIM *>(_o);
        switch (_id) {
        case 0: _t->startButtonClicked(); break;
        case 1: _t->loadImageButtonClicked(); break;
        case 2: _t->refreshDatabaseButtonClicked(); break;
        case 3: _t->pathToDatabaseChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setCleanAndRebuildFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AIM::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AIM.data,
      qt_meta_data_AIM,  qt_static_metacall, 0, 0}
};


const QMetaObject *AIM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AIM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AIM.stringdata))
        return static_cast<void*>(const_cast< AIM*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AIM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
