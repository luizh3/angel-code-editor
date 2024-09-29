import QtQuick 2.15
import QtQuick.Layouts 1.3

import theme 1.0
import elements 1.0

GenericModal {
    id: root

    vTitle: qsTr("Keyboard Shortcuts")

    component ShortcutElement: RowLayout {
        id: shortcutElementComponent
        spacing: 0
        height: 40

        required property string vDescription
        required property var vShortcuts

        Text {
            text: shortcutElementComponent.vDescription
            Layout.preferredHeight: shortcutElementComponent.height
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 16
            color: Colors.white100
        }
        KeywordList {
            words: shortcutElementComponent.vShortcuts
            Layout.preferredHeight: shortcutElementComponent.height
            Layout.alignment: Qt.AlignRight
        }
    }

    contentItem: Column {
        anchors.fill: parent

        ShortcutElement {
            width: parent.width
            vDescription: qsTr("Open Folder")
            vShortcuts: ["Ctrl", "O"]
        }

        ShortcutElement {
            width: parent.width
            vDescription: qsTr("Shortcuts")
            vShortcuts: ["Ctrl", "I"]
        }

        ShortcutElement {
            width: parent.width
            vDescription: qsTr("Save")
            vShortcuts: ["Ctrl", "S"]
        }
    }
}
