import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {

    ScrollView {
        anchors.fill: parent
        contentWidth: availableWidth
        clip: true

        ColumnLayout {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 40
            spacing: 15
            // HIỂN THỊ
            Text {
                text: "HIỂN THỊ"
                color: "#64748b"
                font.pixelSize: 13
                font.bold: true
                Layout.topMargin: 10
                Layout.leftMargin: 5
            }

            //  Chế độ tối
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 5

                        Text { text: "Chế độ tối"; color: "white"; font.pixelSize: 17; font.bold: true }
                        Text { text: "Giao diện tối cho ban đêm"; color: "#64748b"; font.pixelSize: 14 }
                    }

                    // Nút gạt
                    Switch {
                        id: switchDarkMode
                        checked: true
                        indicator: Rectangle {
                            implicitWidth: 50
                            implicitHeight: 28
                            radius: 14
                            color: switchDarkMode.checked ? "#6366f1" : "#1e293b"

                            Rectangle {
                                x: switchDarkMode.checked ? parent.width - width - 3 : 3
                                y: 3
                                width: 22
                                height: 22
                                radius: 11
                                color: "white"
                                Behavior on x { NumberAnimation { duration: 150 } }
                            }
                        }
                    }
                }
            }

            // Card 2: Độ sáng
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 70
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text { text: "Độ sáng"; color: "white"; font.pixelSize: 17; font.bold: true; Layout.fillWidth: true }
                    Text { text: "☀️"; color: "#64748b"; font.pixelSize: 18 }

                    // Thanh kéo (Slider) Custom
                    Slider {
                        id: sliderBrightness
                        value: 0.75
                        Layout.preferredWidth: 250

                        background: Rectangle {
                            x: sliderBrightness.leftPadding
                            y: sliderBrightness.topPadding + sliderBrightness.availableHeight / 2 - height / 2
                            implicitWidth: 200
                            implicitHeight: 6
                            width: sliderBrightness.availableWidth
                            height: implicitHeight
                            radius: 3
                            color: "#1e293b"

                            Rectangle {
                                width: sliderBrightness.visualPosition * parent.width
                                height: parent.height
                                color: "#6366f1"
                                radius: 3
                            }
                        }

                        handle: Rectangle {
                            x: sliderBrightness.leftPadding + sliderBrightness.visualPosition * (sliderBrightness.availableWidth - width)
                            y: sliderBrightness.topPadding + sliderBrightness.availableHeight / 2 - height / 2
                            implicitWidth: 18
                            implicitHeight: 18
                            radius: 9
                            color: "#6366f1"
                        }
                    }

                    Text {
                        text: Math.round(sliderBrightness.value * 100) + "%"
                        color: "#64748b"
                        font.pixelSize: 14
                        Layout.preferredWidth: 40
                        horizontalAlignment: Text.AlignRight
                    }
                }
            }
            // ÂM THANH
            Text {
                text: "ÂM THANH"
                color: "#64748b"
                font.pixelSize: 13
                font.bold: true
                Layout.topMargin: 20
                Layout.leftMargin: 5
            }
            // Âm lượng
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 70
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text { text: "Âm lượng"; color: "white"; font.pixelSize: 17; font.bold: true; Layout.fillWidth: true }
                    Text { text: "🔊"; color: "#64748b"; font.pixelSize: 18 }

                    Slider {
                        id: sliderVolume
                        value: 0.60
                        Layout.preferredWidth: 250

                        background: Rectangle {
                            x: sliderVolume.leftPadding
                            y: sliderVolume.topPadding + sliderVolume.availableHeight / 2 - height / 2
                            implicitWidth: 200
                            implicitHeight: 6
                            width: sliderVolume.availableWidth
                            height: implicitHeight
                            radius: 3
                            color: "#1e293b"

                            Rectangle {
                                width: sliderVolume.visualPosition * parent.width
                                height: parent.height
                                color: "#6366f1"
                                radius: 3
                            }
                        }

                        handle: Rectangle {
                            x: sliderVolume.leftPadding + sliderVolume.visualPosition * (sliderVolume.availableWidth - width)
                            y: sliderVolume.topPadding + sliderVolume.availableHeight / 2 - height / 2
                            implicitWidth: 18
                            implicitHeight: 18
                            radius: 9
                            color: "#6366f1"
                        }
                    }

                    Text {
                        text: Math.round(sliderVolume.value * 100) + "%"
                        color: "#64748b"
                        font.pixelSize: 14
                        Layout.preferredWidth: 40
                        horizontalAlignment: Text.AlignRight
                    }
                }
            }

            // Âm thanh thông báo
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 70
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Text { text: "Âm thanh thông báo"; color: "white"; font.pixelSize: 17; font.bold: true; Layout.fillWidth: true }

                    Switch {
                        id: switchNotif
                        checked: true
                        indicator: Rectangle {
                            implicitWidth: 50
                            implicitHeight: 28
                            radius: 14
                            color: switchNotif.checked ? "#6366f1" : "#1e293b"

                            Rectangle {
                                x: switchNotif.checked ? parent.width - width - 3 : 3
                                y: 3
                                width: 22
                                height: 22
                                radius: 11
                                color: "white"
                                Behavior on x { NumberAnimation { duration: 150 } }
                            }
                        }
                    }
                }
            }

            //  KẾT NỐI

            Text {
                text: "KẾT NỐI"
                color: "#64748b"
                font.pixelSize: 13
                font.bold: true
                Layout.topMargin: 20
                Layout.leftMargin: 5
            }

            //  Bluetooth
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 5

                        Text { text: "Bluetooth"; color: "white"; font.pixelSize: 17; font.bold: true }
                        Text { text: "iPhone của Lực"; color: "#64748b"; font.pixelSize: 14 }
                    }

                    Switch {
                        id: switchBt
                        checked: true
                        indicator: Rectangle {
                            implicitWidth: 50
                            implicitHeight: 28
                            radius: 14
                            color: switchBt.checked ? "#6366f1" : "#1e293b"

                            Rectangle {
                                x: switchBt.checked ? parent.width - width - 3 : 3
                                y: 3
                                width: 22
                                height: 22
                                radius: 11
                                color: "white"
                                Behavior on x { NumberAnimation { duration: 150 } }
                            }
                        }
                    }
                }
            }

            //  Wi-Fi
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 5

                        Text { text: "Wi-Fi"; color: "white"; font.pixelSize: 17; font.bold: true }
                        Text { text: "CarNet_5G"; color: "#64748b"; font.pixelSize: 14 }
                    }

                    Switch {
                        id: switchWifi
                        checked: true
                        indicator: Rectangle {
                            implicitWidth: 50
                            implicitHeight: 28
                            radius: 14
                            color: switchWifi.checked ? "#6366f1" : "#1e293b"

                            Rectangle {
                                x: switchWifi.checked ? parent.width - width - 3 : 3
                                y: 3
                                width: 22
                                height: 22
                                radius: 11
                                color: "white"
                                Behavior on x { NumberAnimation { duration: 150 } }
                            }
                        }
                    }
                }
            }

            //  HỆ THỐNG
            Text {
                text: "HỆ THỐNG"
                color: "#64748b"
                font.pixelSize: 13
                font.bold: true
                Layout.topMargin: 20
                Layout.leftMargin: 5
            }

            // Ngôn ngữ
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 5

                        Text { text: "Ngôn ngữ"; color: "white"; font.pixelSize: 17; font.bold: true }
                        Text { text: "Tiếng Việt"; color: "#64748b"; font.pixelSize: 14 }
                    }

                    Text { text: "›"; color: "#64748b"; font.pixelSize: 30; Layout.alignment: Qt.AlignVCenter; Layout.rightMargin: 10 }
                }
            }

            // Phiên bản
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 80
                radius: 15
                color: "#151925"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    Column {
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignVCenter
                        spacing: 5

                        Text { text: "Phiên bản"; color: "white"; font.pixelSize: 17; font.bold: true }
                        Text { text: "v2.4.1"; color: "#64748b"; font.pixelSize: 14 }
                    }

                    Text { text: "Mới nhất"; color: "#64748b"; font.pixelSize: 15; Layout.alignment: Qt.AlignVCenter }
                }
            }

            // Khoảng trống dưới cùng để cuộn không bị sát đáy
            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
            }
        }
    }
}