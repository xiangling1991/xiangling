/****************************************************************************
** Meta object code from reading C++ file 'FileExtractDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TitanImagePlugin/otitan.tool.file_extract/FileExtractDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileExtractDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileExtractDlg_t {
    QByteArrayData data[9];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileExtractDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileExtractDlg_t qt_meta_stringdata_FileExtractDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FileExtractDlg"
QT_MOC_LITERAL(1, 15, 7), // "Message"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "msg"
QT_MOC_LITERAL(4, 28, 15), // "AddCompressFile"
QT_MOC_LITERAL(5, 44, 18), // "RemoveCompressFile"
QT_MOC_LITERAL(6, 63, 13), // "AddOutputPath"
QT_MOC_LITERAL(7, 77, 7), // "Confirm"
QT_MOC_LITERAL(8, 85, 11) // "ShowMessage"

    },
    "FileExtractDlg\0Message\0\0msg\0AddCompressFile\0"
    "RemoveCompressFile\0AddOutputPath\0"
    "Confirm\0ShowMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileExtractDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x09 /* Protected */,
       5,    0,   48,    2, 0x09 /* Protected */,
       6,    0,   49,    2, 0x09 /* Protected */,
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    1,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void FileExtractDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileExtractDlg *_t = static_cast<FileExtractDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->AddCompressFile(); break;
        case 2: _t->RemoveCompressFile(); break;
        case 3: _t->AddOutputPath(); break;
        case 4: _t->Confirm(); break;
        case 5: _t->ShowMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileExtractDlg::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileExtractDlg::Message)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FileExtractDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FileExtractDlg.data,
      qt_meta_data_FileExtractDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileExtractDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileExtractDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileExtractDlg.stringdata0))
        return static_cast<void*>(const_cast< FileExtractDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int FileExtractDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FileExtractDlg::Message(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
