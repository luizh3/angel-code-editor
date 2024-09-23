import QtQuick 2.15
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3

import theme 1.0

GenericModal {

    RectangularGlow {
        id: effect
        anchors.fill: rect
        glowRadius: 4
        spread: 0.2
        color: Colors.gray700
        cornerRadius: 8
    }

    Rectangle {
        id: rect
        anchors.fill: parent
        color: Colors.gray800
        radius: 4
        border.color: Colors.gray300

        ListView {
            id: listView
            model: 5
            anchors.fill: parent
            clip: true
            anchors.margins: 12
            delegate: Rectangle {
                color: mouseArea.containsMouse ? Colors.gray600 : Colors.gray800
                width: listView.width
                height: 25
                radius: 4

                RowLayout {
                    width: parent.width
                    spacing: 12

                    Image {
                        Layout.preferredHeight: 24
                        Layout.preferredWidth: 24
                        source: "../../resources/icons/c++.png"
                    }

                    Text {
                        text: "C++"
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
        }
    }
}
