import QtQuick 2.15
Item {
    width: 120
    height: 440

    Timer {
        id: leftBlinkTimer
        interval: 500 // Tốc độ nháy 0.5s
        running: myController.turnLeft
        repeat: true
        property bool flash: false
        onTriggered: flash = !flash
        onRunningChanged: if (!running) flash = false
    }
    Image {
        source: (myController.turnLeft && leftBlinkTimer.flash)
                ? "qrc:/icons-left-checked/right-two.svg"
                : "qrc:/icons-left/right-two.svg"

        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 330
        anchors.top: parent.top
    }
    Image {
        source: "qrc:/icons-left/handbrake.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 290
        anchors.top: parent.top
        anchors.topMargin: 20
    }

    Image {
        source: myController.battery
                ? "qrc:/icons-left-checked/battery.svg"
                : "qrc:/icons-left/battery.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 250
        anchors.top: parent.top
        anchors.topMargin: 40
    }
    Image {
        source: "qrc:/icons-left/engine.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 210
        anchors.top: parent.top
        anchors.topMargin: 60
    }
    Image {
        source: myController.engineOil
                ? "qrc:/icons-left-checked/oil.svg"
                : "qrc:/icons-left/oil.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 170
        anchors.top: parent.top
        anchors.topMargin:80
    }
    Image {
        source: "qrc:/icons-left/tire.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.left: parent.left
        anchors.leftMargin: 130
        anchors.top: parent.top
        anchors.topMargin: 110
    }
}
