/****************************************************************************
** Meta object code from reading C++ file 'classifier.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/MLP/View_module/classifier.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__Classifier_t {
    const uint offsetsAndSize[12];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__Classifier_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__Classifier_t qt_meta_stringdata_s21__Classifier = {
    {
QT_MOC_LITERAL(0, 15), // "s21::Classifier"
QT_MOC_LITERAL(16, 10), // "BackSignal"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 11), // "SentMessage"
QT_MOC_LITERAL(40, 7), // "message"
QT_MOC_LITERAL(48, 11) // "ReadySignal"

    },
    "s21::Classifier\0BackSignal\0\0SentMessage\0"
    "message\0ReadySignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__Classifier[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    1,   33,    2, 0x06,    2 /* Public */,
       5,    0,   36,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

       0        // eod
};

void s21::Classifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Classifier *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->BackSignal(); break;
        case 1: _t->SentMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ReadySignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Classifier::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Classifier::BackSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Classifier::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Classifier::SentMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Classifier::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Classifier::ReadySignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject s21::Classifier::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__Classifier.offsetsAndSize,
    qt_meta_data_s21__Classifier,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__Classifier_t
, QtPrivate::TypeAndForceComplete<Classifier, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *s21::Classifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::Classifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__Classifier.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::Classifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void s21::Classifier::BackSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void s21::Classifier::SentMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void s21::Classifier::ReadySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
