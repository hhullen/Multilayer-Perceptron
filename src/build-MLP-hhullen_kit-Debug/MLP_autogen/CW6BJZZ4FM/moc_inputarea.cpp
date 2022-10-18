/****************************************************************************
** Meta object code from reading C++ file 'inputarea.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MLP/View_module/inputarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__InputArea_t {
    const uint offsetsAndSize[16];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__InputArea_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__InputArea_t qt_meta_stringdata_s21__InputArea = {
    {
QT_MOC_LITERAL(0, 14), // "s21::InputArea"
QT_MOC_LITERAL(15, 10), // "line_ended"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 15), // "mousePressEvent"
QT_MOC_LITERAL(43, 25), // "QGraphicsSceneMouseEvent*"
QT_MOC_LITERAL(69, 5), // "event"
QT_MOC_LITERAL(75, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(93, 14) // "mouseMoveEvent"

    },
    "s21::InputArea\0line_ended\0\0mousePressEvent\0"
    "QGraphicsSceneMouseEvent*\0event\0"
    "mouseReleaseEvent\0mouseMoveEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__InputArea[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   39,    2, 0x08,    2 /* Private */,
       6,    1,   42,    2, 0x08,    4 /* Private */,
       7,    1,   45,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void s21::InputArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InputArea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->line_ended(); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseMoveEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputArea::line_ended)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject s21::InputArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_s21__InputArea.offsetsAndSize,
    qt_meta_data_s21__InputArea,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__InputArea_t
, QtPrivate::TypeAndForceComplete<InputArea, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::InputArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::InputArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__InputArea.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int s21::InputArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void s21::InputArea::line_ended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
