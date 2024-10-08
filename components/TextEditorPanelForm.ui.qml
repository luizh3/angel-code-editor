import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import theme 1.0

Item {
    id: root
    property alias textCompleter: textCompleter
    property alias textArea: textArea
    property alias rowsList: rowsList

    ScrollView {
        id: scrollView
        anchors.fill: parent

        RowLayout {
            spacing: 0
            width: Math.max(scrollView.implicitWidth, root.width)
            height: Math.max(scrollView.implicitHeight, root.height)

            Rectangle {
                color: Colors.gray600
                Layout.fillHeight: true
                Layout.preferredWidth: 1
            }

            RowsList {
                id: rowsList
                lineCount: textArea.lineCount
                lineCurrentY: textArea.cursorRectangle.y
                lineHeight: textArea.cursorRectangle.height
                Layout.alignment: Qt.AlignTop
                Layout.preferredWidth: 40
                Layout.fillHeight: true
                color: Colors.gray800
            }

            TextArea {
                id: textArea
                Layout.fillHeight: true
                Layout.fillWidth: true
                selectByMouse: true
                mouseSelectionMode: TextEdit.SelectCharacters
                color: Colors.white100
                selectionColor: Colors.gray300
                padding: 0
                topInset: 0
                textMargin: 0
                font.letterSpacing: 0
                font.wordSpacing: 0
                textFormat: TextEdit.MarkdownText
                //@disable-check M222
                Keys.onPressed: function (event) {
                    //@disable-check M222
                    textCompleter.onKeyPressed(event)
                }

                background: Rectangle {
                    color: Colors.gray700

                    Rectangle {
                        visible: textArea.selectedText.length === 0
                        width: parent.width
                        height: textArea.cursorRectangle.height
                        color: Colors.gray600
                        y: textArea.cursorRectangle.y
                        radius: 1
                    }
                }
                font.pixelSize: 16
            }
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
