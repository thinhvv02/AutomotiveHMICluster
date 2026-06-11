import QtQuick 2.15

Item {
    id: rootItem
    width: widthBox
    height: heighthBox
    property int widthBox: 100
    property int heighthBox: 50
    property color colorBox: "#FFFFFF"
    property color colorText: "#FFFFFF"

    // DÒNG QUAN TRỌNG NHẤT: Dùng 'alias' để link thuộc tính text của txtInput ra ngoài
    property alias text: txtInput.text

    Rectangle {
        id: bgTB
        anchors.fill: parent
        color: "transparent"
        border.width: 1
        border.color: rootItem.colorBox
        radius: 5
        clip: true

        TextInput {
            id: txtInput
            // Điền kín khung để click nhạy hơn
            anchors.fill: parent

            // Căn giữa chữ theo chiều dọc
            verticalAlignment: TextInput.AlignVCenter
            leftPadding: 10
            rightPadding: 10

            font.pixelSize: 30
            color: rootItem.colorText
        }
    }
}