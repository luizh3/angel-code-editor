import QtQuick 2.15

HeaderForm {
    id: root

    signal openFolder
    signal shortcuts

    menuItemOpenFolder.onTriggered: root.openFolder()
    menuItemShortcuts.onTriggered: root.shortcuts()
}
