/****************************************************************************
** Meta object code from reading C++ file 'dashboardcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dashboardcontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboardcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN19DashboardControllerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN19DashboardControllerE = QtMocHelpers::stringData(
    "DashboardController",
    "speedChanged",
    "",
    "tachoChanged",
    "speedAngleChanged",
    "tachoAngleChanged",
    "turnLeftChanged",
    "turnRightChanged",
    "hiBeamChanged",
    "fogLightChanged",
    "dimLightChanged",
    "setSpeed",
    "speed",
    "setTacho",
    "tacho",
    "setTurnLeft",
    "turnLeft",
    "setTurnRight",
    "turnRight",
    "setHiBeam",
    "hiBeam",
    "setFogLight",
    "fogLight",
    "setDimLight",
    "dimLight",
    "sendCommandToESP",
    "cmd",
    "readSerialData",
    "speedAngle",
    "tachoAngle"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN19DashboardControllerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       9,  156, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x06,   10 /* Public */,
       3,    0,  123,    2, 0x06,   11 /* Public */,
       4,    0,  124,    2, 0x06,   12 /* Public */,
       5,    0,  125,    2, 0x06,   13 /* Public */,
       6,    0,  126,    2, 0x06,   14 /* Public */,
       7,    0,  127,    2, 0x06,   15 /* Public */,
       8,    0,  128,    2, 0x06,   16 /* Public */,
       9,    0,  129,    2, 0x06,   17 /* Public */,
      10,    0,  130,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  131,    2, 0x0a,   19 /* Public */,
      13,    1,  134,    2, 0x0a,   21 /* Public */,
      15,    1,  137,    2, 0x0a,   23 /* Public */,
      17,    1,  140,    2, 0x0a,   25 /* Public */,
      19,    1,  143,    2, 0x0a,   27 /* Public */,
      21,    1,  146,    2, 0x0a,   29 /* Public */,
      23,    1,  149,    2, 0x0a,   31 /* Public */,
      25,    1,  152,    2, 0x0a,   33 /* Public */,
      27,    0,  155,    2, 0x08,   35 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      12, QMetaType::Int, 0x00015103, uint(0), 0,
      14, QMetaType::Int, 0x00015103, uint(1), 0,
      28, QMetaType::Double, 0x00015001, uint(2), 0,
      29, QMetaType::Double, 0x00015001, uint(3), 0,
      16, QMetaType::Bool, 0x00015103, uint(4), 0,
      18, QMetaType::Bool, 0x00015103, uint(5), 0,
      20, QMetaType::Bool, 0x00015103, uint(6), 0,
      22, QMetaType::Bool, 0x00015103, uint(7), 0,
      24, QMetaType::Bool, 0x00015103, uint(8), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject DashboardController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN19DashboardControllerE.offsetsAndSizes,
    qt_meta_data_ZN19DashboardControllerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN19DashboardControllerE_t,
        // property 'speed'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'tacho'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'speedAngle'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'tachoAngle'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'turnLeft'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'turnRight'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'hiBeam'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'fogLight'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'dimLight'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DashboardController, std::true_type>,
        // method 'speedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tachoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'speedAngleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tachoAngleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'turnLeftChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'turnRightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hiBeamChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fogLightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dimLightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setTacho'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setTurnLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setTurnRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setHiBeam'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setFogLight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setDimLight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendCommandToESP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DashboardController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DashboardController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->tachoChanged(); break;
        case 2: _t->speedAngleChanged(); break;
        case 3: _t->tachoAngleChanged(); break;
        case 4: _t->turnLeftChanged(); break;
        case 5: _t->turnRightChanged(); break;
        case 6: _t->hiBeamChanged(); break;
        case 7: _t->fogLightChanged(); break;
        case 8: _t->dimLightChanged(); break;
        case 9: _t->setSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setTacho((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setTurnLeft((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setTurnRight((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->setHiBeam((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setFogLight((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->setDimLight((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->sendCommandToESP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->readSerialData(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::speedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::tachoChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::speedAngleChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::tachoAngleChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::turnLeftChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::turnRightChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::hiBeamChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::fogLightChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (DashboardController::*)();
            if (_q_method_type _q_method = &DashboardController::dimLightChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->tacho(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->speedAngle(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->tachoAngle(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->turnLeft(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->turnRight(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->hiBeam(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->fogLight(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->dimLight(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setTacho(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setTurnLeft(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setTurnRight(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setHiBeam(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setFogLight(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setDimLight(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *DashboardController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashboardController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN19DashboardControllerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DashboardController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DashboardController::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DashboardController::tachoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DashboardController::speedAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DashboardController::tachoAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DashboardController::turnLeftChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DashboardController::turnRightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DashboardController::hiBeamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DashboardController::fogLightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void DashboardController::dimLightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
