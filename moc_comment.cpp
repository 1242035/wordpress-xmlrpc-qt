/****************************************************************************
** Meta object code from reading C++ file 'comment.h'
**
** Created: Tue Dec 4 08:08:21 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/comment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Comment[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      36,   34,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Comment[] = {
    "Comment\0\0Comment_get_ok(QVariant)\0,\0"
    "Comment_get_failed(int,QString)\0"
};

const QMetaObject Comment::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Comment,
      qt_meta_data_Comment, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Comment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Comment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Comment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Comment))
        return static_cast<void*>(const_cast< Comment*>(this));
    return QObject::qt_metacast(_clname);
}

int Comment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Comment_get_ok((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: Comment_get_failed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
