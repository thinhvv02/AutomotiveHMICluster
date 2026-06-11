import QtQuick 2.15

Item {
    id: rootItem
    width: widthBtn
    height: heightBtn

    property int widthBtn: 64
    property int heightBtn: 34
    property color colorButton: "#FFFFFF"
    property bool statusBtn: false

    Rectangle{
        id: bgBtn
        anchors.fill: rootItem
        radius: height/2
        color: "transparent"
        border.width: 1
        border.color: rootItem.colorButton

        Rectangle{
            id: pointBtn
            width: 30
            height: 30
            color: rootItem.colorButton
            anchors.verticalCenter: bgBtn.verticalCenter
            radius: height/2
            x: 2

            MouseArea{
                anchors.fill: parent
                onClicked:{
                    rootItem.statusBtn = !rootItem.statusBtn
                    if(rootItem.statusBtn) pointBtn.x = pointBtn.width +2
                    else pointBtn.x = 2
                    console.log("CLICK")
                }
            }
        }
    }
}
