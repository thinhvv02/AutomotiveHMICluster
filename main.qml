import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: root
    visible: true
    title: "Nhóm 3 - Màn Hình Giải Trí"
    color: "#0b0f19"

    property string activePage: "home"
    property string currentTimeStr: "00:00"

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var date = new Date()
            root.currentTimeStr = Qt.formatDateTime(date, "HH:mm")
        }
    }

    Component.onCompleted: {
        var screenW = Screen.desktopAvailableWidth
        var screenH = Screen.desktopAvailableHeight

        // Setup khối Music: Chiếm 50% màn hình, lùi vào lề 2%
        root.width = screenW * 0.5
        root.height = 900  // Chiều cao chuẩn ôm vừa khít giao diện
        root.x = screenW * 0.02
        root.y = (screenH - root.height) / 2 // Căn giữa theo chiều dọc

        // KHÓA MÀN HÌNH CHÍNH
        root.minimumWidth = root.width
        root.maximumWidth = root.width
        root.minimumHeight = root.height
        root.maximumHeight = root.height

        var date = new Date()
        root.currentTimeStr = Qt.formatDateTime(date, "HH:mm")

        // Gọi màn hình Ô tô
        showCarWindow()
    }

    function navigateTo(pageId, pageUrl) {
        if (root.activePage !== pageId) {
            root.activePage = pageId
            stackView.replace(pageUrl)
        }
    }

    // TOP BAR
    Rectangle {
        id: topBar
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: rightBar.left
        color: "#151925"

        Rectangle {
            width: parent.width
            height: 1
            color: "#1e293b"
            anchors.bottom: parent.bottom
        }

        Text {
            text: {
                if (root.activePage === "home") return "Trang chủ"
                if (root.activePage === "music") return "Trình phát nhạc"
                if (root.activePage === "settings") return "Cài đặt"
                return "Trang chủ"
            }
            color: "white"
            font.bold: true
            font.pixelSize: 16
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.verticalCenter: parent.verticalCenter
        }

        Row {
            anchors.right: parent.right
            anchors.rightMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            spacing: 20

            Text { text: "25°C"; color: "#C3C3C3"; font.pixelSize: 14 }
            Text { text: root.currentTimeStr; color: "#C3C3C3"; font.pixelSize: 14 }

            Image { source: "qrc:/image_icons/wifi.png"; width: 25; height: 25; fillMode: Image.PreserveAspectFit }
            Image { source: "qrc:/image_icons/bluetooth.png"; width: 25; height: 25; fillMode: Image.PreserveAspectFit }
        }
    }
    //  RIGHT BAR MENU
    Rectangle {
        id: rightBar
        width: 80
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: "#151925"

        Rectangle {
            width: 1
            color: "#1e293b"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }

        Column {
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 25

            Repeater {
                model: [
                    { id: "home", icon: "app.png", page: "HomePage.qml" },
                    { id: "music", icon: "music.png", page: "MusicHub.qml" },
                    { id: "settings", icon: "setting.png", page: "SettingPage.qml" }
                ]
                delegate: Item {
                    width: 60
                    height: 60
                    anchors.horizontalCenter: parent.horizontalCenter

                    Rectangle {
                        anchors.fill: parent
                        radius: 18
                        visible: root.activePage === modelData.id
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "#c084fc" }
                            GradientStop { position: 1.0; color: "#db2777" }
                        }
                    }

                    Image {
                        source: "qrc:/image_icons/" + modelData.icon
                        width: 30
                        height: 30
                        anchors.centerIn: parent
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: root.navigateTo(modelData.id, modelData.page)
                    }
                }
            }
        }
    }

    StackView {
        id: stackView
        anchors.top: topBar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: rightBar.left
        initialItem: "HomePage.qml"

        replaceEnter: Transition { PropertyAnimation { property: "opacity"; from: 0.0; to: 1.0; duration: 250 } }
        replaceExit: Transition { PropertyAnimation { property: "opacity"; from: 1.0; to: 0.0; duration: 250 } }
    }
    // WINDOW MÀN HÌNH ĐIỀU KHIỂN Ô TÔ (BÊN PHẢI)
    Component {
        id: carWindowComponent
        Window {
            id: innerCarWindow
            title: "Nhóm 3 - Bảng Điều Khiển Xe"
            color: "#0f111a"
            flags: Qt.Window

            DashboardCar { anchors.fill: parent }

            Connections {
                target: innerCarWindow
                function onClosing(closeEvent) {
                    closeEvent.accepted = false
                    innerCarWindow.hide()
                }
            }
        }
    }

    property var carWindowInstance: null

    function showCarWindow() {
        if (carWindowInstance === null) {
            carWindowInstance = carWindowComponent.createObject(null)
        }

        var screenW = Screen.desktopAvailableWidth

        // Setup khối Car: Chiếm 50% màn hình, chừa lại khe hở 1% ở giữa 2 màn hình
        carWindowInstance.width = screenW * 0.50
        carWindowInstance.height = root.height // Ép bằng chiều cao màn Music (520)

        carWindowInstance.x = root.x + root.width + (screenW * 0.01) // Xếp ngay sát bên phải
        carWindowInstance.y = root.y // Phẳng hàng tuyệt đối với màn Music

        //  KHÓA MÀN HÌNH CHỤP Ô TÔ
        carWindowInstance.minimumWidth = carWindowInstance.width
        carWindowInstance.maximumWidth = carWindowInstance.width
        carWindowInstance.minimumHeight = carWindowInstance.height
        carWindowInstance.maximumHeight = carWindowInstance.height

        carWindowInstance.show()
        carWindowInstance.raise()
        carWindowInstance.requestActivate()
    }
}