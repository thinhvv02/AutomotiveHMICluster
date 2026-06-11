import QtQuick 2.15

Item {
    id: root
    width: 4
    height: 120

    transformOrigin: Item.Bottom

    Rectangle {
        anchors.fill: parent
        color: "red"
        radius: 2
        antialiasing: true
    }
}