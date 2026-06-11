import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: nowPlayingRoot
    width: parent ? parent.width : 800
    height: parent ? parent.height : 480

    property bool hasValidSong: MusicApp.playlist.length > 0 && MusicApp.currentSongIndex >= 0 && MusicApp.currentSongIndex < MusicApp.playlist.length

    // LISTVIEW GÁNH TOÀN BỘ MÀN HÌNH
    ListView {
        id: playlistView
        anchors.fill: parent
        // LỀ SẼ TỰ THU HẸP
        anchors.topMargin: nowPlayingRoot.width < 600 ? 20 : 40
        anchors.bottomMargin: nowPlayingRoot.width < 600 ? 20 : 40

        // SỬA THÀNH LỀ TRONG CỦA FLICKABLE (KHÔNG CÓ ANCHORS)
        leftMargin: nowPlayingRoot.width < 600 ? 20 : 40
        rightMargin: nowPlayingRoot.width < 600 ? 20 : 40
        model: MusicApp.playlist
        clip: true
        spacing: 8

        // THANH CUỘN TÀNG HÌNH ĐÃ THÊM TỪ TRƯỚC
        ScrollBar.vertical: ScrollBar {
            id: vbar
            policy: ScrollBar.AsNeeded
            width: 6
            background: Item {}
            contentItem: Rectangle {
                implicitWidth: 6
                radius: 3
                color: vbar.pressed ? "#c084fc" : (vbar.hovered ? "#475569" : "#1e293b")
            }
        }


        // HEADER: NHÉT TOÀN BỘ ĐĨA THAN VÀO ĐÂY ĐỂ CUỘN ĐƯỢC

        header: ColumnLayout {
            width: playlistView.width - playlistView.leftMargin - playlistView.rightMargin - (vbar.visible ? 25 : 0)
            spacing: nowPlayingRoot.width < 600 ? 15 : 30
            Column {
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 20
                spacing: nowPlayingRoot.width < 600 ? 10 : 20

                // --- ĐĨA THAN RESPONSIVE ---
                Item {
                    property int artSize: nowPlayingRoot.width < 600 ? 180 : 260
                    width: artSize
                    height: artSize
                    anchors.horizontalCenter: parent.horizontalCenter

                    Rectangle {
                        anchors.centerIn: parent
                        width: parent.width + 20
                        height: parent.height + 20
                        radius: width / 2
                        color: "#a855f7"
                        opacity: 0.2
                    }

                    Rectangle {
                        id: albumArt
                        anchors.fill: parent
                        radius: width / 2
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "#a855f7" }
                            GradientStop { position: 1.0; color: "#f97316" }
                        }

                        Image {
                            source: "qrc:/image_icons/music.png"
                            width: parent.width * 0.25
                            height: parent.height * 0.25
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

                //  TÊN BÀI HÁT & ICON TIM
                RowLayout {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 20

                    Column {
                        spacing: 8
                        Layout.alignment: Qt.AlignVCenter

                        Text {
                            text: hasValidSong ? MusicApp.playlist[MusicApp.currentSongIndex].title : "Chưa có dữ liệu"
                            color: "white"
                            font.pixelSize: nowPlayingRoot.width < 600 ? 18 : 22
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        Text {
                            text: hasValidSong ? MusicApp.playlist[MusicApp.currentSongIndex].artist : ""
                            color: "#94a3b8"
                            font.pixelSize: nowPlayingRoot.width < 600 ? 14 : 16
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }

                    Item {
                        Layout.preferredWidth: 30
                        Layout.preferredHeight: 30
                        Layout.alignment: Qt.AlignVCenter

                        Image {
                            id: mainFavoriteIcon
                            source: (hasValidSong && MusicApp.playlist[MusicApp.currentSongIndex].isFavorite) ? "qrc:/image_icons/hearted.png" : "qrc:/image_icons/heart.png"
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            Behavior on scale { NumberAnimation { duration: 100 } }
                        }

                        MouseArea {
                            anchors.fill: parent
                            onPressed: mainFavoriteIcon.scale = 0.8
                            onReleased: mainFavoriteIcon.scale = 1.0
                            onClicked: {
                                if (MusicApp.playlist.length > 0) {
                                    MusicApp.toggleFavorite(MusicApp.currentSongIndex)
                                }
                            }
                        }
                    }
                }

                // THANH THỜI GIAN RESPONSIVE
                RowLayout {
                    width: Math.min(nowPlayingRoot.width - 60, 600)
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 15

                    Text {
                        text: hasValidSong ? MusicApp.formatTime(MusicApp.timeToSeconds(MusicApp.playlist[MusicApp.currentSongIndex].duration) * MusicApp.songProgress) : "0:00"
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
                                onClicked: (mouse) => {
                                               var newProgress = mouse.x / width
                                               MusicApp.seekToProgress(Math.min(Math.max(newProgress, 0), 1))
                                           }
                                onPositionChanged: (mouse) => {
                                                       if (pressed) {
                                                           var dragProgress = mouse.x / width
                                                           MusicApp.seekToProgress(Math.min(Math.max(dragProgress, 0), 1))
                                                       }
                                                   }
                            }
                        }
                    }

                    Text {
                        text: hasValidSong ? MusicApp.playlist[MusicApp.currentSongIndex].duration : "0:00"
                        color: "#94a3b8"
                        font.pixelSize: 13
                        Layout.preferredWidth: 35
                        Layout.alignment: Qt.AlignVCenter
                    }
                }

                //HÀNG NÚT BẤM
                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: nowPlayingRoot.width < 600 ? 10 : 15

                    Rectangle {
                        width: nowPlayingRoot.width < 600 ? 40 : 50
                        height: nowPlayingRoot.width < 600 ? 40 : 50
                        radius: width / 2
                        color: MusicApp.isShuffle ? "#a855f7" : (mouseShuffle.containsMouse ? "#2a324a" : "#161b26")
                        scale: mouseShuffle.pressed ? 0.9 : 1.0

                        Behavior on color { ColorAnimation { duration: 150 } }
                        Behavior on scale { NumberAnimation { duration: 100 } }

                        Image {
                            source: "qrc:/image_icons/shuffle.png"
                            width: parent.width * 0.45
                            height: parent.height * 0.45
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
                        width: nowPlayingRoot.width < 600 ? 40 : 50
                        height: nowPlayingRoot.width < 600 ? 40 : 50
                        radius: width / 2
                        color: mousePrev.containsMouse ? "#2a324a" : "#161b26"
                        scale: mousePrev.pressed ? 0.9 : 1.0

                        Image {
                            source: "qrc:/image_icons/previous.png"
                            width: parent.width * 0.45
                            height: parent.height * 0.45
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn: parent
                        }
                        MouseArea {
                            id: mousePrev
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: MusicApp.prevSong()
                        }
                    }

                    Item {
                        width: nowPlayingRoot.width < 600 ? 55 : 70
                        height: nowPlayingRoot.width < 600 ? 55 : 70
                        scale: mousePlay.pressed ? 0.9 : 1.0

                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width * 1.2
                            height: parent.height * 1.2
                            radius: width / 2
                            color: "#c084fc"
                            opacity: 0.2
                        }
                        Rectangle {
                            anchors.fill: parent
                            radius: width / 2
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: mousePlay.containsMouse ? "#d8b4fe" : "#c084fc" }
                                GradientStop { position: 1.0; color: mousePlay.containsMouse ? "#f17eb8" : "#db2777" }
                            }
                            Image {
                                source: MusicApp.isPlaying ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"
                                width: parent.width * 0.45
                                height: parent.height * 0.45
                                fillMode: Image.PreserveAspectFit
                                anchors.centerIn: parent
                            }
                            MouseArea {
                                id: mousePlay
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: MusicApp.isPlaying = !MusicApp.isPlaying
                            }
                        }
                    }

                    Rectangle {
                        width: nowPlayingRoot.width < 600 ? 40 : 50
                        height: nowPlayingRoot.width < 600 ? 40 : 50
                        radius: width / 2
                        color: mouseNext.containsMouse ? "#2a324a" : "#161b26"
                        scale: mouseNext.pressed ? 0.9 : 1.0

                        Image {
                            source: "qrc:/image_icons/next.png"
                            width: parent.width * 0.45
                            height: parent.height * 0.45
                            fillMode: Image.PreserveAspectFit
                            anchors.centerIn: parent
                        }
                        MouseArea {
                            id: mouseNext
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: MusicApp.nextSong()
                        }
                    }

                    Rectangle {
                        width: nowPlayingRoot.width < 600 ? 40 : 50
                        height: nowPlayingRoot.width < 600 ? 40 : 50
                        radius: width / 2
                        color: MusicApp.isRepeat ? "#a855f7" : (mouseRepeat.containsMouse ? "#2a324a" : "#161b26")
                        scale: mouseRepeat.pressed ? 0.9 : 1.0

                        Image {
                            source: "qrc:/image_icons/repeat.png"
                            width: parent.width * 0.45
                            height: parent.height * 0.45
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

            Text {
                Layout.topMargin: 20
                Layout.bottomMargin: 5
                text: "Danh sách đang phát"
                color: "white"
                font.pixelSize: 20
                font.bold: true
                Layout.fillWidth: true
            }
        }

        // THIẾT KẾ CHO TỪNG BÀI HÁT (GIỮ NGUYÊN)
        delegate: Rectangle {
            id: songRow
            width: playlistView.width - playlistView.leftMargin - playlistView.rightMargin - (vbar.visible ? 25 : 0)
            height: 75
            radius: 15

            property bool isMenuOpen: (songMenu.visible && songMenu.targetIndex === index) || (addToPlaylistMenu.visible && addToPlaylistMenu.targetSongIndex === index)
            property bool isIconHovered: addMouse.containsMouse || favMouse.containsMouse || plMouse.containsMouse || dotMouse.containsMouse
            property bool showIcons: rowMouseArea.containsMouse || isIconHovered || isMenuOpen

            color: (modelData.isPlaying && MusicApp.isPlaying) ? "#22173f" : (showIcons ? "#1e293b" : "transparent")
            border.color: (modelData.isPlaying && MusicApp.isPlaying) ? "#3b2260" : "transparent"
            border.width: 1

            MouseArea {
                id: rowMouseArea
                anchors.fill: parent
                hoverEnabled: true
                z: -1
                onClicked: MusicApp.playSong(index)
            }

            RowLayout {
                anchors.fill: parent
                anchors.margins: nowPlayingRoot.width < 600 ? 10 : 20
                spacing: 15

                Text {
                    text: (index + 1)
                    color: (modelData.isPlaying && MusicApp.isPlaying) ? "#c084fc" : "#64748b"
                    font.pixelSize: 16
                    font.bold: true
                    Layout.preferredWidth: 25
                }

                Column {
                    Layout.fillWidth: true
                    spacing: 5

                    Text {
                        text: modelData.title
                        color: "white"
                        font.bold: true
                        font.pixelSize: 16
                        elide: Text.ElideRight
                        width: parent.width
                    }
                    Text {
                        text: modelData.artist
                        color: "#64748b"
                        font.pixelSize: 14
                        elide: Text.ElideRight
                        width: parent.width
                    }
                }

                Item {
                    Layout.preferredWidth: nowPlayingRoot.width < 600 ? 150 : 210
                    Layout.fillHeight: true

                    Text {
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        visible: !songRow.showIcons
                        text: modelData.duration
                        color: "#64748b"
                        font.pixelSize: 14
                    }

                    Row {
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: nowPlayingRoot.width < 600 ? 8 : 18
                        visible: songRow.showIcons

                        Item {
                            width: 28; height: 28
                            scale: addMouse.pressed ? 0.8 : (addMouse.containsMouse ? 1.2 : 1.0)
                            Behavior on scale { NumberAnimation { duration: 100 } }
                            Image { source: "qrc:/image_icons/add.png"; anchors.fill: parent }
                            MouseArea {
                                id: addMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: {
                                    addToPlaylistMenu.targetSongIndex = index
                                    addToPlaylistMenu.popup(parent, -180, 30)
                                }
                            }
                        }

                        Item {
                            width: 28; height: 28
                            scale: favMouse.pressed ? 0.8 : (favMouse.containsMouse ? 1.2 : 1.0)
                            Behavior on scale { NumberAnimation { duration: 100 } }
                            Image { source: modelData.isFavorite ? "qrc:/image_icons/hearted.png" : "qrc:/image_icons/heart.png"; anchors.fill: parent }
                            MouseArea {
                                id: favMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: MusicApp.toggleFavorite(index)
                            }
                        }

                        Item {
                            width: 28; height: 28
                            scale: plMouse.pressed ? 0.8 : (plMouse.containsMouse ? 1.2 : 1.0)
                            Behavior on scale { NumberAnimation { duration: 100 } }
                            Image { source: (modelData.isPlaying && MusicApp.isPlaying) ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"; anchors.fill: parent }
                            MouseArea {
                                id: plMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: {
                                    if (modelData.isPlaying) MusicApp.isPlaying = !MusicApp.isPlaying
                                    else MusicApp.playSong(index)
                                }
                            }
                        }

                        Item {
                            width: 28; height: 28
                            scale: dotMouse.pressed ? 0.8 : (dotMouse.containsMouse ? 1.2 : 1.0)
                            Behavior on scale { NumberAnimation { duration: 100 } }
                            Image { source: "qrc:/image_icons/three-dots.png"; anchors.fill: parent }
                            MouseArea {
                                id: dotMouse
                                anchors.fill: parent
                                hoverEnabled: true
                                onClicked: {
                                    songMenu.targetIndex = index
                                    songMenu.popup(parent, -180, 30)
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // CÁC POPUP VÀ MENU CHO BÀI HÁT
    Menu {
        id: addToPlaylistMenu
        property int targetSongIndex: -1
        width: 220
        background: Rectangle { color: "#1e293b"; radius: 8; border.color: "#334155"; border.width: 1 }

        MenuItem {
            text: "Thêm vào..."
            enabled: false
            contentItem: Text { text: parent.text; color: "#94a3b8"; font.pixelSize: 13; font.bold: true }
        }
        Repeater {
            model: MusicApp.customPlaylists
            MenuItem {
                text: modelData.name
                contentItem: Text { text: parent.text; color: "white"; font.pixelSize: 15; verticalAlignment: Text.AlignVCenter }
                onTriggered: MusicApp.addSongToCustomPlaylist(addToPlaylistMenu.targetSongIndex, index)
            }
        }
        MenuItem {
            visible: MusicApp.customPlaylists.length === 0
            text: "Chưa có Playlist nào"
            enabled: false
            contentItem: Text { text: parent.text; color: "#ef4444"; font.pixelSize: 14; font.italic: true }
        }
    }

    Menu {
        id: songMenu
        property int targetIndex: -1
        width: 220
        background: Rectangle { color: "#1e293b"; radius: 8; border.color: "#334155"; border.width: 1 }

        MenuItem {
            text: "Sửa thông tin"
            contentItem: Text { text: parent.text; color: "white"; font.pixelSize: 15; verticalAlignment: Text.AlignVCenter }
            onTriggered: editPopup.openEdit(songMenu.targetIndex)
        }
        MenuItem {
            text: "Xóa khỏi danh sách"
            contentItem: Text { text: parent.text; color: "#ef4444"; font.pixelSize: 15; verticalAlignment: Text.AlignVCenter }
            onTriggered: MusicApp.deleteSong(songMenu.targetIndex)
        }
    }

    Popup {
        id: editPopup
        width: 400
        height: 250
        anchors.centerIn: parent
        modal: true
        background: Rectangle { color: "#0f111a"; radius: 15; border.color: "#334155" }
        property int editingIndex: -1

        function openEdit(index) {
            editingIndex = index
            var song = MusicApp.playlist[index]
            titleInput.text = song.title
            artistInput.text = song.artist
            open()
        }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 15
            Text { text: "Sửa thông tin bài hát"; color: "white"; font.bold: true; font.pixelSize: 18 }
            TextField {
                id: titleInput
                Layout.fillWidth: true
                color: "white"
                background: Rectangle { color: "#1e293b"; radius: 8 }
            }
            TextField {
                id: artistInput
                Layout.fillWidth: true
                color: "white"
                background: Rectangle { color: "#1e293b"; radius: 8 }
            }
            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: 10
                Button {
                    text: "Hủy"
                    contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter }
                    background: Rectangle { color: "#334155"; radius: 8; implicitWidth: 80; implicitHeight: 35 }
                    onClicked: editPopup.close()
                }
                Button {
                    text: "Lưu"
                    contentItem: Text { text: parent.text; color: "white"; horizontalAlignment: Text.AlignHCenter }
                    background: Rectangle { color: "#c084fc"; radius: 8; implicitWidth: 80; implicitHeight: 35 }
                    onClicked: {
                        MusicApp.editSong(editPopup.editingIndex, titleInput.text, artistInput.text)
                        editPopup.close()
                    }
                }
            }
        }
    }
}