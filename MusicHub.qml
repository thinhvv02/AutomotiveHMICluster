import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: hubRoot

    Component.onCompleted: {
        contentLoader.setSource("PlaylistView.qml", { "pageTitle": "Tất cả bài hát", "playlistType": "all" })
    }

    ColumnLayout {
        anchors.fill: parent
        // THU NHỎ LỀ KHI MÀN HÌNH HẸP
        anchors.margins: hubRoot.width < 900 ? 15 : 30
        spacing: hubRoot.width < 900 ? 10 : 20

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: hubRoot.width < 900 ? 15 : 30

            //  CỘT TRÁI (SIDEBAR) RESPONSIVE
            Rectangle {
                // TỰ THU HẸP SIDEBAR XUỐNG 220PX KHI BỊ CHIA ĐÔI MÀN HÌNH
                Layout.preferredWidth: hubRoot.width < 900 ? 220 : 320
                Layout.fillHeight: true
                color: "#151925"
                radius: 20
                border.color: "#1e293b"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: hubRoot.width < 900 ? 15 : 25
                    spacing: 15

                    Text {
                        text: "Trung Tâm Âm Nhạc"
                        color: "white"
                        // TỰ GIẢM SIZE CHỮ
                        font.pixelSize: hubRoot.width < 900 ? 18 : 22
                        font.bold: true
                        Layout.bottomMargin: 10
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45
                        radius: 8
                        color: favMouse.containsMouse ? "#1e293b" : "transparent"

                        Behavior on color { ColorAnimation { duration: 150 } }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 15

                            Image {
                                source: "qrc:/image_icons/hearted.png"
                                Layout.preferredWidth: 24
                                Layout.preferredHeight: 24
                            }
                            Text {
                                text: "Bài hát Yêu thích"
                                color: favMouse.containsMouse ? "white" : "#94a3b8"
                                font.pixelSize: 16
                                Layout.fillWidth: true
                            }
                        }
                        MouseArea {
                            id: favMouse
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: contentLoader.setSource("PlaylistView.qml", { "pageTitle": "Bài hát Yêu thích", "playlistType": "favorite" })
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45
                        radius: 8
                        color: recMouse.containsMouse ? "#1e293b" : "transparent"

                        Behavior on color { ColorAnimation { duration: 150 } }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 15

                            Image {
                                source: "qrc:/image_icons/history.png"
                                Layout.preferredWidth: 24
                                Layout.preferredHeight: 24
                            }
                            Text {
                                text: "Nghe gần đây"
                                color: recMouse.containsMouse ? "white" : "#94a3b8"
                                font.pixelSize: 16
                                Layout.fillWidth: true
                            }
                        }
                        MouseArea {
                            id: recMouse
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: contentLoader.setSource("PlaylistView.qml", { "pageTitle": "Nghe gần đây", "playlistType": "recent" })
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45
                        radius: 8
                        color: usbMouse.containsMouse ? "#1e293b" : "transparent"

                        Behavior on color { ColorAnimation { duration: 150 } }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 15

                            Image {
                                source: "qrc:/image_icons/music.png"
                                Layout.preferredWidth: 24
                                Layout.preferredHeight: 24
                            }
                            Text {
                                text: "Tất cả bài hát"
                                color: usbMouse.containsMouse ? "white" : "#94a3b8"
                                font.pixelSize: 16
                                Layout.fillWidth: true
                            }
                        }
                        MouseArea {
                            id: usbMouse
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: contentLoader.setSource("PlaylistView.qml", { "pageTitle": "Tất cả bài hát", "playlistType": "all" })
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45
                        radius: 8
                        color: playMouse.containsMouse ? "#1e293b" : "transparent"

                        Behavior on color { ColorAnimation { duration: 150 } }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 15

                            Image {
                                source: "qrc:/image_icons/music.png"
                                Layout.preferredWidth: 24
                                Layout.preferredHeight: 24
                            }
                            Text {
                                text: "Đang phát"
                                color: playMouse.containsMouse ? "white" : "#94a3b8"
                                font.pixelSize: 16
                                Layout.fillWidth: true
                            }
                        }
                        MouseArea {
                            id: playMouse
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: {
                                MusicApp.loadPlayingPlaylist() // TỰ ĐỘNG LOAD LẠI LIST ĐANG CHẠY
                                contentLoader.setSource("NowPlaying.qml")
                            }
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 1
                        color: "#334155"
                        Layout.topMargin: 5
                        Layout.bottomMargin: 5
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 45
                        radius: 8
                        color: addMouse.containsMouse ? "#1e293b" : "transparent"

                        Behavior on color { ColorAnimation { duration: 150 } }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 15

                            Image {
                                source: "qrc:/image_icons/add.png"
                                Layout.preferredWidth: 24
                                Layout.preferredHeight: 24
                            }
                            Text {
                                text: "Tạo Playlist mới"
                                color: addMouse.containsMouse ? "#c084fc" : "#a855f7"
                                font.pixelSize: 16
                                font.bold: true
                                Layout.fillWidth: true
                            }
                        }
                        MouseArea {
                            id: addMouse
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: createPlaylistPopup.open()
                        }
                    }

                    ListView {
                        id: customPlaylistsView
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        model: MusicApp.customPlaylists
                        clip: true
                        spacing: 5

                        ScrollBar.vertical: ScrollBar {
                            id: vbar
                            policy: ScrollBar.AsNeeded
                            width: 6 // Làm thanh cuộn mỏng lại cho thanh lịch

                            // QUAN TRỌNG NHẤT: Xóa cái nền (track) mặc định của Qt
                            background: Item {}

                            contentItem: Rectangle {
                                implicitWidth: 6
                                radius: 3
                                // Bình thường màu xám tối chìm vào nền. Hover/Kéo sẽ sáng lên.
                                color: vbar.pressed ? "#c084fc" : (vbar.hovered ? "#475569" : "#1e293b")
                            }
                        }

                        delegate: Rectangle {
                            width: customPlaylistsView.width
                            height: 45
                            radius: 8
                            color: plMouse.containsMouse ? "#1e293b" : "transparent"

                            Behavior on color { ColorAnimation { duration: 150 } }

                            RowLayout {
                                anchors.fill: parent
                                anchors.margins: 10
                                spacing: 15

                                Image {
                                    source: "qrc:/image_icons/playlist.png"
                                    Layout.preferredWidth: 20
                                    Layout.preferredHeight: 20
                                }
                                Text {
                                    text: modelData.name
                                    color: plMouse.containsMouse ? "white" : "#94a3b8"
                                    font.pixelSize: 16
                                    Layout.fillWidth: true
                                }
                            }
                            MouseArea {
                                id: plMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: contentLoader.setSource("PlaylistView.qml", { "pageTitle": modelData.name, "playlistType": "custom_" + index })
                            }
                        }
                    }
                }
            }

            Loader {
                id: contentLoader
                Layout.fillWidth: true
                Layout.fillHeight: true

                Behavior on opacity { NumberAnimation { duration: 200 } }
                onSourceChanged: opacity = 0
                onLoaded: opacity = 1
            }
        }

        // MINI PLAYER RESPONSIVE
        Rectangle {
            id: miniPlayer
            Layout.fillWidth: true
            Layout.preferredHeight: 70 // THU NHỎ CHIỀU CAO (Từ 90 -> 70)
            color: "#181425"
            radius: 20 // Bo góc nhẹ lại cho hợp với chiều cao mới
            border.color: "#1e293b"
            border.width: 1
            visible: MusicApp.playlist.length > 0 && MusicApp.hasStartedPlaying

            property var playingSong: MusicApp.playingSongInfo
            property bool hasValidSong: MusicApp.playlist.length > 0 && MusicApp.currentSongIndex >= 0 && MusicApp.currentSongIndex < MusicApp.playlist.length

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    MusicApp.loadPlayingPlaylist() // TỰ ĐỘNG LOAD LẠI LIST ĐANG CHẠY
                    contentLoader.setSource("NowPlaying.qml")
                }
            }

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10 // Bóp margin lại cho đỡ tốn diện tích
                anchors.leftMargin: hubRoot.width < 900 ? 10 : 15
                anchors.rightMargin: hubRoot.width < 900 ? 10 : 15
                spacing: hubRoot.width < 900 ? 10 : 20

                // THU NHỎ KHỐI ICON MUSIC
                Rectangle {
                    width: 45
                    height: 45
                    radius: 12
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#c084fc" }
                        GradientStop { position: 1.0; color: "#db2777" }
                    }
                    Image {
                        source: "qrc:/image_icons/music.png"
                        width: 24
                        height: 24
                        anchors.centerIn: parent
                        RotationAnimator on rotation {
                            running: MusicApp.isPlaying
                            from: 0
                            to: 360
                            duration: 8000
                            loops: Animation.Infinite
                        }
                    }
                }

                // 2. THU NHỎ FONT CHỮ
                Column {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignVCenter
                    spacing: 3 // Kéo 2 dòng chữ lại gần nhau
                    Text {
                        text: miniPlayer.hasValidSong ? MusicApp.playlist[MusicApp.currentSongIndex].title : ""
                        color: "white"
                        font.bold: true
                        font.pixelSize: 15
                        elide: Text.ElideRight
                        width: parent.width
                    }
                    Text {
                        text: miniPlayer.hasValidSong ? MusicApp.playlist[MusicApp.currentSongIndex].artist : ""
                        color: "#94a3b8"
                        font.pixelSize: 12
                        elide: Text.ElideRight
                        width: parent.width
                    }
                    Item {
                        width: parent.width * 0.8
                        height: 8
                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width
                            height: 3 // Thanh chạy mỏng lại một chút
                            color: "#334155"
                            radius: 2
                            Rectangle {
                                width: parent.width * MusicApp.songProgress
                                height: parent.height
                                radius: 2
                                gradient: Gradient {
                                    GradientStop { position: 0.0; color: "#c084fc" }
                                    GradientStop { position: 1.0; color: "#db2777" }
                                }
                            }
                        }
                    }
                }

                //  THU NHỎ CÁC NÚT ĐIỀU KHIỂN
                Row {
                    spacing: hubRoot.width < 900 ? 10 : 15
                    Layout.alignment: Qt.AlignVCenter

                    Item {
                        width: 30; height: 30
                        scale: mousePrevMini.pressed ? 0.8 : (mousePrevMini.containsMouse ? 1.1 : 1.0)
                        Behavior on scale { NumberAnimation { duration: 100 } }
                        Image { source: "qrc:/image_icons/previous.png"; anchors.fill: parent }
                        MouseArea {
                            id: mousePrevMini
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: MusicApp.prevSong()
                        }
                    }

                    Item {
                        width: 30; height: 30
                        scale: mousePlayMini.pressed ? 0.8 : (mousePlayMini.containsMouse ? 1.1 : 1.0)
                        Behavior on scale { NumberAnimation { duration: 100 } }
                        Image { source: MusicApp.isPlaying ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"; anchors.fill: parent }
                        MouseArea {
                            id: mousePlayMini
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: MusicApp.isPlaying = !MusicApp.isPlaying
                        }
                    }

                    Item {
                        width: 30; height: 30
                        scale: mouseNextMini.pressed ? 0.8 : (mouseNextMini.containsMouse ? 1.1 : 1.0)
                        Behavior on scale { NumberAnimation { duration: 100 } }
                        Image { source: "qrc:/image_icons/next.png"; anchors.fill: parent }
                        MouseArea {
                            id: mouseNextMini
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: MusicApp.nextSong()
                        }
                    }
                }
            }
        }
    }
    Popup {
        id: createPlaylistPopup
        width: 400
        height: 200
        anchors.centerIn: parent
        modal: true
        background: Rectangle { color: "#0f111a"; radius: 15; border.color: "#334155" }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 15
            Text { text: "Tạo Playlist Mới"; color: "white"; font.bold: true; font.pixelSize: 18 }
            TextField {
                id: playlistNameInput
                Layout.fillWidth: true
                color: "white"
                placeholderText: "Nhập tên playlist..."
                placeholderTextColor: "#64748b"
                background: Rectangle { color: "#1e293b"; radius: 8 }
            }
            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: 10
                Button {
                    text: "Hủy"
                    contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter }
                    background: Rectangle { color: "#334155"; radius: 8; implicitWidth: 80; implicitHeight: 35 }
                    onClicked: { playlistNameInput.text = ""; createPlaylistPopup.close() }
                }
                Button {
                    text: "Tạo mới"
                    contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter }
                    background: Rectangle { color: "#c084fc"; radius: 8; implicitWidth: 80; implicitHeight: 35 }
                    onClicked: {
                        if (playlistNameInput.text.trim() !== "") {
                            MusicApp.createCustomPlaylist(playlistNameInput.text)
                            playlistNameInput.text = ""
                            createPlaylistPopup.close()
                        }
                    }
                }
            }
        }
    }

    Popup {
        id: toastPopup
        parent: Overlay.overlay
        x: Math.round((parent.width - width) / 2)
        y: Math.round(parent.height - height - 100)
        height: 45
        background: Rectangle { color: "#1e293b"; radius: 22.5; border.color: "#c084fc"; border.width: 1 }
        contentItem: Text {
            id: toastText
            color: "white"
            font.pixelSize: 15
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            padding: 15
        }
        Timer { id: toastTimer; interval: 2000; onTriggered: toastPopup.close() }
    }

    Connections {
        target: MusicApp
        function onShowNotification(msg) {
            toastText.text = msg
            toastPopup.open()
            toastTimer.restart()
        }
    }
}