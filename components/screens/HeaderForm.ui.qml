import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

import theme 1.0
import elements 1.0

MenuBar {
    id: root
    height: 36
    width: 1024

    property alias menuItemOpenFolder: menuItemOpenFolder
    property alias menuItemShortcuts: menuItemShortcuts

    background: Rectangle {
        color: Colors.gray800

        Rectangle {
            id: marginBottom
            width: parent.width
            height: 1
            color: Colors.gray600
            anchors.top: parent.bottom
        }
    }

    component MenuBarItemCustom: MenuBarItem {
        id: menuBarItemCustom
        height: root.height

        property string title

        background: Rectangle {
            color: menuBarItemCustom.highlighted ? Colors.gray300 : Colors.gray800
        }

        contentItem: Text {
            text: menuBarItemCustom.title
            font.pixelSize: 16
            color: Colors.white100
        }
    }

    MenuBarItemCustom {
        title: qsTr("File")
        menu: MenuElement {

            MenuItemElement {
                id: menuItemOpenFolder
                text: qsTr("Open Folder...")
                width: parent.width
                vShortcuts: ["Ctrl", "O"]
            }

            MenuItemElement {
                id: menuItemShortcuts
                text: qsTr("Keyboard Shortcuts")
                width: parent.width
                vShortcuts: ["Ctrl", "I"]
            }
        }
    }
}
