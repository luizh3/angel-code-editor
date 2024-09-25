import QtQuick 2.15

SelectionItemForm {
    id: root

    signal selected

    mouseArea.onClicked: root.selected()
    imageIcon.source: root.vDsIcon ? `qrc:/resources/icons/${root.vDsIcon}` : ""
}
