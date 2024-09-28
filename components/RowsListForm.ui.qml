import QtQuick 2.15

import QtQuick.Layouts 1.3

import theme 1.0

Rectangle {
    id: root
    property alias lineCount: repeater.model
    property int lineCurrentY: 0
    property int lineHeight: 0
    readonly property alias indexCurrentRow: columnRows.indexCurrentRow
    width: 40

    Column {
        id: columnRows
        width: parent.width
        spacing: 0

        property int indexCurrentRow: 0

        Repeater {
            id: repeater
            width: parent.width

            Rectangle {
                id: rectangle
                width: parent.width

                height: root.lineHeight
                color: Colors.gray800

                property bool isCurrentRow: root.lineCurrentY === rectangle.y

                Connections {
                    target: rectangle

                    function onIsCurrentRowChanged() {
                        if (rectangle.isCurrentRow) {
                            columnRows.indexCurrentRow = index
                        }
                    }
                }

                Text {
                    text: index + 1
                    color: rectangle.isCurrentRow ? Colors.white100 : Colors.gray300
                    anchors.centerIn: parent
                }
            }
        }
    }
}
