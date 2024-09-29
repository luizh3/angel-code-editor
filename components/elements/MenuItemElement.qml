import QtQuick 2.7
import QtQuick.Controls 2.15

import theme 1.0

MenuItem {
    id: root
    height: 36

    property alias vShortcuts: keywordList.words

    Shortcut {
        sequence: vShortcuts.join("+")
        onActivated: root.triggered()
    }

    background: Rectangle {
        implicitWidth: root.width
        implicitHeight: root.height
        color: root.hovered ? Colors.gray300 : Colors.gray800
        border.color: Colors.gray600
    }
    contentItem: Item {
        anchors.fill: parent

        Text {
            id: txtLabel
            text: root.text
            font.pixelSize: 14
            color: Colors.white100
            verticalAlignment: Text.AlignVCenter
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.verticalCenter: parent.verticalCenter
        }
        KeywordList {
            id: keywordList
            anchors.right: parent.right
            anchors.rightMargin: 8
            height: parent.height
        }
    }
}
