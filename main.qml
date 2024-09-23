import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import theme 1.0
import screens 1.0

import "components"

ApplicationWindow {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Angel Code Editor")
    color: Colors.gray800

    PopupManager {
        id: popupManager
        anchors.fill: parent
    }

    Component {
        id: languageSelecter
        LanguageSelectorModal {
            width: 600
            height: 500
            anchors.centerIn: parent
        }
    }

    Component.onCompleted: function () {
        popupManager.push(languageSelecter)
    }

    TextEditorPanel {
        anchors.fill: parent
    }
    footer: Rectangle {
        height: 20
        width: parent.width
        color: Colors.gray800

        Rectangle {
            width: parent.width
            height: 1
            color: Colors.gray600
        }
    }
}
