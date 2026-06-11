import QtQuick 2.15

Item {
    // --- CÁC BIẾN REAL-TIME GIẢ LẬP ---
    property int speedLimit: 90
    property real distanceToTurn: 260
    property real remainingDistance: 25.4
    property int remainingTime: 11

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            if (distanceToTurn > 0) {
                distanceToTurn -= 15
            } else {
                distanceToTurn = 500
            }

            if (remainingDistance > 0) {
                remainingDistance -= 0.01
            }

            if (remainingTime > 0 && Math.random() > 0.8) {
                remainingTime -= 1
            }
        }
    }
    Image {
        id: road
        anchors.fill: parent
        source: "qrc:/road/road3.svg"
        fillMode: Image.Stretch

        Image {
            id: car1
            width: parent.width * 0.16
            height: parent.height * 0.20
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 25
            source: "qrc:/road/car.png"
            fillMode: Image.PreserveAspectFit

            SequentialAnimation on anchors.bottomMargin {
                loops: Animation.Infinite
                NumberAnimation { from: 100; to: 101; duration: 120 }
                NumberAnimation { from: 100; to: 101; duration: 120 }
            }
        }

        Image {
            id: car2
            source: "qrc:/road/car.png"
            fillMode: Image.PreserveAspectFit

            width: parent.width * 0.20
            height: parent.height * 0.25

            property real progress: 0.0

            NumberAnimation on progress {
                from: 0.0
                to: 0.65
                duration: 20000
                loops: Animation.Infinite
            }

            // Tọa độ Y: Chạy từ trên (0.05) xuống dưới
            y: (parent.height * 0.05) + (progress * parent.height * 0.9)
            // progress * 40 : Dạt rất mạnh sang trái khi tới gần để bám đúng giữa làn
            x: (parent.width / 2) - 10 - (progress * 40) - (width / 2)

            scale: 0.1 + (progress * 1.1)
            opacity: progress < 0.1 ? progress * 10 : (progress > 0.9 ? (1.0 - progress) * 10 : 1.0)
            z: progress
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.bottomMargin: 30
            anchors.leftMargin: 100
            spacing: 8

            Image {
                source: "qrc:/road/marker.svg"
                height: 18
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: remainingDistance.toFixed(1) + " KM"
                color: "white"
                font.pixelSize: 18
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Row {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.bottomMargin: 30
            anchors.rightMargin: 80
            spacing: 8

            Image {
                source: "qrc:/road/clock.svg"
                width: 18
                height: 18
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: remainingTime + " Min"
                color: "white"
                font.pixelSize: 18
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}