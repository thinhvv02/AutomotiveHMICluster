import QtQuick 2.15

Item {
    id: root
    width: 150
    height: 150

    // Biến nhận góc quay từ C++
    property real angle: 0

    Item {
        id: needleGroup

        // Đặt mỏ neo tại tâm của QIndicator
        x: root.width / 2
        y: root.height / 2

        // Xoay quanh tâm
        transform: Rotation {
            origin.x: 0
            origin.y: 0
            angle: root.angle
        }

        property int needleLength: 70

        // THÂN KIM CHỈ BÁO (Chỉ dùng Rectangle theo đúng yêu cầu 2.5)
        Rectangle {
            width: 4
            height: needleGroup.needleLength
            color: "red"
            // Dùng thuộc tính radius để bo tròn đầu kim cho đẹp
            radius: 2

            x: -width / 2
            y: -height
        }
    }

    // NÚT TÂM KIM (Đứng yên - Dùng Rectangle bo tròn thành hình tròn)
    Rectangle {
        width: 16
        height: 16
        radius: 8 // width/2 sẽ ra hình tròn
        color: "darkred"
        border.color: "red"
        border.width: 2

        anchors.centerIn: parent
        z: 10
    }

    // Hiệu ứng quay mượt mà
    Behavior on angle {
        NumberAnimation {
            duration: 300
            easing.type: Easing.OutBack // Thêm hiệu ứng nảy nhẹ lúc dừng cho giống kim xe thật
        }
    }
}