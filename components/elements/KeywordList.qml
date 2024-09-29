import QtQuick 2.15
import theme 1.0

Row {
    id: root

    property alias words: repeater.model
    spacing: 4

    Repeater {
        id: repeater
        anchors.fill: parent

        Row {
            spacing: 4
            anchors.verticalCenter: parent.verticalCenter

            KeywordIcon {
                keyword: modelData
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                font.pixelSize: 12
                text: "+"
                color: Colors.white100
                anchors.verticalCenter: parent.verticalCenter
                visible: index !== words.length - 1
            }
        }
    }
}
