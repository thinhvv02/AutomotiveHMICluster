import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: playlistRoot
    anchors.fill: parent
    property string pageTitle: "Danh sách phát"
    property string playlistType: ""

    onPlaylistTypeChanged: {
        if (playlistType !== "") {
            MusicApp.loadPlaylist(playlistType)
            searchInput.text = ""
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        RowLayout {
            Layout.fillWidth: true
            spacing: 20

            Text {
                text: pageTitle
                color: "white"
                font.pixelSize: playlistRoot.width < 600 ? 22 : 28
                font.bold: true
                Layout.preferredWidth: playlistRoot.width < 600 ? 150 : 300
                elide: Text.ElideRight
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 45
                radius: 22.5
                color: "#151925"
                border.color: "#1e293b"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 10
                    anchors.leftMargin: 15
                    spacing: 10

                    Image {
                        source: "qrc:/image_icons/search.png"
                        Layout.preferredWidth: 20
                        Layout.preferredHeight: 20
                        opacity: 0.6
                    }

                    TextField {
                        id: searchInput
                        Layout.fillWidth: true
                        placeholderText: "Tìm kiếm bài hát hoặc ca sĩ..."
                        placeholderTextColor: "#64748b"
                        color: "white"
                        font.pixelSize: 15
                        background: Item {}
                    }
                }
            }
        }

        ListView {
            id: playlistView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: MusicApp.playlist
            clip: true
            spacing: 0
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

            delegate: Item {
                id: delegateWrapper
                width: playlistView.width

                property string searchText: searchInput.text.trim().toLowerCase()
                property string songTitle: modelData.title.toLowerCase()
                property string songArtist: modelData.artist.toLowerCase()
                property bool isMatch: searchText === "" || songTitle.indexOf(searchText) !== -1 || songArtist.indexOf(searchText) !== -1

                visible: isMatch
                height: isMatch ? 83 : 0

                Rectangle {
                    id: songRow
                    width: parent.width
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
                        onClicked: {
                            contentLoader.setSource("NowPlaying.qml")
                            MusicApp.playSong(index)
                        }
                    }

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: playlistRoot.width < 600 ? 10 : 20
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
                            Layout.preferredWidth: playlistRoot.width < 600 ? 150 : 210
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
                                spacing: playlistRoot.width < 600 ? 8 : 18
                                visible: songRow.showIcons

                                Item {
                                    width: 28
                                    height: 28
                                    scale: addMouse.pressed ? 0.8 : (addMouse.containsMouse ? 1.2 : 1.0)

                                    Behavior on scale {
                                        NumberAnimation {
                                            duration: 100
                                        }
                                    }

                                    Image {
                                        source: "qrc:/image_icons/add.png"
                                        anchors.fill: parent
                                    }

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
                                    width: 28
                                    height: 28
                                    scale: favMouse.pressed ? 0.8 : (favMouse.containsMouse ? 1.2 : 1.0)

                                    Behavior on scale {
                                        NumberAnimation {
                                            duration: 100
                                        }
                                    }

                                    Image {
                                        source: modelData.isFavorite ? "qrc:/image_icons/hearted.png" : "qrc:/image_icons/heart.png"
                                        anchors.fill: parent
                                    }

                                    MouseArea {
                                        id: favMouse
                                        anchors.fill: parent
                                        hoverEnabled: true
                                        onClicked: MusicApp.toggleFavorite(index)
                                    }
                                }

                                Item {
                                    width: 28
                                    height: 28
                                    scale: plMouse.pressed ? 0.8 : (plMouse.containsMouse ? 1.2 : 1.0)

                                    Behavior on scale {
                                        NumberAnimation {
                                            duration: 100
                                        }
                                    }

                                    Image {
                                        source: (modelData.isPlaying && MusicApp.isPlaying) ? "qrc:/image_icons/pause.png" : "qrc:/image_icons/play.png"
                                        anchors.fill: parent
                                    }

                                    MouseArea {
                                        id: plMouse
                                        anchors.fill: parent
                                        hoverEnabled: true
                                        onClicked: {
                                            if (modelData.isPlaying) {
                                                MusicApp.isPlaying = !MusicApp.isPlaying
                                            } else {
                                                MusicApp.playSong(index)
                                            }
                                        }
                                    }
                                }

                                Item {
                                    width: 28
                                    height: 28
                                    scale: dotMouse.pressed ? 0.8 : (dotMouse.containsMouse ? 1.2 : 1.0)

                                    Behavior on scale {
                                        NumberAnimation {
                                            duration: 100
                                        }
                                    }

                                    Image {
                                        source: "qrc:/image_icons/three-dots.png"
                                        anchors.fill: parent
                                    }

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
        }

        Menu {
            id: addToPlaylistMenu
            property int targetSongIndex: -1
            width: 220
            background: Rectangle {
                color: "#1e293b"
                radius: 8
                border.color: "#334155"
                border.width: 1
            }

            MenuItem {
                text: "Thêm vào..."
                enabled: false
                contentItem: Text {
                    text: parent.text
                    color: "#94a3b8"
                    font.pixelSize: 13
                    font.bold: true
                }
            }

            Repeater {
                model: MusicApp.customPlaylists
                MenuItem {
                    text: modelData.name
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        font.pixelSize: 15
                        verticalAlignment: Text.AlignVCenter
                    }
                    onTriggered: MusicApp.addSongToCustomPlaylist(addToPlaylistMenu.targetSongIndex, index)
                }
            }

            MenuItem {
                visible: MusicApp.customPlaylists.length === 0
                text: "Chưa có Playlist nào"
                enabled: false
                contentItem: Text {
                    text: parent.text
                    color: "#ef4444"
                    font.pixelSize: 14
                    font.italic: true
                }
            }
        }

        Menu {
            id: songMenu
            property int targetIndex: -1
            width: 220
            background: Rectangle {
                color: "#1e293b"
                radius: 8
                border.color: "#334155"
                border.width: 1
            }

            MenuItem {
                text: "Sửa thông tin"
                visible: playlistType !== "usb" && playlistType !== "all"
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.pixelSize: 15
                    verticalAlignment: Text.AlignVCenter
                }
                onTriggered: editPopup.openEdit(songMenu.targetIndex)
            }

            MenuItem {
                text: "Xóa khỏi danh sách"
                contentItem: Text {
                    text: parent.text
                    color: "#ef4444"
                    font.pixelSize: 15
                    verticalAlignment: Text.AlignVCenter
                }
                onTriggered: MusicApp.deleteSong(songMenu.targetIndex)
            }
        }

        Popup {
            id: editPopup
            width: 400
            height: 250
            anchors.centerIn: parent
            modal: true
            background: Rectangle {
                color: "#0f111a"
                radius: 15
                border.color: "#334155"
            }

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

                Text {
                    text: "Sửa thông tin bài hát"
                    color: "white"
                    font.bold: true
                    font.pixelSize: 18
                }

                TextField {
                    id: titleInput
                    Layout.fillWidth: true
                    color: "white"
                    background: Rectangle {
                        color: "#1e293b"
                        radius: 8
                    }
                }

                TextField {
                    id: artistInput
                    Layout.fillWidth: true
                    color: "white"
                    background: Rectangle {
                        color: "#1e293b"
                        radius: 8
                    }
                }

                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    spacing: 10

                    Button {
                        text: "Hủy"
                        contentItem: Text {
                            text: parent.text
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                        }
                        background: Rectangle {
                            color: "#334155"
                            radius: 8
                            implicitWidth: 80
                            implicitHeight: 35
                        }
                        onClicked: editPopup.close()
                    }

                    Button {
                        text: "Lưu"
                        contentItem: Text {
                            text: parent.text
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                        }
                        background: Rectangle {
                            color: "#c084fc"
                            radius: 8
                            implicitWidth: 80
                            implicitHeight: 35
                        }
                        onClicked: {
                            MusicApp.editSong(editPopup.editingIndex, titleInput.text, artistInput.text)
                            editPopup.close()
                        }
                    }
                }
            }
        }
    }
}