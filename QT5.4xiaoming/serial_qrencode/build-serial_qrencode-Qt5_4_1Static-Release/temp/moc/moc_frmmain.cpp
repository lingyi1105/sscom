/****************************************************************************
** Meta object code from reading C++ file 'frmmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../serial_qrencode/frmmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_frmMain_t {
    QByteArrayData data[13];
    char stringdata[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmMain_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmMain_t qt_meta_stringdata_frmMain = {
    {
QT_MOC_LITERAL(0, 0, 7), // "frmMain"
QT_MOC_LITERAL(1, 8, 22), // "on_btnMenu_Max_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "check_serial_port"
QT_MOC_LITERAL(4, 50, 15), // "serialport_recv"
QT_MOC_LITERAL(5, 66, 32), // "on_cboxStyle_currentIndexChanged"
QT_MOC_LITERAL(6, 99, 4), // "arg1"
QT_MOC_LITERAL(7, 104, 27), // "on_open_port_Button_clicked"
QT_MOC_LITERAL(8, 132, 22), // "on_prit_button_clicked"
QT_MOC_LITERAL(9, 155, 23), // "on_print_button_clicked"
QT_MOC_LITERAL(10, 179, 7), // "plotPic"
QT_MOC_LITERAL(11, 187, 9), // "QPrinter*"
QT_MOC_LITERAL(12, 197, 7) // "printer"

    },
    "frmMain\0on_btnMenu_Max_clicked\0\0"
    "check_serial_port\0serialport_recv\0"
    "on_cboxStyle_currentIndexChanged\0arg1\0"
    "on_open_port_Button_clicked\0"
    "on_prit_button_clicked\0on_print_button_clicked\0"
    "plotPic\0QPrinter*\0printer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void frmMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmMain *_t = static_cast<frmMain *>(_o);
        switch (_id) {
        case 0: _t->on_btnMenu_Max_clicked(); break;
        case 1: _t->check_serial_port(); break;
        case 2: _t->serialport_recv(); break;
        case 3: _t->on_cboxStyle_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_open_port_Button_clicked(); break;
        case 5: _t->on_prit_button_clicked(); break;
        case 6: _t->on_print_button_clicked(); break;
        case 7: _t->plotPic((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject frmMain::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmMain.data,
      qt_meta_data_frmMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *frmMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_frmMain.stringdata))
        return static_cast<void*>(const_cast< frmMain*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
