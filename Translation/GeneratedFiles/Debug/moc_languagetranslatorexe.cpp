/****************************************************************************
** Meta object code from reading C++ file 'languagetranslatorexe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../languagetranslatorexe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'languagetranslatorexe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LanguageTranslatorExe_t {
    QByteArrayData data[12];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageTranslatorExe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageTranslatorExe_t qt_meta_stringdata_LanguageTranslatorExe = {
    {
QT_MOC_LITERAL(0, 0, 21), // "LanguageTranslatorExe"
QT_MOC_LITERAL(1, 22, 24), // "on_toolbtn_excel_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 21), // "on_toolbtn_qt_clicked"
QT_MOC_LITERAL(4, 70, 21), // "on_toobtn_qml_clicked"
QT_MOC_LITERAL(5, 92, 39), // "on_listWidget_select_currentT..."
QT_MOC_LITERAL(6, 132, 11), // "currentText"
QT_MOC_LITERAL(7, 144, 25), // "on_pushbtn_Cancle_clicked"
QT_MOC_LITERAL(8, 170, 21), // "on_pushbtn_Ok_clicked"
QT_MOC_LITERAL(9, 192, 23), // "on_toobtn_qml_2_clicked"
QT_MOC_LITERAL(10, 216, 29), // "on_listWidget_receive_clicked"
QT_MOC_LITERAL(11, 246, 5) // "index"

    },
    "LanguageTranslatorExe\0on_toolbtn_excel_clicked\0"
    "\0on_toolbtn_qt_clicked\0on_toobtn_qml_clicked\0"
    "on_listWidget_select_currentTextChanged\0"
    "currentText\0on_pushbtn_Cancle_clicked\0"
    "on_pushbtn_Ok_clicked\0on_toobtn_qml_2_clicked\0"
    "on_listWidget_receive_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageTranslatorExe[] = {

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
    QMetaType::Void, QMetaType::QModelIndex,   11,

       0        // eod
};

void LanguageTranslatorExe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LanguageTranslatorExe *_t = static_cast<LanguageTranslatorExe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolbtn_excel_clicked(); break;
        case 1: _t->on_toolbtn_qt_clicked(); break;
        case 2: _t->on_toobtn_qml_clicked(); break;
        case 3: _t->on_listWidget_select_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pushbtn_Cancle_clicked(); break;
        case 5: _t->on_pushbtn_Ok_clicked(); break;
        case 6: _t->on_toobtn_qml_2_clicked(); break;
        case 7: _t->on_listWidget_receive_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LanguageTranslatorExe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LanguageTranslatorExe.data,
      qt_meta_data_LanguageTranslatorExe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageTranslatorExe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageTranslatorExe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageTranslatorExe.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LanguageTranslatorExe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
