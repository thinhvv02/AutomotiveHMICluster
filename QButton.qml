import QtQuick 2.15

Rectangle {
    id: root
    property string text: "Button"
    property bool isActive: false
    signal clicked()
    width: 100
    height: 40
    radius: 8
    color: isActive ? "#3498db" : "#95a5a6"
    Text {
        text: root.text
        anchors.centerIn: parent
        color: "white"
        font.bold: true
        font.pixelSize: 14
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}