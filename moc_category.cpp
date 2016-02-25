/****************************************************************************
** Meta object code from reading C++ file 'category.h'
**
** Created: Tue Dec 4 08:08:13 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/category.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'category.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Category[] = {

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
      12,   10,    9,    9, 0x0a,
      49,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Category[] = {
    "Category\0\0,\0Category_map_from_error(int,QString)\0"
    "Category_map_from_result(QVariant)\0"
};

const QMetaObject Category::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Category,
      qt_meta_data_Category, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Category::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Category::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Category::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Category))
        return static_cast<void*>(const_cast< Category*>(this));
    return QObject::qt_metacast(_clname);
}

int Category::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Category_map_from_error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: Category_map_from_result((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
