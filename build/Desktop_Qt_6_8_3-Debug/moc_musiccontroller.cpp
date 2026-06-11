/****************************************************************************
** Meta object code from reading C++ file 'musiccontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../musiccontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musiccontroller.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15MusicControllerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN15MusicControllerE = QtMocHelpers::stringData(
    "MusicController",
    "playlistChanged",
    "",
    "customPlaylistsChanged",
    "isPlayingChanged",
    "currentSongIndexChanged",
    "songProgressChanged",
    "isShuffleChanged",
    "isRepeatChanged",
    "hasStartedPlayingChanged",
    "showNotification",
    "message",
    "playingSongInfoChanged",
    "requestCommandESP",
    "cmd",
    "onTimerTick",
    "playSong",
    "index",
    "nextSong",
    "prevSong",
    "seek",
    "secondsOffset",
    "seekToProgress",
    "progress",
    "loadPlaylist",
    "type",
    "loadPlayingPlaylist",
    "createCustomPlaylist",
    "name",
    "addSong",
    "title",
    "artist",
    "duration",
    "addSongToCustomPlaylist",
    "songIndex",
    "targetPlaylistIndex",
    "editSong",
    "deleteSong",
    "toggleFavorite",
    "timeToSeconds",
    "timeStr",
    "formatTime",
    "totalSeconds",
    "playlist",
    "QVariantList",
    "customPlaylists",
    "isPlaying",
    "currentSongIndex",
    "songProgress",
    "isShuffle",
    "isRepeat",
    "hasStartedPlaying",
    "playingSongInfo",
    "QVariantMap"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN15MusicControllerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       9,  241, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  176,    2, 0x06,   10 /* Public */,
       3,    0,  177,    2, 0x06,   11 /* Public */,
       4,    0,  178,    2, 0x06,   12 /* Public */,
       5,    0,  179,    2, 0x06,   13 /* Public */,
       6,    0,  180,    2, 0x06,   14 /* Public */,
       7,    0,  181,    2, 0x06,   15 /* Public */,
       8,    0,  182,    2, 0x06,   16 /* Public */,
       9,    0,  183,    2, 0x06,   17 /* Public */,
      10,    1,  184,    2, 0x06,   18 /* Public */,
      12,    0,  187,    2, 0x06,   20 /* Public */,
      13,    1,  188,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  191,    2, 0x08,   23 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,  192,    2, 0x02,   24 /* Public */,
      18,    0,  195,    2, 0x02,   26 /* Public */,
      19,    0,  196,    2, 0x02,   27 /* Public */,
      20,    1,  197,    2, 0x02,   28 /* Public */,
      22,    1,  200,    2, 0x02,   30 /* Public */,
      24,    1,  203,    2, 0x02,   32 /* Public */,
      26,    0,  206,    2, 0x02,   34 /* Public */,
      27,    1,  207,    2, 0x02,   35 /* Public */,
      29,    3,  210,    2, 0x02,   37 /* Public */,
      33,    2,  217,    2, 0x02,   41 /* Public */,
      36,    3,  222,    2, 0x02,   44 /* Public */,
      37,    1,  229,    2, 0x02,   48 /* Public */,
      38,    1,  232,    2, 0x02,   50 /* Public */,
      39,    1,  235,    2, 0x02,   52 /* Public */,
      41,    1,  238,    2, 0x02,   54 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   30,   31,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   17,   30,   31,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Int, QMetaType::QString,   40,
    QMetaType::QString, QMetaType::Int,   42,

 // properties: name, type, flags, notifyId, revision
      43, 0x80000000 | 44, 0x00015009, uint(0), 0,
      45, 0x80000000 | 44, 0x00015009, uint(1), 0,
      46, QMetaType::Bool, 0x00015103, uint(2), 0,
      47, QMetaType::Int, 0x00015103, uint(3), 0,
      48, QMetaType::Double, 0x00015103, uint(4), 0,
      49, QMetaType::Bool, 0x00015103, uint(5), 0,
      50, QMetaType::Bool, 0x00015103, uint(6), 0,
      51, QMetaType::Bool, 0x00015001, uint(7), 0,
      52, 0x80000000 | 53, 0x00015009, uint(9), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN15MusicControllerE.offsetsAndSizes,
    qt_meta_data_ZN15MusicControllerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN15MusicControllerE_t,
        // property 'playlist'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'customPlaylists'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'isPlaying'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'currentSongIndex'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'songProgress'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'isShuffle'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'isRepeat'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'hasStartedPlaying'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'playingSongInfo'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicController, std::true_type>,
        // method 'playlistChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'customPlaylistsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isPlayingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentSongIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'songProgressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isShuffleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isRepeatChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hasStartedPlayingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'playingSongInfoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestCommandESP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onTimerTick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'nextSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prevSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'seek'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'seekToProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'loadPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'loadPlayingPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createCustomPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addSongToCustomPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'deleteSong'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'toggleFavorite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'timeToSeconds'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'formatTime'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MusicController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MusicController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->playlistChanged(); break;
        case 1: _t->customPlaylistsChanged(); break;
        case 2: _t->isPlayingChanged(); break;
        case 3: _t->currentSongIndexChanged(); break;
        case 4: _t->songProgressChanged(); break;
        case 5: _t->isShuffleChanged(); break;
        case 6: _t->isRepeatChanged(); break;
        case 7: _t->hasStartedPlayingChanged(); break;
        case 8: _t->showNotification((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->playingSongInfoChanged(); break;
        case 10: _t->requestCommandESP((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->onTimerTick(); break;
        case 12: _t->playSong((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->nextSong(); break;
        case 14: _t->prevSong(); break;
        case 15: _t->seek((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->seekToProgress((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 17: _t->loadPlaylist((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->loadPlayingPlaylist(); break;
        case 19: _t->createCustomPlaylist((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->addSong((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 21: _t->addSongToCustomPlaylist((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 22: _t->editSong((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 23: _t->deleteSong((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->toggleFavorite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: { int _r = _t->timeToSeconds((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->formatTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::playlistChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::customPlaylistsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::isPlayingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::currentSongIndexChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::songProgressChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::isShuffleChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::isRepeatChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::hasStartedPlayingChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)(QString );
            if (_q_method_type _q_method = &MusicController::showNotification; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)();
            if (_q_method_type _q_method = &MusicController::playingSongInfoChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (MusicController::*)(QString );
            if (_q_method_type _q_method = &MusicController::requestCommandESP; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->playlist(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->customPlaylists(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isPlaying(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->currentSongIndex(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->songProgress(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->isShuffle(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isRepeat(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->hasStartedPlaying(); break;
        case 8: *reinterpret_cast< QVariantMap*>(_v) = _t->playingSongInfo(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setIsPlaying(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setCurrentSongIndex(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setSongProgress(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setIsShuffle(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setIsRepeat(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *MusicController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN15MusicControllerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
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
void MusicController::playlistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicController::customPlaylistsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicController::isPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicController::currentSongIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MusicController::songProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MusicController::isShuffleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MusicController::isRepeatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MusicController::hasStartedPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MusicController::showNotification(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MusicController::playingSongInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MusicController::requestCommandESP(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
