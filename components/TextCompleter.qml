import QtQuick 2.15

import Control.TextCompleterControl 1.0

TextCompleterForm {
    id: root

    property alias textDocument: control.textDocument
    property alias currentPosition: control.currentPosition

    sugestions: control.sugestions

    TextCompleterControl {
        id: control
    }

    function onKeyPressed(event) {

        if (!root.visible) {
            return
        }

        switch (event.key) {
        case Qt.Key_Up:
            root.next()
            break
        case Qt.Key_Down:
            root.previus()
            break
        case Qt.Key_Return:
        case Qt.Key_Enter:
            event.accepted = true
            root.confirme()
            break
        case Qt.Key_Escape:
        case Qt.Key_Right:
        case Qt.Key_Left:
            root.reset()
            break
        default:
            break
        }
    }

    function next() {
        if (!root.hasSugestions) {
            return
        }
        if (root.currentIndex === 0) {
            return
        }
        root.currentIndex = root.currentIndex - 1
    }

    function previus() {
        if (!root.hasSugestions) {
            return
        }
        if (root.currentIndex === (root.sugestions.length - 1)) {
            return
        }
        root.currentIndex = root.currentIndex + 1
    }

    function reset() {
        control.currentPosition = Qt.point(0, 0)
        root.visible = false
    }

    function confirme() {
        const word = root.sugestions[root.currentIndex]
        control.completeSugestion(word)
        root.reset()
    }

    function start() {
        root.visible = true
    }
}
