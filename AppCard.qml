import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    property string title: "App"
    property string iconSource: ""
    property string color1: "#6366f1"
    property string color2: "#ec4899"

    signal clicked()

    Layout.fillWidth: true
    Layout.preferredHeight: 130
    color: "#151925"
    radius: 15

    Column {
        anchors.centerIn: parent
        spacing: 12
        Rectangle {
            width: 50; height: 50; radius: 15
            anchors.horizontalCenter: parent.horizontalCenter
            gradient: Gradient {
                GradientStop { position: 0.0; color: color1 }
                GradientStop { position: 1.0; color: color2 }
            }
            Image {
                    source: iconSource
                    width: 30
                    height: 30
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                }
        }
        Text {
            text: title
            color: "white"
            font.pixelSize: 15
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onEntered: parent.color = "#1e2436" // Hiệu ứng khi hover
        onExited: parent.color = "#151925"
        onClicked: parent.clicked()
    }
}