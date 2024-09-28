import QtQuick 2.7
import QtQuick.Controls 2.15

import theme 1.0

MenuItem {
    id: root
    height: 36

    background: Rectangle {
        implicitWidth: root.width
        implicitHeight: root.height
        color: root.hovered ? Colors.gray300 : Colors.gray800
        border.color: Colors.gray600
    }
    contentItem: Text {
        id: txtLabel
        anchors.fill: parent
        text: root.text
        font.pixelSize: 16
        color: Colors.white100
        verticalAlignment: Text.AlignVCenter
        anchors.left: parent.left
        anchors.leftMargin: 8
    }
}
