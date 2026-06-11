#include "musiccontroller.h"
#include <QRandomGenerator>

MusicController::MusicController(QObject *parent)
    : QObject(parent),
    m_playingPlaylistType(""),
    m_isPlaying(false),
    m_currentSongIndex(0),
    m_songProgress(0.0),
    m_isShuffle(false),
    m_isRepeat(false),
    m_hasStartedPlaying(false),
    m_currentSongDuration(0)
{
    loadInitialData();
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MusicController::onTimerTick);
}

void MusicController::loadInitialData()
{
    m_usbPlaylist.clear();
    m_favPlaylist.clear();
    m_recentPlaylist.clear();
    m_allCustomPlaylists.clear();
    m_customPlaylistsInfo.clear();

    int indexCounter = 0;

    auto createSong = [&indexCounter](QString title, QString artist, QString duration) -> QVariantMap {
        QVariantMap song;
        song["title"] = title;
        song["artist"] = artist;
        song["duration"] = duration;
        song["isPlaying"] = false;
        song["isFavorite"] = false;

        song["originalIndex"] = indexCounter++;
        return song;
    };
    m_usbPlaylist.append(createSong("Đừng làm trái tim anh đau", "Sơn Tùng M-TP", "5:25"));
    m_usbPlaylist.append(createSong("Nơi này có anh", "Sơn Tùng M-TP", "4:18"));
    m_usbPlaylist.append(createSong("Sugar", "Maroon 5", "5:01"));
    m_usbPlaylist.append(createSong("Gió đêm qua đường", "Chu Thúy Quỳnh", "4:16"));
    m_usbPlaylist.append(createSong("Pen Pineapple Apple Pen", "Pikotaro", "2:33"));
    m_usbPlaylist.append(createSong("Baby", "Justin Bieber", "4:00"));
    m_usbPlaylist.append(createSong("50 năm về sau", "Đặng Thanh Tuyền", "4:59"));
    m_usbPlaylist.append(createSong("Cho con", "BRay", "2:17"));
    m_usbPlaylist.append(createSong("Mất kết nối", "Dương Domic", "3:27"));
    m_usbPlaylist.append(createSong("Phép màu", "Nguyễn Hùng", "4:16"));

    loadPlaylist("all");
}

void MusicController::loadPlaylist(QString type)
{
    m_currentPlaylistType = type;
    if (type == "usb" || type == "all") m_playlist = m_usbPlaylist;
    else if (type == "favorite") m_playlist = m_favPlaylist;
    else if (type == "recent") m_playlist = m_recentPlaylist;
    else if (type.startsWith("custom_")) {
        int index = type.split("_")[1].toInt();
        if (index >= 0 && index < m_allCustomPlaylists.size()) m_playlist = m_allCustomPlaylists[index];
        else m_playlist.clear();
    } else m_playlist.clear();

    updatePlaylistState();
}

void MusicController::loadPlayingPlaylist()
{
    if (!m_playingPlaylistType.isEmpty() && m_currentPlaylistType != m_playingPlaylistType) {
        loadPlaylist(m_playingPlaylistType);
    }
}

void MusicController::syncActivePlaylist()
{
    if (m_currentPlaylistType == "usb" || m_currentPlaylistType == "all") m_usbPlaylist = m_playlist;
    else if (m_currentPlaylistType == "favorite") m_favPlaylist = m_playlist;
    else if (m_currentPlaylistType == "recent") m_recentPlaylist = m_playlist;
    else if (m_currentPlaylistType.startsWith("custom_")) {
        int index = m_currentPlaylistType.split("_")[1].toInt();
        if (index >= 0 && index < m_allCustomPlaylists.size()) m_allCustomPlaylists[index] = m_playlist;
    }
}

QVariantMap MusicController::playingSongInfo() const
{
    if (m_playingPlaylistType == "usb" || m_playingPlaylistType == "all") {
        if (m_currentSongIndex >= 0 && m_currentSongIndex < m_usbPlaylist.count()) return m_usbPlaylist[m_currentSongIndex].toMap();
    } else if (m_playingPlaylistType == "favorite") {
        if (m_currentSongIndex >= 0 && m_currentSongIndex < m_favPlaylist.count()) return m_favPlaylist[m_currentSongIndex].toMap();
    } else if (m_playingPlaylistType == "recent") {
        if (m_currentSongIndex >= 0 && m_currentSongIndex < m_recentPlaylist.count()) return m_recentPlaylist[m_currentSongIndex].toMap();
    } else if (m_playingPlaylistType.startsWith("custom_")) {
        int idx = m_playingPlaylistType.split("_")[1].toInt();
        if (idx >= 0 && idx < m_allCustomPlaylists.size()) {
            if (m_currentSongIndex >= 0 && m_currentSongIndex < m_allCustomPlaylists[idx].count()) return m_allCustomPlaylists[idx][m_currentSongIndex].toMap();
        }
    }
    return QVariantMap();
}

void MusicController::createCustomPlaylist(QString name)
{
    QVariantMap info;
    info["name"] = name;
    m_customPlaylistsInfo.append(info);
    m_allCustomPlaylists.append(QVariantList());
    emit customPlaylistsChanged();
    emit showNotification("Đã tạo Playlist: " + name);
}

void MusicController::toggleFavorite(int index)
{
    if (index >= 0 && index < m_playlist.count()) {
        QVariantMap song = m_playlist[index].toMap();
        bool isFav = !song["isFavorite"].toBool();
        song["isFavorite"] = isFav;

        QString title = song["title"].toString();
        QString artist = song["artist"].toString();

        m_playlist[index] = song;

        if (m_currentPlaylistType == "usb" || m_currentPlaylistType == "all") m_usbPlaylist = m_playlist;
        else if (m_currentPlaylistType == "recent") m_recentPlaylist = m_playlist;
        else if (m_currentPlaylistType.startsWith("custom_")) {
            int idx = m_currentPlaylistType.split("_")[1].toInt();
            m_allCustomPlaylists[idx] = m_playlist;
        }

        for (int i = 0; i < m_usbPlaylist.count(); i++) {
            QVariantMap s = m_usbPlaylist[i].toMap();
            if (s["title"] == title && s["artist"] == artist) { s["isFavorite"] = isFav; m_usbPlaylist[i] = s; }
        }
        for (int i = 0; i < m_recentPlaylist.count(); i++) {
            QVariantMap s = m_recentPlaylist[i].toMap();
            if (s["title"] == title && s["artist"] == artist) { s["isFavorite"] = isFav; m_recentPlaylist[i] = s; }
        }
        for (int i = 0; i < m_allCustomPlaylists.size(); i++) {
            QVariantList cl = m_allCustomPlaylists[i];
            for (int j = 0; j < cl.count(); j++) {
                QVariantMap s = cl[j].toMap();
                if (s["title"] == title && s["artist"] == artist) { s["isFavorite"] = isFav; cl[j] = s; }
            }
            m_allCustomPlaylists[i] = cl;
        }

        if (isFav) {
            bool alreadyInFav = false;
            for (const QVariant& item : m_favPlaylist) {
                if (item.toMap()["title"] == title && item.toMap()["artist"] == artist) alreadyInFav = true;
            }
            if (!alreadyInFav) m_favPlaylist.append(song);
            emit showNotification("Đã thêm vào bài hát yêu thích");
        } else {
            for (int i = 0; i < m_favPlaylist.count(); ++i) {
                if (m_favPlaylist[i].toMap()["title"] == title && m_favPlaylist[i].toMap()["artist"] == artist) {
                    m_favPlaylist.removeAt(i);
                    break;
                }
            }
            emit showNotification("Đã xóa khỏi bài hát yêu thích");
        }

        emit playlistChanged();
        emit playingSongInfoChanged();
    }
}

void MusicController::addSong(QString title, QString artist, QString duration)
{
    QVariantMap newSong;
    newSong["title"] = title;
    newSong["artist"] = artist;
    newSong["duration"] = duration;
    newSong["isPlaying"] = false;
    newSong["isFavorite"] = false;
    newSong["originalIndex"] = m_usbPlaylist.count();
    m_playlist.append(newSong);
    syncActivePlaylist();
    emit playlistChanged();
    emit showNotification("Đã thêm bài hát mới");
}

void MusicController::addSongToCustomPlaylist(int songIndex, int targetPlaylistIndex)
{
    if (songIndex < 0 || songIndex >= m_playlist.count()) return;
    if (targetPlaylistIndex < 0 || targetPlaylistIndex >= m_allCustomPlaylists.size()) return;

    QVariantMap songToAdd = m_playlist[songIndex].toMap();
    QVariantList currentTargetList = m_allCustomPlaylists[targetPlaylistIndex];

    bool alreadyExists = false;
    for (const QVariant& item : currentTargetList) {
        if (item.toMap()["title"] == songToAdd["title"] && item.toMap()["artist"] == songToAdd["artist"]) {
            alreadyExists = true;
            break;
        }
    }

    if (!alreadyExists) {
        currentTargetList.append(songToAdd);
        m_allCustomPlaylists[targetPlaylistIndex] = currentTargetList;
        if (m_currentPlaylistType == "custom_" + QString::number(targetPlaylistIndex)) {
            m_playlist = currentTargetList;
            emit playlistChanged();
        }
        QString plName = m_customPlaylistsInfo[targetPlaylistIndex].toMap()["name"].toString();
        emit showNotification("Đã thêm vào " + plName);
    } else {
        emit showNotification("Bài hát đã có trong Playlist");
    }
}

void MusicController::editSong(int index, QString title, QString artist)
{
    if (index >= 0 && index < m_playlist.count()) {
        QVariantMap song = m_playlist[index].toMap();
        song["title"] = title;
        song["artist"] = artist;
        m_playlist[index] = song;
        syncActivePlaylist();
        emit playlistChanged();
        emit showNotification("Đã cập nhật thông tin");
        emit playingSongInfoChanged();
    }
}

void MusicController::deleteSong(int index)
{
    if (index >= 0 && index < m_playlist.count()) {
        bool isDeletingCurrent = (m_currentSongIndex == index);
        bool wasPlaying = m_isPlaying;
        m_playlist.removeAt(index);

        if (m_playlist.isEmpty()) {
            setIsPlaying(false);
            m_currentSongIndex = 0;
            m_songProgress = 0.0;
            emit currentSongIndexChanged();
            emit songProgressChanged();
        } else {
            if (isDeletingCurrent) {
                int nextIdx = (index >= m_playlist.count()) ? 0 : index;
                if (wasPlaying) playSong(nextIdx);
                else {
                    m_currentSongIndex = nextIdx;
                    m_songProgress = 0.0;
                    emit currentSongIndexChanged();
                    emit songProgressChanged();
                    updatePlaylistState();
                }
            } else if (m_currentSongIndex > index) {
                m_currentSongIndex--;
                emit currentSongIndexChanged();
                updatePlaylistState();
            } else {
                updatePlaylistState();
            }
        }
        syncActivePlaylist();
        emit playlistChanged();
        emit showNotification("Đã xóa khỏi danh sách");
        emit playingSongInfoChanged();
    }
}

void MusicController::playSong(int index)
{
    if (index < 0 || index >= m_playlist.count()) return;

    // 1. RÚT LẤY "CĂN CƯỚC CÔNG DÂN" (VỊ TRÍ GỐC) CỦA BÀI HÁT
    int originalIdx = m_playlist[index].toMap()["originalIndex"].toInt();

    // 2. ÉP GỬI LỆNH XUỐNG ESP32 BẰNG VỊ TRÍ GỐC NÀY
    QString cmd = QString("play_track:%1").arg(originalIdx + 1);
    emit requestCommandESP(cmd);

    m_currentSongIndex = index;
    m_songProgress = 0.0;
    m_isPlaying = true;
    m_currentSongDuration = timeToSeconds(m_playlist[index].toMap()["duration"].toString());

    // ĐÁNH DẤU CHÍNH XÁC DANH SÁCH ĐANG ĐƯỢC PHÁT
    m_playingPlaylistType = m_currentPlaylistType;

    QVariantMap playingSong = m_playlist[index].toMap();
    QString title = playingSong["title"].toString();
    QString artist = playingSong["artist"].toString();

    // Cập nhật Nghe gần đây (Recent Playlist)
    for (int i = 0; i < m_recentPlaylist.count(); ++i) {
        if (m_recentPlaylist[i].toMap()["title"] == title && m_recentPlaylist[i].toMap()["artist"] == artist) {
            m_recentPlaylist.removeAt(i);
            break;
        }
    }
    m_recentPlaylist.insert(0, playingSong);

    if (!m_hasStartedPlaying) {
        m_hasStartedPlaying = true;
        emit hasStartedPlayingChanged();
    }

    updatePlaylistState();
    m_timer->start(1000);

    emit currentSongIndexChanged();
    emit songProgressChanged();
    emit isPlayingChanged();
    emit playingSongInfoChanged();
}

void MusicController::nextSong()
{
    if (m_playlist.isEmpty()) { setIsPlaying(false); return; }

    if (m_isRepeat) playSong(m_currentSongIndex);
    else if (m_isShuffle) {
        // NẾU ĐANG BẬT SHUFFLE
        int nextIdx = m_currentSongIndex;
        if (m_playlist.count() > 1) {
            // "Lắc xí ngầu" liên tục cho đến khi ra một bài khác với bài đang phát
            while (nextIdx == m_currentSongIndex)
                nextIdx = QRandomGenerator::global()->bounded(m_playlist.count());
        }
        // Phát bài ngẫu nhiên vừa bốc được (gọi play_track:X xuống ESP32)
        playSong(nextIdx);
    } else {
        // NẾU PHÁT THEO THỨ TỰ BÌNH THƯỜNG
        int nextIdx = (m_currentSongIndex + 1) % m_playlist.count();
        playSong(nextIdx);
    }
}

void MusicController::prevSong()
{
    // emit requestCommandESP("prev");
    if (m_playlist.isEmpty()) { setIsPlaying(false); return; }
    int prevIdx = m_currentSongIndex - 1;
    if (prevIdx < 0) prevIdx = m_playlist.count() - 1;
    playSong(prevIdx);
}

void MusicController::seek(int secondsOffset)
{
    if (!m_isPlaying || m_currentSongDuration <= 0) return;
    double newProgress = m_songProgress + ((double)secondsOffset / m_currentSongDuration);
    setSongProgress(qBound(0.0, newProgress, 1.0));
}

void MusicController::seekToProgress(double progress)
{
    setSongProgress(qBound(0.0, progress, 1.0));
}

void MusicController::onTimerTick()
{
    if (!m_isPlaying || m_currentSongDuration <= 0) return;

    m_songProgress += (1.0 / m_currentSongDuration);
    emit songProgressChanged();

    if (m_songProgress >= 1.0) nextSong();
}

void MusicController::updatePlaylistState()
{
    for (int i = 0; i < m_playlist.count(); i++) {
        QVariantMap song = m_playlist[i].toMap();
        song["isPlaying"] = (i == m_currentSongIndex);
        m_playlist[i] = song;
    }
    syncActivePlaylist();
    emit playlistChanged();
}

void MusicController::setIsPlaying(bool playing) {
    if (m_isPlaying != playing) {
        m_isPlaying = playing;
        if (m_isPlaying) {
            m_timer->start(1000);
            emit requestCommandESP("play");
        } else {
            m_timer->stop();
            emit requestCommandESP("pause");
        }
        emit isPlayingChanged();
    }
}

int MusicController::timeToSeconds(QString timeStr)
{
    QStringList parts = timeStr.split(":");
    if (parts.length() != 2) return 0;
    return parts[0].toInt() * 60 + parts[1].toInt();
}

QString MusicController::formatTime(int totalSeconds)
{
    int m = totalSeconds / 60;
    int s = totalSeconds % 60;
    return QString("%1:%2").arg(m).arg(s, 2, 10, QChar('0'));
}

QVariantList MusicController::playlist() const { return m_playlist; }
QVariantList MusicController::customPlaylists() const { return m_customPlaylistsInfo; }
bool MusicController::isPlaying() const { return m_isPlaying; }
bool MusicController::hasStartedPlaying() const { return m_hasStartedPlaying; }

int MusicController::currentSongIndex() const { return m_currentSongIndex; }
void MusicController::setCurrentSongIndex(int index) {
    if (m_currentSongIndex != index) {
        m_currentSongIndex = index;
        emit currentSongIndexChanged();
        emit playingSongInfoChanged();
    }
}
double MusicController::songProgress() const { return m_songProgress; }
void MusicController::setSongProgress(double progress) {
    if (m_songProgress != progress) {
        m_songProgress = progress;
        emit songProgressChanged();
    }
}
bool MusicController::isShuffle() const { return m_isShuffle; }
void MusicController::setIsShuffle(bool shuffle) {
    if (m_isShuffle != shuffle) {
        m_isShuffle = shuffle;
        emit isShuffleChanged();
    }
}
bool MusicController::isRepeat() const { return m_isRepeat; }
void MusicController::setIsRepeat(bool repeat) {
    if (m_isRepeat != repeat) {
        m_isRepeat = repeat;

        //  BÁO CHO ESP32 BIẾT
        if (m_isRepeat) emit requestCommandESP("repeat_on");
        else emit requestCommandESP("repeat_off");

        emit isRepeatChanged();
    }
}