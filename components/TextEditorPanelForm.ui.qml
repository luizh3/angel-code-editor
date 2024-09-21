import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import Control.TextDocumentHandlerControl 1.0

Item {

    TextDocumentHandlerControl {
        textDocument: textArea.textDocument
    }

    property alias textCompleter: textCompleter
    property alias textArea: textArea
    property alias rowsList: rowsList

    RowLayout {
        anchors.fill: parent
        spacing: 0

        RowsList {
            id: rowsList
            lineCount: textArea.lineCount
            lineCurrentY: textArea.cursorRectangle.y
            lineHeight: textArea.cursorRectangle.height
            Layout.alignment: Qt.AlignTop
        }

        TextArea {
            id: textArea
            Layout.fillHeight: true
            Layout.fillWidth: true
            selectByMouse: true
            mouseSelectionMode: TextEdit.SelectCharacters
            color: "#FFFFFF"
            selectionColor: "gray"
            padding: 0
            topInset: 0
            textMargin: 0
            font.letterSpacing: 0
            font.wordSpacing: 0

            //@disable-check M222
            Keys.onPressed: function (event) {
                //@disable-check M222
                textCompleter.onKeyPressed(event)
            }

            background: Rectangle {
                color: "#1f1f1f"

                Rectangle {
                    visible: textArea.selectedText.length === 0
                    width: parent.width
                    height: textArea.cursorRectangle.height
                    color: "#2b2b2b"
                    y: textArea.cursorRectangle.y
                    radius: 1
                }
            }
            font.pixelSize: 16
        }
    }

    TextCompleter {
        id: textCompleter
        textDocument: textArea.textDocument
        y: textArea.cursorRectangle.y + textArea.cursorRectangle.height + 3
        x: textArea.cursorRectangle.x + (textCompleter.width / 2)
        visible: false
    }
}
