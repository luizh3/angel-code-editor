import QtQuick 2.15

import Control.TextDocumentHandlerControl 1.0

TextEditorPanelForm {

    TextDocumentHandlerControl {
        id: control
        textDocument: textArea.textDocument
    }

    function handleChangeCurrentLanguage(language) {
        control.languageChanged(language)
        textCompleter.languageChanged(language)
    }

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
