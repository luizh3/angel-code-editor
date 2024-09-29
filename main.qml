import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.0

import theme 1.0
import screens 1.0

import "components"

ApplicationWindow {
    id: root
    width: 1366
    height: 768
    visible: true
    title: qsTr("Angel Code Editor")
    color: Colors.gray800

    FolderDialog {
        id: folderDialog
        onFolderChanged: filesTree.open(folderDialog.currentFolder)
    }

    function handleOpenFolder() {
        folderDialog.open()
    }

    function handleShortcuts() {
        popupManager.push(keyboardShortcutsModalComponent)
    }

    header: Header {
        width: parent.width

        onOpenFolder: root.handleOpenFolder()
        onShortcuts: root.handleShortcuts()
    }

    PopupManager {
        id: popupManager
        anchors.fill: parent
    }

    Component {
        id: languageSelectorModalComponent
        LanguageSelectorModal {
            width: 600
            height: 500
            onSelected: textEditorPanel.handleChangeCurrentLanguage(language)
        }
    }

    Component {
        id: keyboardShortcutsModalComponent
        KeyboardShortcutsModal {
            width: 600
            height: 500
        }
    }

    RowLayout {
        anchors.fill: parent

        FilesTree {
            id: filesTree
            Layout.fillHeight: true
            Layout.preferredWidth: 280
            Layout.leftMargin: 12
            onSelected: textEditorPanel.readFile(file)
        }

        TextEditorPanel {
            id: textEditorPanel
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    footer: Footer {
        width: parent.width
        onLanguage: popupManager.push(languageSelectorModalComponent)
    }
}
