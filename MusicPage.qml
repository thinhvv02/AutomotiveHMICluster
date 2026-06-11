import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 40
        spacing: 30

        Column {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            // Khu vực đĩa nhạc xoay
            Item {
                width: 260
                height: 260
                anchors.horizontalCenter: parent.horizontalCenter

                Rectangle {
                    anchors.centerIn: parent
                    width: 280
                    height: 280
                    radius: 140
                    color: "#a855f7"
                    opacity: 0.2
                }

                Rectangle {
                    id: albumArt
                    anchors.fill: parent
                    radius: 130
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#a855f7" }
                        GradientStop { position: 1.0; color: "#f97316" }
                    }

                    Image {
                        source: "qrc:/image_icons/music.png"
                        width: 60
                        height: 60
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                    }

                    RotationAnimator on rotation {
                        loops: Animation.Infinite
                        from: 0
                        to: 360
                        duration: 10000
                        running: MusicApp.isPlaying
                    }
                }
            }

            // Tên bài hát & Ca sĩ
            Column {
                spacing: 8
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    text: MusicApp.playlist.length > 0 ? MusicApp.playlist[MusicApp.currentSongIndex].title : "Chưa có dữ liệu"
                    color: "white"
                    font.pixelSize: 22
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    text: MusicApp.playlist.length > 0 ? MusicApp.playlist[MusicApp.currentSongIndex].artist : ""
                    color: "#94a3b8"
                    font.pixelSize: 16
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            // ==========================================
            // THANH TIẾN TRÌNH (ĐÃ FIX HIỂN THỊ TRỞ LẠI)
            // ==========================================
            RowLayout {
                width: 500 // KHÔI PHỤC WIDTH CỐ ĐỊNH 500
                anchors.horizontalCenter: parent.horizontalCenter // KHÔI PHỤC ANCHORS
                spacing: 15

                Text {
                    text: MusicApp.playlist.length > 0 ? MusicApp.formatTime(MusicApp.timeToSeconds(MusicApp.playlist[MusicApp.currentSongIndex].duration) * MusicApp.songProgress) : "0:00"
                    color: "#94a3b8"
                    font.pixelSize: 13
                    Layout.preferredWidth: 35
                    horizontalAlignment: Text.AlignRight
                    Layout.alignment: Qt.AlignVCenter
                }

                Item {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 12
                    Layout.alignment: Qt.AlignVCenter

                    Rectangle {
                        id: progressBarTrack
                        anchors.centerIn: parent
                        width: parent.width
                        height: progressMouseArea.containsMouse ? 10 : 6
                        radius: progressMouseArea.containsMouse ? 5 : 3
                        color: "#1e293b"

                        Behavior on height { NumberAnimation { duration: 150 } }
                        Behavior on radius { NumberAnimation { duration: 150 } }

                        Rectangle {
                            width: parent.width * MusicApp.songProgress
                            height: parent.height
                            radius: parent.radius
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: "#a855f7" }
                                GradientStop { position: 1.0; color: "#ec4899" }
                            }
                            Behavior on width { NumberAnimation { duration: 50 } }
                        }

                        MouseArea {
                            id: progressMouseArea
                            anchors.fill: parent
                            anchors.margins: -5
                            hoverEnabled: true
                            onClicked: {
                                var newProgress = mouse.x / width
                                MusicApp.seekToProgress(Math.min(Math.max(newProgress, 0), 1))
                            }
                            onPositionChanged: {
                                if (pressed) {
                                    var dragProgress = mouse.x / width
                                    MusicApp.seekToProgress(Math.min(Math.max(dragProgress, 0), 1))
                                }
                            }
                        }
                    }
                }

                Text {
                    text: MusicApp.playlist.length > 0 ? MusicApp.playlist[MusicApp.currentSongIndex].duration : "0:00"
                    color: "#94a3b8"
                    font.pixelSize: 13
                    Layout.preferredWidth: 35
                    Layout.alignment: Qt.AlignVCenter
                }
            }

            // 7 Nút Điều Khiển
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 15

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: MusicApp.isShuffle ? "#a855f7" : (mouseShuffle.containsMouse ? "#2a324a" : "#161b26")
                    scale: mouseShuffle.pressed ? 0.9 : 1.0
                    Behavior on color { ColorAnimation { duration: 150 } }
                    Behavior on scale { NumberAnimation { duration: 100 } }

                    Image {
                        source: "qrc:/image_icons/shuffle.png"
                        width: 22
                        height: 22
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        opacity: MusicApp.isShuffle ? 1.0 : 0.6
                    }
                    MouseArea {
                        id: mouseShuffle
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            MusicApp.isShuffle = !MusicApp.isShuffle
                            if (MusicApp.isShuffle) MusicApp.isRepeat = false
                        }
                    }
                }

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: mousePrev.containsMouse ? "#2a324a" : "#161b26"
                    scale: mousePrev.pressed ? 0.9 : 1.0

                    Image { source: "qrc:/image_icons/previous.png"; width: 22; height: 22; fillMode: Image.PreserveAspectFit; anchors.centerIn: parent }
                    MouseArea { id: mousePrev; anchors.fill: parent; hoverEnabled: true; onClicked: MusicApp.prevSong() }
                }

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: mouseRewind.containsMouse ? "#2a324a" : "#161b26"
                    scale: mouseRewind.pressed ? 0.9 : 1.0

                    Image { source: "qrc:/image_icons/backward.png"; width: 22; height: 22; fillMode: Image.PreserveAspectFit; anchors.centerIn: parent }
                    MouseArea { id: mouseRewind; anchors.fill: parent; hoverEnabled: true; onClicked: MusicApp.seek(-10) }
                }

                Item {
                    width: 70
                    height: 70
                    scale: mousePlay.pressed ? 0.9 : 1.0

                    Rectangle { anchors.centerIn: parent; width: 85; height: 85; radius: 42.5; color: "#c084fc"; opacity: 0.2 }
                    Rectangle {
                        anchors.fill: parent
                        radius: 35
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: mousePlay.containsMouse ? "#d8b4fe" : "#c084fc" }
                            GradientStop { position: 1.0; color: mousePlay.containsMouse ? "#f17eb8" : "#db2777" }
                        }
                        Image {
                            source: MusicApp.isPlaying ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"
                            width: 30
                            height: 30
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn: parent
                        }
                        MouseArea { id: mousePlay; anchors.fill: parent; hoverEnabled: true; onClicked: MusicApp.isPlaying = !MusicApp.isPlaying }
                    }
                }

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: mouseForward.containsMouse ? "#2a324a" : "#161b26"
                    scale: mouseForward.pressed ? 0.9 : 1.0

                    Image { source: "qrc:/image_icons/forward.png"; width: 22; height: 22; fillMode: Image.PreserveAspectFit; anchors.centerIn: parent }
                    MouseArea { id: mouseForward; anchors.fill: parent; hoverEnabled: true; onClicked: MusicApp.seek(10) }
                }

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: mouseNext.containsMouse ? "#2a324a" : "#161b26"
                    scale: mouseNext.pressed ? 0.9 : 1.0

                    Image { source: "qrc:/image_icons/next.png"; width: 22; height: 22; fillMode: Image.PreserveAspectFit; anchors.centerIn: parent }
                    MouseArea { id: mouseNext; anchors.fill: parent; hoverEnabled: true; onClicked: MusicApp.nextSong() }
                }

                Rectangle {
                    width: 50
                    height: 50
                    radius: 25
                    color: MusicApp.isRepeat ? "#a855f7" : (mouseRepeat.containsMouse ? "#2a324a" : "#161b26")
                    scale: mouseRepeat.pressed ? 0.9 : 1.0

                    Image {
                        source: "qrc:/image_icons/repeat.png"
                        width: 22
                        height: 22
                        fillMode: Image.PreserveAspectFit
                        anchors.centerIn: parent
                        opacity: MusicApp.isRepeat ? 1.0 : 0.6
                    }
                    MouseArea {
                        id: mouseRepeat
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            MusicApp.isRepeat = !MusicApp.isRepeat
                            if (MusicApp.isRepeat) MusicApp.isShuffle = false
                        }
                    }
                }
            }
        }

        // ==========================================
        // DANH SÁCH PHÁT (UI C++ Model)
        // ==========================================
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 15

            RowLayout {
                Layout.fillWidth: true
                Text {
                    text: "Danh sách phát"
                    color: "white"
                    font.pixelSize: 20
                    font.bold: true
                    Layout.fillWidth: true
                }

                Item {
                    width: 30
                    height: 30
                    Image {
                        source: "qrc:/image_icons/add.png"
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: MusicApp.addSong("Bài hát mới", "Nghệ sĩ chưa biết", "4:00")
                    }
                }
            }

            ListView {
                id: playlistView
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: MusicApp.playlist
                clip: true
                spacing: 8

                delegate: Rectangle {
                    width: playlistView.width
                    height: 75
                    radius: 15
                    color: modelData.isPlaying ? "#22173f" : "transparent"
                    border.color: modelData.isPlaying ? "#3b2260" : "transparent"
                    border.width: 1

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 15

                        // Thay thế Text bằng Icon Play/Pause
                        Item {
                            Layout.preferredWidth: 24
                            Layout.preferredHeight: 24
                            Layout.alignment: Qt.AlignVCenter

                            Image {
                                id: rowPlayIcon
                                anchors.fill: parent
                                // Logic kết hợp: Đúng bài đang chọn VÀ nhạc đang chạy thì hiện Pause, ngược lại hiện Play
                                source: (modelData.isPlaying && MusicApp.isPlaying) ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"
                                fillMode: Image.PreserveAspectFit
                                // Làm mờ nhẹ icon của các bài chưa phát để nổi bật bài đang phát
                                opacity: modelData.isPlaying ? 1.0 : 0.4

                                Behavior on opacity { NumberAnimation { duration: 150 } }
                            }

                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                // Hiệu ứng sáng icon khi di chuột vào
                                onEntered: rowPlayIcon.opacity = 1.0
                                onExited: rowPlayIcon.opacity = modelData.isPlaying ? 1.0 : 0.4

                                onClicked: {
                                    if (modelData.isPlaying) {
                                        // Nếu bấm vào đúng bài đang phát -> Tạm dừng / Phát tiếp
                                        MusicApp.isPlaying = !MusicApp.isPlaying
                                    } else {
                                        // Nếu bấm vào icon của bài khác -> Chuyển sang phát bài đó
                                        MusicApp.playSong(index)
                                    }
                                }
                            }
                        }

                        Column {
                            Layout.fillWidth: true
                            spacing: 5
                            Text { text: modelData.title; color: "white"; font.bold: true; font.pixelSize: 16 }
                            Text { text: modelData.artist; color: "#64748b"; font.pixelSize: 14 }
                        }

                        Text {
                            text: modelData.duration
                            color: "#64748b"
                            font.pixelSize: 14
                            Layout.rightMargin: 10
                        }

                        Row {
                            spacing: 20
                            Layout.alignment: Qt.AlignVCenter

                            Item {
                                width: 22
                                height: 22
                                Image {
                                    source: "qrc:/image_icons/hearted.png"
                                    anchors.fill: parent
                                    fillMode: Image.PreserveAspectFit
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: MusicApp.toggleFavorite(index)
                                }
                            }

                            Item {
                                width: 22
                                height: 22
                                Image {
                                    source: "qrc:/image_icons/edit.png"
                                    anchors.fill: parent
                                    fillMode: Image.PreserveAspectFit
                                }
                                MouseArea {
                                    anchors.fill: parent
                                }
                            }

                            Item {
                                width: 22
                                height: 22
                                Image {
                                    source: "qrc:/image_icons/delete.png"
                                    anchors.fill: parent
                                    fillMode: Image.PreserveAspectFit
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: MusicApp.deleteSong(index)
                                }
                            }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        z: -1
                        onClicked: MusicApp.playSong(index)
                    }
                }
            }
        }
    }
}