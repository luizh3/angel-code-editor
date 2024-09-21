import QtQuick 2.15

TextEditorPanelForm {

    Shortcut {
        sequence: "Ctrl+W"
        onActivated: function () {

            function bindPosition() {
                return Qt.point(textArea.cursorPosition,
                                rowsList.indexCurrentRow)
            }

            textCompleter.currentPosition = Qt.binding(bindPosition)
            textCompleter.start()
        }
    }
}
