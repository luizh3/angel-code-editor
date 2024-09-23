import QtQuick 2.15
import QtQuick.Controls 2.15

import theme 1.0

Item {
    id: root

    function pop() {

        if (stack.depth === 1) {
            root.clear()
            return
        }

        stack.pop()
        stack.onPop()
    }

    function push(popup) {
        var popupCreated = stack.push(popup)
        stack.onPush()
        popupCreated.close.connect(function onRemove() {
            popupCreated.close.disconnect(onRemove)
            root.pop()
        })
        return popupCreated
    }

    function clear() {
        stack.clear()
        stack.onPop()
    }

    StackView {
        id: stack
        anchors.fill: parent
        parent: Overlay.overlay
        visible: false

        property int _duration: 200

        function hide() {
            stack.visible = false
        }

        function show() {
            stack.visible = true
        }

        function onPush() {
            stack.show()
        }

        function onPop() {
            stack.hide()
        }

        background: Rectangle {
            // opacity: 0.3
            // color: Colors.white100
            color: "transparent"

            MouseArea {
                anchors.fill: parent
            }
        }
        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: root.duration
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: root.duration
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: root.duration
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: root.duration
            }
        }
    }
}
