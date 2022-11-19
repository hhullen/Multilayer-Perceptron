/****************************************************************************
** Meta object code from reading C++ file 'testing.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/MLP/View_module/testing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__Testing_t {
    const uint offsetsAndSize[14];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__Testing_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__Testing_t qt_meta_stringdata_s21__Testing = {
    {
QT_MOC_LITERAL(0, 12), // "s21::Testing"
QT_MOC_LITERAL(13, 10), // "BackSignal"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 9), // "RunSignal"
QT_MOC_LITERAL(35, 15), // "TerminateSignal"
QT_MOC_LITERAL(51, 17), // "SentMessageSignal"
QT_MOC_LITERAL(69, 7) // "message"

    },
    "s21::Testing\0BackSignal\0\0RunSignal\0"
    "TerminateSignal\0SentMessageSignal\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__Testing[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,
       3,    0,   39,    2, 0x06,    2 /* Public */,
       4,    0,   40,    2, 0x06,    3 /* Public */,
       5,    1,   41,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void s21::Testing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Testing *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->BackSignal(); break;
        case 1: _t->RunSignal(); break;
        case 2: _t->TerminateSignal(); break;
        case 3: _t->SentMessageSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Testing::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Testing::BackSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Testing::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Testing::RunSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Testing::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Testing::TerminateSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Testing::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Testing::SentMessageSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject s21::Testing::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__Testing.offsetsAndSize,
    qt_meta_data_s21__Testing,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__Testing_t
, QtPrivate::TypeAndForceComplete<Testing, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>



>,
    nullptr
} };


const QMetaObject *s21::Testing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::Testing::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__Testing.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::Testing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void s21::Testing::BackSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void s21::Testing::RunSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void s21::Testing::TerminateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void s21::Testing::SentMessageSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
