import QtQuick 2.15

BadgeButtonForm {

    id: root

    signal clicked

    Behavior on color {
        ColorAnimation {
            duration: 200
        }
    }

    mouseArea.onClicked: root.clicked()
}
