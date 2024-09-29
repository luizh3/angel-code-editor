import QtQuick 2.15

import theme 1.0

Rectangle {
    id: root
    color: Colors.gray800
    radius: 4
    border.color: Colors.gray300

    signal close

    anchors.centerIn: parent

    property alias contentItem: contentItem.children
    property string vTitle: ""

    MouseArea {
        anchors.fill: parent
    }

    component Header: Item {
        height: txtTitle.height
        width: parent.width

        property alias vTitle: txtTitle.text

        Text {
            id: txtTitle
            font.pixelSize: 18
            text: root.vTitle
            font.bold: true
            color: Colors.white100
        }
    }

    Header {
        id: header
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }

        anchors.margins: 24
    }

    Item {
        id: contentItem
        width: parent.width
        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: 24
        }
    }
}
