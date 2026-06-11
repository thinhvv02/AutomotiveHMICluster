import QtQuick 2.15
import QtQuick.Window 2.15
import "Data_Lab07/Common"

Window {
    width: 1280
    height: 800
    visible: true
    title: qsTr("Lab 07 - Model View")

    Image {
        id: bgApp
        anchors.fill: parent
        source: toggleBtn.statusBtn ? "qrc:/Data_Lab07/Img/lightBg.png" : "qrc:/Data_Lab07/Img/darkBg.png"
    }

    Image {
        id: topBar
        width: parent.width
        source: toggleBtn.statusBtn ? "qrc:/Data_Lab07/Img/top_light.png" : "qrc:/Data_Lab07/Img/top_dark.png"
        fillMode: Image.PreserveAspectFit
        anchors.top: parent.top
    }

    Image {
        id: bltIcon
        width: 60
        height: 60
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        source: toggleBtn.statusBtn ? "qrc:/Data_Lab07/Img/iconBltBlack.png" : "qrc:/Data_Lab07/Img/iconBltWhite.png"
    }

    Row {
        id: themeRow
        anchors.top: parent.top
        anchors.topMargin: 80
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Text {
            text: "THEME: LIGHT"
            color: "orange"
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
        }

        QToggleButton {
            id: toggleBtn
            colorButton: "orange" [cite, 213]
        }

        Text {
            text: "DARK"
            color: "orange"
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Row {
        id: inputRow
        anchors.top: themeRow.bottom
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Text {
            text: "MAC:"
            color: "orange"
            font.pixelSize: 20
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
        }

        QTextBox {
            id: txtMac
            widthBox: 400
            heighthBox: 50
            colorText: "orange" [cite, 220]
            colorBox: "orange"
        }

        Text {
            text: "Name"
            color: "orange"
            font.pixelSize: 20
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
        }

        QTextBox {
            id: txtName
            widthBox: 400
            heighthBox: 50
            colorText: "orange" [cite, 220]
            colorBox: "orange"
        }

        Rectangle {
            width: 60
            height: 50
            color: "orange"
            radius: 5

            Text {
                anchors.centerIn: parent
                text: "ADD"
                color: "white"
                font.bold: true
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    forceActiveFocus()
                    if (txtMac.text.trim() !== "" && txtName.text.trim() !== "") {
                        myBTModel.addDevice(txtMac.text, txtName.text)

                        txtMac.text = ""
                        txtName.text = ""
                    } else {
                        console.log("Dữ liệu trống, không thể thêm vào Model!")
                    }
                }
            }
        }
    }

    ListView {
        id: lvBluetooth
        width: 1180
        height: 550
        anchors.top: inputRow.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        model: myBTModel
        clip: true
        spacing: 5

        delegate: QDelegateBox {
            widthBox: 1180
            heightBox: 50

            widthBoxItem1: 80
            widthBoxItem2: 300
            widthBoxItem3: 300
            textIndex: index + 1
            textMacID: model.macAddress
            textNameDevice: model.deviceName

            fontSize: 18
            colorText: toggleBtn.statusBtn ? "black" : "white"
            colorBorderBox: "gray"
        }
    }
}