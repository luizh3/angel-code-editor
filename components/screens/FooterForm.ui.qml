import QtQuick 2.15
import QtQuick.Layouts 1.3

import theme 1.0
import elements 1.0

Rectangle {
    height: 20
    width: 1024
    color: Colors.gray800

    property alias badgetButtonLanguage: badgetButtonLanguage

    Rectangle {
        id: marginTop
        width: parent.width
        height: 1
        color: Colors.gray600
    }

    RowLayout {
        width: parent.width
        height: parent.height
        anchors.right: parent.right
        layoutDirection: Qt.RightToLeft

        BadgeButton {
            id: badgetButtonLanguage
            Layout.preferredHeight: parent.height - marginTop.height
            Layout.alignment: Qt.AlignVCenter
            Layout.preferredWidth: 80
        }
    }
}
