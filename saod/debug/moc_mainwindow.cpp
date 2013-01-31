/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 29. Oct 17:07:50 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      31,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      77,   11,   11,   11, 0x0a,
      90,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     131,   11,   11,   11, 0x0a,
     141,   11,   11,   11, 0x0a,
     151,   11,   11,   11, 0x0a,
     164,   11,   11,   11, 0x0a,
     181,   11,   11,   11, 0x0a,
     202,   11,   11,   11, 0x0a,
     218,   11,   11,   11, 0x0a,
     236,   11,   11,   11, 0x0a,
     257,   11,   11,   11, 0x0a,
     275,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0show_client_form()\0"
    "show_car_form()\0show_hire_form()\0"
    "add_client()\0del_client()\0search_client()\0"
    "search_client_for_form()\0add_car()\0"
    "del_car()\0search_car()\0add_repire_car()\0"
    "return_from_repire()\0car_to_client()\0"
    "car_from_client()\0change_comboclient()\0"
    "change_combocar()\0change_combohire()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: show_client_form(); break;
        case 1: show_car_form(); break;
        case 2: show_hire_form(); break;
        case 3: add_client(); break;
        case 4: del_client(); break;
        case 5: search_client(); break;
        case 6: search_client_for_form(); break;
        case 7: add_car(); break;
        case 8: del_car(); break;
        case 9: search_car(); break;
        case 10: add_repire_car(); break;
        case 11: return_from_repire(); break;
        case 12: car_to_client(); break;
        case 13: car_from_client(); break;
        case 14: change_comboclient(); break;
        case 15: change_combocar(); break;
        case 16: change_combohire(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
