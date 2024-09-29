import QtQuick 2.15

import theme 1.0

Rectangle {
    id: keyboardIcon
    width: textKeyword.width
    height: textKeyword.height

    property string keyword

    radius: 4
    border.color: Colors.gray600
    color: Colors.gray600

    Text {
        id: textKeyword
        text: keyboardIcon.keyword
        anchors.centerIn: parent
        font.pixelSize: 12
        topPadding: 4
        bottomPadding: 4
        leftPadding: 8
        rightPadding: 8
        font.bold: true
        color: Colors.white100
    }
}
