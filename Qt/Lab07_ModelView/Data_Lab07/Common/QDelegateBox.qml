import QtQuick 2.15

Item {
    id: rootItem
    width: widthBox
    height: heightBox

    property int widthBox: 100
    property int widthBoxItem1: 50
    property int widthBoxItem2: 50
    property int widthBoxItem3: 50
    property int heightBox: 50
    property color colorBorderBox: "#FFFFFF"
    property color colorText: "#FFFFFF"
    property string textIndex: ""
    property string textMacID: ""
    property string textNameDevice: ""
    property int fontSize: 10
    Rectangle{
        id: bgRoot
        anchors.fill: parent
        color: "transparent"
        // anchors.centerIn: parent
        Row{
            // anchors.fill: parent
            spacing: 5
            anchors.centerIn: parent
            Rectangle{
                id: recIdx
                width: rootItem.widthBoxItem1
                height: rootItem.heightBox
                border.width: 2
                border.color: rootItem.colorBorderBox
                color: "transparent"
                radius: 5

                Text {
                    text: rootItem.textIndex
                    color: rootItem.colorText
                    anchors.verticalCenter: recIdx.verticalCenter
                    anchors.left: recIdx.left
                    anchors.leftMargin: 10
                    font.pixelSize: rootItem.fontSize
                    elide: Text.ElideRight
                    width: recIdx.width - 20
                }
            }
            Rectangle{
                id: recMacID
                width: rootItem.widthBoxItem2
                height: rootItem.heightBox
                border.width: 2
                border.color: rootItem.colorBorderBox
                color: "transparent"
                radius: 5

                Text {
                    text: rootItem.textMacID
                    color: rootItem.colorText
                    anchors.verticalCenter: recMacID.verticalCenter
                    anchors.left: recMacID.left
                    anchors.leftMargin: 10
                    font.pixelSize: rootItem.fontSize
                    elide: Text.ElideRight
                    width: recMacID.width - 20
                }
            }
            Rectangle{
                id: recNameDv
                width: rootItem.widthBoxItem3
                height: rootItem.heightBox
                border.width: 2
                border.color: rootItem.colorBorderBox
                color: "transparent"
                radius: 5
                // clip: true
                Text {
                    text: rootItem.textNameDevice
                    color: rootItem.colorText
                    anchors.verticalCenter: recNameDv.verticalCenter
                    anchors.left: recNameDv.left
                    anchors.leftMargin: 10
                    font.pixelSize: rootItem.fontSize
                    elide: Text.ElideRight
                    width: recNameDv.width - 20
                }
            }
        }
    }
}
