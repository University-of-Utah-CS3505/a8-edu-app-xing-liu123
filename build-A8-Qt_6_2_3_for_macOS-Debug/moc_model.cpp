/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../A8/model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Model_t {
    const uint offsetsAndSize[38];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 5), // "Model"
QT_MOC_LITERAL(6, 10), // "setUpFish1"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 1), // "x"
QT_MOC_LITERAL(20, 1), // "y"
QT_MOC_LITERAL(22, 10), // "setUpFish2"
QT_MOC_LITERAL(33, 10), // "setUpFish3"
QT_MOC_LITERAL(44, 10), // "setUpSpear"
QT_MOC_LITERAL(55, 2), // "x1"
QT_MOC_LITERAL(58, 2), // "y1"
QT_MOC_LITERAL(61, 2), // "x2"
QT_MOC_LITERAL(64, 2), // "y2"
QT_MOC_LITERAL(67, 9), // "startTime"
QT_MOC_LITERAL(77, 10), // "setUpWorld"
QT_MOC_LITERAL(88, 11), // "updateFish1"
QT_MOC_LITERAL(100, 11), // "updateFish2"
QT_MOC_LITERAL(112, 11), // "updateFish3"
QT_MOC_LITERAL(124, 11), // "updateSpear"
QT_MOC_LITERAL(136, 10) // "startTimer"

    },
    "Model\0setUpFish1\0\0x\0y\0setUpFish2\0"
    "setUpFish3\0setUpSpear\0x1\0y1\0x2\0y2\0"
    "startTime\0setUpWorld\0updateFish1\0"
    "updateFish2\0updateFish3\0updateSpear\0"
    "startTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   80,    2, 0x06,    1 /* Public */,
       5,    2,   85,    2, 0x06,    4 /* Public */,
       6,    2,   90,    2, 0x06,    7 /* Public */,
       7,    4,   95,    2, 0x06,   10 /* Public */,
      12,    0,  104,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,  105,    2, 0x0a,   16 /* Public */,
      14,    0,  106,    2, 0x0a,   17 /* Public */,
      15,    0,  107,    2, 0x0a,   18 /* Public */,
      16,    0,  108,    2, 0x0a,   19 /* Public */,
      17,    0,  109,    2, 0x0a,   20 /* Public */,
      18,    0,  110,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setUpFish1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setUpFish2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setUpFish3((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->setUpSpear((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->startTime(); break;
        case 5: _t->setUpWorld(); break;
        case 6: _t->updateFish1(); break;
        case 7: _t->updateFish2(); break;
        case 8: _t->updateFish3(); break;
        case 9: _t->updateSpear(); break;
        case 10: _t->startTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::setUpFish1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::setUpFish2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::setUpFish3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::setUpSpear)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Model::startTime)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model.offsetsAndSize,
    qt_meta_data_Model,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Model_t
, QtPrivate::TypeAndForceComplete<Model, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Model::setUpFish1(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::setUpFish2(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::setUpFish3(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::setUpSpear(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::startTime()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
