/****************************************************************************
** Meta object code from reading C++ file 'FileFilterDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TitanImagePlugin/otitan.tool.file_compress/FileFilterDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileFilterDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileFilterDlg_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileFilterDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileFilterDlg_t qt_meta_stringdata_FileFilterDlg = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FileFilterDlg"
QT_MOC_LITERAL(1, 14, 12), // "AddDirectory"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "AllSelect"
QT_MOC_LITERAL(4, 38, 10), // "ClearFiles"
QT_MOC_LITERAL(5, 49, 13) // "ReverseSelect"

    },
    "FileFilterDlg\0AddDirectory\0\0AllSelect\0"
    "ClearFiles\0ReverseSelect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileFilterDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileFilterDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileFilterDlg *_t = static_cast<FileFilterDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddDirectory(); break;
        case 1: _t->AllSelect(); break;
        case 2: _t->ClearFiles(); break;
        case 3: _t->ReverseSelect(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FileFilterDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FileFilterDlg.data,
      qt_meta_data_FileFilterDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileFilterDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileFilterDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileFilterDlg.stringdata0))
        return static_cast<void*>(const_cast< FileFilterDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int FileFilterDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
