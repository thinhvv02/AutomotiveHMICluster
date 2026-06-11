import QtQuick 2.15
import QtQuick.Window 2.15


Item {
    anchors.fill: parent

    // Trong DashboardCar.qml
    property real remainingDistance: 25.4
    property int remainingTime: 11

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            if (remainingDistance > 0) remainingDistance -= 0.01
            if (remainingTime > 0 && Math.random() > 0.8) remainingTime -= 1
        }
    }
    Item {
        id: mainContainer
        width: 1280; height: 480
        anchors.centerIn: parent
        scale: Math.min(parent.width / width, parent.height / height)
        Rectangle {
                    anchors.fill: parent
                    color: "#0f111a"
                    radius: 20
                }
        BottomBar {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.4
            height: 50
        }
        TopBar {
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.40
            height: parent.height * 0.18
        }
        LeftClock {
            width: parent.width * 0.4
            height: parent.height * 0.8
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.06
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 25
        }
        RightClock {
            width: parent.width * 0.35
            height: parent.height * 0.75
            anchors.right: parent.right
            anchors.rightMargin: parent.width * 0.09
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 25
        }
        Road {
            width: parent.width * 0.30
            height: parent.height * 0.7
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.07
        }
        LeftIcons {
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.verticalCenter: parent.verticalCenter
        }
        RightIcons {
            anchors.right: parent.right
            anchors.rightMargin: 25
            anchors.verticalCenter: parent.verticalCenter
        }
        SideGauge {
            id: leftGauge
            gaugeSource: "qrc:/icons/left.svg"
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 150
            anchors.bottomMargin: 20
        }
        Image {
            id: leftStatusIcon
            source: "qrc:/icons/feaul.svg"
            width: 30
            height: 30
            fillMode: Image.PreserveAspectFit
            anchors.bottom: leftGauge.top
            anchors.horizontalCenter: leftGauge.horizontalCenter
            anchors.horizontalCenterOffset:-60
            anchors.bottomMargin: -30
        }
        SideGauge {
            id: rightGauge
            gaugeSource: "qrc:/icons/right.svg"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 150
            anchors.bottomMargin: 15
        }

        Image {
            id: rightStatusIcon
            source: "qrc:/icons/desal.svg"
            width: 30
            height: 30
            fillMode: Image.PreserveAspectFit
            anchors.bottom: rightGauge.top
            anchors.horizontalCenter: rightGauge.horizontalCenter
            anchors.horizontalCenterOffset: 60
            anchors.bottomMargin: -30
        }
    }
}