#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>
#include <QTimer>
#include <QStringList>

class MusicController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList playlist READ playlist NOTIFY playlistChanged)
    Q_PROPERTY(QVariantList customPlaylists READ customPlaylists NOTIFY customPlaylistsChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)
    Q_PROPERTY(int currentSongIndex READ currentSongIndex WRITE setCurrentSongIndex NOTIFY currentSongIndexChanged)
    Q_PROPERTY(double songProgress READ songProgress WRITE setSongProgress NOTIFY songProgressChanged)
    Q_PROPERTY(bool isShuffle READ isShuffle WRITE setIsShuffle NOTIFY isShuffleChanged)
    Q_PROPERTY(bool isRepeat READ isRepeat WRITE setIsRepeat NOTIFY isRepeatChanged)
    Q_PROPERTY(bool hasStartedPlaying READ hasStartedPlaying NOTIFY hasStartedPlayingChanged)
    Q_PROPERTY(QVariantMap playingSongInfo READ playingSongInfo NOTIFY playingSongInfoChanged)

public:
    explicit MusicController(QObject *parent = nullptr);

    QVariantList playlist() const;
    QVariantList customPlaylists() const;
    bool isPlaying() const;
    int currentSongIndex() const;
    double songProgress() const;
    bool isShuffle() const;
    bool isRepeat() const;
    bool hasStartedPlaying() const;

    // ĐÂY LÀ DÒNG BỊ THIẾU MÌNH VỪA THÊM VÀO ĐỂ FIX LỖI
    QVariantMap playingSongInfo() const;

    void setIsPlaying(bool playing);
    void setCurrentSongIndex(int index);
    void setSongProgress(double progress);
    void setIsShuffle(bool shuffle);
    void setIsRepeat(bool repeat);

    Q_INVOKABLE void playSong(int index);
    Q_INVOKABLE void nextSong();
    Q_INVOKABLE void prevSong();
    Q_INVOKABLE void seek(int secondsOffset);
    Q_INVOKABLE void seekToProgress(double progress);

    Q_INVOKABLE void loadPlaylist(QString type);
    Q_INVOKABLE void loadPlayingPlaylist();
    Q_INVOKABLE void createCustomPlaylist(QString name);

    Q_INVOKABLE void addSong(QString title, QString artist, QString duration);
    Q_INVOKABLE void addSongToCustomPlaylist(int songIndex, int targetPlaylistIndex);
    Q_INVOKABLE void editSong(int index, QString title, QString artist);
    Q_INVOKABLE void deleteSong(int index);
    Q_INVOKABLE void toggleFavorite(int index);

    Q_INVOKABLE int timeToSeconds(QString timeStr);
    Q_INVOKABLE QString formatTime(int totalSeconds);

signals:
    void playlistChanged();
    void customPlaylistsChanged();
    void isPlayingChanged();
    void currentSongIndexChanged();
    void songProgressChanged();
    void isShuffleChanged();
    void isRepeatChanged();
    void hasStartedPlayingChanged();
    void showNotification(QString message);
    void playingSongInfoChanged();
    void requestCommandESP(QString cmd);

private slots:
    void onTimerTick();

private:
    QVariantList m_playlist;
    QVariantList m_usbPlaylist;
    QVariantList m_favPlaylist;
    QVariantList m_recentPlaylist;

    QList<QVariantList> m_allCustomPlaylists;
    QVariantList m_customPlaylistsInfo;

    QString m_currentPlaylistType;
    QString m_playingPlaylistType;

    bool m_isPlaying;
    int m_currentSongIndex;
    double m_songProgress;
    bool m_isShuffle;
    bool m_isRepeat;
    bool m_hasStartedPlaying;

    int m_currentSongDuration;

    QTimer *m_timer;

    void loadInitialData();
    void updatePlaylistState();
    void syncActivePlaylist();
};

#endif