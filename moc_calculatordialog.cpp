/****************************************************************************
** Meta object code from reading C++ file 'calculatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "calculatordialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorDialog_t {
    QByteArrayData data[13];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorDialog_t qt_meta_stringdata_CalculatorDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CalculatorDialog"
QT_MOC_LITERAL(1, 17, 9), // "on_numBtn"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "on_bracketLeftBtn"
QT_MOC_LITERAL(4, 46, 18), // "on_bracketRightBtn"
QT_MOC_LITERAL(5, 65, 15), // "on_backspaceBtn"
QT_MOC_LITERAL(6, 81, 11), // "on_clearBtn"
QT_MOC_LITERAL(7, 93, 14), // "on_divisionBtn"
QT_MOC_LITERAL(8, 108, 20), // "on_multiplicationBtn"
QT_MOC_LITERAL(9, 129, 11), // "on_minusBtn"
QT_MOC_LITERAL(10, 141, 9), // "on_dotBtn"
QT_MOC_LITERAL(11, 151, 12), // "on_equalsBtn"
QT_MOC_LITERAL(12, 164, 10) // "on_plusBtn"

    },
    "CalculatorDialog\0on_numBtn\0\0"
    "on_bracketLeftBtn\0on_bracketRightBtn\0"
    "on_backspaceBtn\0on_clearBtn\0on_divisionBtn\0"
    "on_multiplicationBtn\0on_minusBtn\0"
    "on_dotBtn\0on_equalsBtn\0on_plusBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalculatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_numBtn(); break;
        case 1: _t->on_bracketLeftBtn(); break;
        case 2: _t->on_bracketRightBtn(); break;
        case 3: _t->on_backspaceBtn(); break;
        case 4: _t->on_clearBtn(); break;
        case 5: _t->on_divisionBtn(); break;
        case 6: _t->on_multiplicationBtn(); break;
        case 7: _t->on_minusBtn(); break;
        case 8: _t->on_dotBtn(); break;
        case 9: _t->on_equalsBtn(); break;
        case 10: _t->on_plusBtn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CalculatorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CalculatorDialog.data,
    qt_meta_data_CalculatorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalculatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CalculatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
