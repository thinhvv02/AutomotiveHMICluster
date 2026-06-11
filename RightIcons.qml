import QtQuick 2.15

Item {
    width: 120
    height: 440

    Timer {
            id: rightBlinkTimer
            interval: 500 // Tốc độ nháy 0.5s
            running: myController.turnRight
            repeat: true
            property bool flash: false
            onTriggered: flash = !flash
            onRunningChanged: if (!running) flash = false
        }

    Image {
            source: (myController.turnRight && rightBlinkTimer.flash)
                    ? "qrc:/icons-right-checked/right-two.svg"
                    : "qrc:/icons-right/right-two.svg"

            width: 30; height: 30; fillMode: Image.PreserveAspectFit
            anchors.right: parent.right
            anchors.rightMargin: 330
            anchors.top: parent.top
        }
    Image {
        source: "qrc:/icons-right/seatbelt.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.right: parent.right
        anchors.rightMargin: 290
        anchors.top: parent.top
        anchors.topMargin: 20
    }


    Image {
        source: "qrc:/icons-right/parking.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.right: parent.right
        anchors.rightMargin: 250
        anchors.top: parent.top
        anchors.topMargin: 40
    }
    Image {
        source: myController.hiBeam
                        ? "qrc:/icons-right-checked/light-high.svg"
                        : "qrc:/icons-right/light-high.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.right: parent.right
        anchors.rightMargin: 210
        anchors.top: parent.top
        anchors.topMargin: 60
    }
    Image {
        source: myController.fogLight
                        ?"qrc:/icons-right/light-fog.svg"
                        :"qrc:/icons-right/light-fog2.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.right: parent.right
        anchors.rightMargin: 180
        anchors.top: parent.top
        anchors.topMargin: 90
    }
    Image {
        source: myController.dimLight
                        ?"qrc:/icons-right/light-dimmed.svg"
                        :"qrc:/icons-right/light-dimmed2.svg"
        width: 30; height: 30; fillMode: Image.PreserveAspectFit
        anchors.right: parent.right
        anchors.rightMargin: 150
        anchors.top: parent.top
        anchors.topMargin: 120
    }

}