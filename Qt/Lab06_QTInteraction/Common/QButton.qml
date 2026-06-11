import QtQuick 2.15

Rectangle {
    id: root

    width: 80
    height: 40
    radius: 10

    signal clicked()

    // ===== STATE =====
    property bool isOn: false

    // ===== TEXT =====
    property string label: "BTN"

    // ===== COLOR =====
    color: isOn ? "#00ff00" : "#444"   

    border.width: 2
    border.color: "white"

   
    Text {
        anchors.centerIn: parent
        text: root.label
        color: "white"
        font.bold: true
    }


    // ===== CLICK =====
    MouseArea {
        anchors.fill: parent

        onClicked: {
            root.isOn = !root.isOn
            root.clicked()
            // toggle
        }
    }

    
    Behavior on color {
        ColorAnimation { duration: 150 }
    }
}
