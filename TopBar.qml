import QtQuick 2.15

Item {
    // --- BIẾN REAL-TIME CHO ĐỒNG HỒ (Định dạng 24h) ---
    property string currentTimeStr: "00:00"

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var date = new Date()
            currentTimeStr = Qt.formatDateTime(date, "HH:mm")
        }
    }

    Component.onCompleted: {
        var date = new Date()
        currentTimeStr = Qt.formatDateTime(date, "HH:mm")
    }

    Image {
        anchors.fill: parent
        source: "qrc:/TopBar.png"
        fillMode: Image.PreserveAspectFit

        // LOGO MỚI
        Image {
            id: customLogo
            // Thay đường dẫn này bằng file logo của bạn

            // Bạn có thể tùy chỉnh width/height ở đây cho vừa mắt
            width: 80
            height: 80

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -5 // Điều chỉnh số này để nhích lên/xuống cho khớp
        }

        Row {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 100
            spacing: 8

            Image {
                source: "qrc:/icons/cloud.svg"
                width: 24
                height: 24
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                id: tempText
                text: "12 °C"
                color: "white"
                font.pixelSize: 20
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Text {
            id: timeText
            text: currentTimeStr
            color: "white"
            font.pixelSize: 20
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 100
        }
    }
}