import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import "components"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Angel Code Editor")
    color: "#181818"

    TextEditorPanel {
        anchors.fill: parent
    }
    footer: Rectangle {
        height: 20
        width: parent.width
        color: "#181818"

        Rectangle {
            width: parent.width
            height: 1
            color: "#2b2b2b"
        }
    }
}
