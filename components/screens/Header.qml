import QtQuick 2.15

HeaderForm {
    id: root

    signal openFolder

    menuItemOpenFolder.onTriggered: root.openFolder()
}
