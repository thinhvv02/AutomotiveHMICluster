import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: rootWindow
    width: 1280
    height: 720
    visible: true
    title: qsTr("Giao diện Dashboard - Step 1: Nền Panel")

    color: "white"

    Image {
        id: dashboardBackground
        source: "qrc:/img_Lab05/Panel.png"
        anchors.centerIn: parent
        width: parent.width * 0.9
        height: parent.height * 0.9
        fillMode: Image.PreserveAspectFit
        z: 0

        Image {
            id: leftTempGauge
            source: "qrc:/img_Lab05/icons/Untitled2-removebg-preview.png"
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: parent.width * 0.028
            anchors.bottomMargin: parent.height * 0.05
            width: parent.width * 0.2
            height: parent.height * 0.5
            fillMode: Image.PreserveAspectFit
            z: 1
        }

        Image {
            id: rightFuelGauge
            source: "qrc:/img_Lab05/icons/Untitled-removebg-preview.png"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: parent.width * 0.028
            anchors.bottomMargin: parent.height * 0.05
            width: parent.width * 0.2
            height: parent.height * 0.5
            fillMode: Image.PreserveAspectFit
            z: 1
        }

        Image {
            id: leftDial
            source: "qrc:/img_Lab05/Tacometer.png"
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.05
            anchors.verticalCenterOffset: parent.height * 0.05
            width: parent.width * 0.35
            height: width
            fillMode: Image.PreserveAspectFit
            z: 1

            Rectangle {
                id: leftNeedle
                width: 4
                height: parent.height * 0.35
                color: "red"
                transformOrigin: Item.Bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.verticalCenter
                antialiasing: true
                z: 9
                rotation: -120
            }

            Rectangle {
                width: 30
                height: 30
                radius: 15
                color: "#2C2C2C"
                border.color: "#888888"
                border.width: 2
                anchors.centerIn: parent
                z: 10
            }
        }

        Image {
            id: rightDial
            source: "qrc:/img_Lab05/Speedometer.png"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: parent.width * 0.05
            anchors.verticalCenterOffset: parent.height * 0.05
            width: parent.width * 0.35
            height: width
            fillMode: Image.PreserveAspectFit
            z: 1

            Rectangle {
                id: rightNeedle
                width: 4
                height: parent.height * 0.35
                color: "red"
                transformOrigin: Item.Bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.verticalCenter
                antialiasing: true
                z: 9
                rotation: -118
            }

            Rectangle {
                width: 30
                height: 30
                radius: 15
                color: "#2C2C2C"
                border.color: "#888888"
                border.width: 2
                anchors.centerIn: parent
                z: 10
            }
        }

        Image {
            id: tempWarningIcon
            source: "qrc:/img_Lab05/icons/feaul.svg"
            width: 30; height: 30
            fillMode: Image.PreserveAspectFit
            z: 5
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: parent.width * 0.035
            anchors.verticalCenterOffset: parent.height * 0.01
        }

        Image {
            id: fuelWarningIcon
            source: "qrc:/img_Lab05/icons/desal.svg"
            width: 30; height: 30
            fillMode: Image.PreserveAspectFit
            z: 5
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: parent.width * 0.035
            anchors.verticalCenterOffset: parent.height * 0.01
        }

        Item {
            id: speedLimitBlock
            x: parent.width * 0.35
            y: parent.height * 0.25
            width: 50
            height: 90
            z: 5

            Image {
                id: speedLimitBg
                source: "qrc:/img_Lab05/icons/Road/Frame 33.png"
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }

            Text {
                text: "90"
                color: "black"
                font.pixelSize: 40
                font.bold: true
                anchors.centerIn: parent
                anchors.verticalCenterOffset: 12
            }
        }

        Item {
            id: navTurnBlock
            anchors.horizontalCenter: parent.horizontalCenter
            y: parent.height * 0.26
            width: 150
            height: 80
            z: 5

            Image {
                id: turnArrow
                source: "qrc:/img_Lab05/icons/Road/mdi_turn-right-bold.svg"
                width: 40; height: 40
                anchors.left: parent.left
                anchors.top: parent.top
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: distanceText
                text: "372 m"
                color: "white"
                font.pixelSize: 26
                font.bold: true
                anchors.left: turnArrow.right
                anchors.leftMargin: 10
                anchors.top: parent.top
            }

            Text {
                text: "Enter SL Street and\ntake first right"
                color: "#A0FFFFFF"
                font.pixelSize: 11
                anchors.left: distanceText.left
                anchors.top: distanceText.bottom
                anchors.topMargin: 2
            }
        }

        Image {
            id: steeringWheelNav
            source: "qrc:/img_Lab05/icons/Road/mingcute_steering-wheel-fill.svg"
            x: parent.width * 0.58
            y: parent.height * 0.27
            width: 75
            height: 75
            fillMode: Image.PreserveAspectFit
            z: 5
        }

        Row {
            id: distanceInfo
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.28
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: -parent.width * 0.08
            spacing: 8

            Image {
                id: locationIcon
                source: "qrc:/img_Lab05/icons/Road/mdi_map-marker-outline.svg"
                width: 20
                height: 20
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: "26 KM"
                color: "white"
                font.pixelSize: 20
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Row {
            id: timeInfo
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.28
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: parent.width * 0.08
            spacing: 8

            Image {
                id: clockIcon
                source: "qrc:/img_Lab05/icons/Road/mdi_clock-time-four-outline.svg"
                width: 20
                height: 20
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                text: "22 Min"
                color: "white"
                font.pixelSize: 20
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Item {
            id: rightWarningIcons
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.topMargin: parent.height * 0.12
            anchors.rightMargin: parent.width * 0.15
            width: 200
            height: 200
            z: 2

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/icon-park-solid_right-two.svg"
                width: 22; height: 22
                fillMode: Image.PreserveAspectFit
                x: 80; y: 30
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/mdi_seatbelt.svg"
                width: 26; height: 26
                fillMode: Image.PreserveAspectFit
                x: 130; y: 50
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/mdi_car-brake-parking.svg"
                width: 26; height: 26
                fillMode: Image.PreserveAspectFit
                x: 180; y: 70
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/mdi_car-light-dimmed.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: 220; y: 95
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/mdi_car-light-high.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: 250; y: 120
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-right/mdi_car-light-fog.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: 280; y: 150
            }
        }

        Item {
            id: leftWarningIcons
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: parent.height * 0.12
            anchors.leftMargin: parent.width * 0.15
            width: 200
            height: 200
            z: 2

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/icon-park-solid_right-two.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: 80; y: 30
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/mdi_car-handbrake.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: 30; y: 50
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/mdi_car-battery.svg"
                width: 28; height: 28
                fillMode: Image.PreserveAspectFit
                x: -20; y: 70
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/ph_engine-bold.svg"
                width: 26; height: 26
                fillMode: Image.PreserveAspectFit
                x: -60; y: 95
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/mdi_oil.svg"
                width: 26; height: 26
                fillMode: Image.PreserveAspectFit
                x: -90; y: 120
            }

            Image {
                source: "qrc:/img_Lab05/icons/icons-left/mdi_car-tire-alert.svg"
                width: 22; height: 22
                fillMode: Image.PreserveAspectFit
                x: -120; y: 150
            }
        }

        Image {
            id: topBar
            source: "qrc:/img_Lab05/Top Bar.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.1
            width: parent.width * 0.6
            height: parent.height * 0.15
            fillMode: Image.PreserveAspectFit
            z: 1

            Row {
                anchors.left: parent.left
                anchors.leftMargin: parent.width * 0.20
                anchors.verticalCenter: parent.verticalCenter
                spacing: 8

                Image {
                    id: cloudIcon
                    source: "qrc:/img_Lab05/icons/cloud.svg"
                    width: 24
                    height: 24
                    fillMode: Image.PreserveAspectFit
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: "12 °C"
                    color: "white"
                    font.pixelSize: 18
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Text {
                anchors.right: parent.right
                anchors.rightMargin: parent.width * 0.20
                anchors.verticalCenter: parent.verticalCenter
                text: "12:14 AM"
                color: "white"
                font.pixelSize: 18
                font.bold: true
            }
        }

        Image {
            id: bottomBar
            source: "qrc:/img_Lab05/icons/bottom.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.1
            width: parent.width * 0.4
            height: parent.height * 0.10
            fillMode: Image.PreserveAspectFit
            z: 1
        }

        Image {
            id: road
            source: "qrc:/img_Lab05/icons/Road/road2.png"
            anchors.centerIn: parent
            width: parent.width * 0.5
            height: parent.height * 0.5
            fillMode: Image.PreserveAspectFit
            z: 0

            Image {
                id: car
                source: "qrc:/img_Lab05/icons/Road/car.png"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 25
                anchors.bottom: parent.bottom
                anchors.bottomMargin: parent.height * 0.15
                width: road.width * 0.15
                height: road.height * 0.15
                fillMode: Image.PreserveAspectFit
                z: 1
            }
        }

        Image {
            id: car2
            source: "qrc:/img_Lab05/icons/Road/car.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: -15
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height * 0.55
            width: road.width * 0.08
            height: road.height * 0.08
            fillMode: Image.PreserveAspectFit
            z: 1
        }
    }
}