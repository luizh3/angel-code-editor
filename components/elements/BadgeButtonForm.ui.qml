import QtQuick 2.15
import QtQuick.Layouts 1.3

import theme 1.0

Rectangle {

    property alias mouseArea: mouseArea

    property alias vLabel: txtLabel.text

    width: 80
    height: 25
    color: mouseArea.containsMouse ? Colors.gray600 : Colors.gray800

    Text {
        id: txtLabel
        text: qsTr("Language")
        color: Colors.white100
        anchors.centerIn: parent
        font.pixelSize: 12
    }

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent
    }
}
