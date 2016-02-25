/****************************************************************************
** Meta object code from reading C++ file 'myapp.h'
**
** Created: Tue Dec 4 08:08:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/myapp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Myapp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      21,    6,    6,    6, 0x0a,
      38,    6,    6,    6, 0x0a,
      48,    6,    6,    6, 0x0a,
      59,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Myapp[] = {
    "Myapp\0\0MA_add_blog()\0MA_delete_blog()\0"
    "MA_help()\0MA_close()\0MA_post()\0"
};

const QMetaObject Myapp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Myapp,
      qt_meta_data_Myapp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Myapp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Myapp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Myapp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Myapp))
        return static_cast<void*>(const_cast< Myapp*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Myapp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MA_add_blog(); break;
        case 1: MA_delete_blog(); break;
        case 2: MA_help(); break;
        case 3: MA_close(); break;
        case 4: MA_post(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
