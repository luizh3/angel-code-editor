import QtQuick 2.15

import theme 1.0

Rectangle {
    id: root
    color: Colors.gray800
    width: 100
    height: sugestionsListView.height

    property alias sugestions: sugestionsListView.model
    property alias sugestionsListView: sugestionsListView
    property alias currentIndex: sugestionsListView.currentIndex

    property bool hasSugestions: sugestions.length > 0

    ListView {
        id: sugestionsListView
        width: parent.width
        height: contentItem.childrenRect.height
        currentIndex: 1
        snapMode: ListView.NoSnap
        visible: root.hasSugestions

        delegate: Rectangle {
            width: 250
            height: 20
            color: ListView.isCurrentItem ? Colors.gray300 : Colors.gray800

            Text {
                text: modelData
                anchors.verticalCenter: parent.verticalCenter
                padding: 12
                color: Colors.white100
            }
        }
    }

    Rectangle {
        width: 250
        height: 20
        color: Colors.gray300
        visible: !root.hasSugestions

        Text {
            text: qsTr("No sugestions")
            anchors.verticalCenter: parent.verticalCenter
            padding: 10
            color: Colors.white100
        }
    }
}
