/****************************************************************************
** Meta object code from reading C++ file 'GBSubdivisionDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TitanImagePlugin/otitan.ortho.gb_subdivision/GBSubdivisionDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GBSubdivisionDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GBSubdivisionDlg_t {
    QByteArrayData data[13];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GBSubdivisionDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GBSubdivisionDlg_t qt_meta_stringdata_GBSubdivisionDlg = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GBSubdivisionDlg"
QT_MOC_LITERAL(1, 17, 17), // "ExchangeCutMethod"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "Confirm"
QT_MOC_LITERAL(4, 44, 9), // "OpenImage"
QT_MOC_LITERAL(5, 54, 13), // "AddOutputPath"
QT_MOC_LITERAL(6, 68, 12), // "ScaleChanged"
QT_MOC_LITERAL(7, 81, 5), // "index"
QT_MOC_LITERAL(8, 87, 12), // "CheckChanged"
QT_MOC_LITERAL(9, 100, 6), // "status"
QT_MOC_LITERAL(10, 107, 18), // "SymbolStateChanged"
QT_MOC_LITERAL(11, 126, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(12, 144, 4) // "item"

    },
    "GBSubdivisionDlg\0ExchangeCutMethod\0\0"
    "Confirm\0OpenImage\0AddOutputPath\0"
    "ScaleChanged\0index\0CheckChanged\0status\0"
    "SymbolStateChanged\0QTableWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GBSubdivisionDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x09 /* Protected */,
       3,    0,   52,    2, 0x09 /* Protected */,
       4,    0,   53,    2, 0x09 /* Protected */,
       5,    0,   54,    2, 0x09 /* Protected */,
       6,    1,   55,    2, 0x09 /* Protected */,
       8,    1,   58,    2, 0x09 /* Protected */,
      10,    1,   61,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void GBSubdivisionDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GBSubdivisionDlg *_t = static_cast<GBSubdivisionDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ExchangeCutMethod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Confirm(); break;
        case 2: _t->OpenImage(); break;
        case 3: _t->AddOutputPath(); break;
        case 4: _t->ScaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->CheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SymbolStateChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GBSubdivisionDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GBSubdivisionDlg.data,
      qt_meta_data_GBSubdivisionDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GBSubdivisionDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GBSubdivisionDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GBSubdivisionDlg.stringdata0))
        return static_cast<void*>(const_cast< GBSubdivisionDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int GBSubdivisionDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
