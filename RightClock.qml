import QtQuick 2.15

Item {
    Image {
        id: bgClock
        anchors.fill: parent
        source: "qrc:/Speedometer.png"
        fillMode: Image.PreserveAspectFit
    }

    QIndicator {
        id: speedNeedle
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.verticalCenter
        rotation: myController.speedAngle

        Behavior on rotation { NumberAnimation { duration: 200 } }
    }

    // THÊM HÌNH TRÒN TẠI TÂM (ĐUÔI KIM)
    Rectangle {
        width: 20
        height: 20
        radius: 10
        color: "#111111" // Màu tối phù hợp với nền bảng điều khiển
        border.color: "#555555"
        border.width: 2
        anchors.centerIn: parent
    }
}