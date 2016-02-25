/****************************************************************************
** Meta object code from reading C++ file 'wordpress.h'
**
** Created: Tue Dec 4 08:10:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/wordpress.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wordpress.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Wordpress[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      36,   34,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   34,   10,   10, 0x0a,
      96,   93,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Wordpress[] = {
    "Wordpress\0\0Wordpress_OK(QVariant)\0,\0"
    "Wordpress_FAILED(int,QString)\0"
    "Wordpress_ok(int,QVariant)\0,,\0"
    "Wordpress_failed(int,int,QString)\0"
};

const QMetaObject Wordpress::staticMetaObject = {
    { &Base::staticMetaObject, qt_meta_stringdata_Wordpress,
      qt_meta_data_Wordpress, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Wordpress::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Wordpress::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Wordpress::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Wordpress))
        return static_cast<void*>(const_cast< Wordpress*>(this));
    return Base::qt_metacast(_clname);
}

int Wordpress::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Base::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Wordpress_OK((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: Wordpress_FAILED((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: Wordpress_ok((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: Wordpress_failed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Wordpress::Wordpress_OK(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Wordpress::Wordpress_FAILED(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
