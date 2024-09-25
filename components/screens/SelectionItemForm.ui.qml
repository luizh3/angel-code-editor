import QtQuick 2.15
import QtQuick.Layouts 1.3

import theme 1.0

Rectangle {
    id: root
    width: 200
    height: 28
    radius: 4

    property string vDsIcon: ""
    property alias vDsOption: txtOption.text
    property alias mouseArea: mouseArea
    property alias imageIcon: imageIcon

    states: [
        State {
            when: mouseArea.containsMouse
            PropertyChanges {
                target: root
                color: Colors.gray600
            }
        },
        State {
            when: !mouseArea.containsMouse
            PropertyChanges {
                target: root
                color: Colors.gray800
            }
        }
    ]

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: 8
        spacing: 12

        Image {
            id: imageIcon
            Layout.preferredHeight: 24
            Layout.preferredWidth: 24
        }

        Text {
            id: txtOption
            font.pixelSize: 12
            color: Colors.white100
            Layout.fillWidth: true
            Layout.fillHeight: true
            verticalAlignment: Qt.AlignVCenter
        }
    }

    //@disable-check M224
    Behavior on color {
        ColorAnimation {
            duration: 200
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
    }
}
