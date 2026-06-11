import QtQuick 2.15

Item {

    property alias gaugeSource: img.source

    width: parent.width * 0.12
    height: parent.height * 0.45

    Image {
        id: img
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

    }
}