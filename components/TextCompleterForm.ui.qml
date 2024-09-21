import QtQuick 2.15

Rectangle {
    id: root
    color: "green"
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
        spacing: 1
        currentIndex: 1
        snapMode: ListView.NoSnap
        visible: root.hasSugestions

        delegate: Rectangle {
            width: 250
            height: 20
            color: ListView.isCurrentItem ? "blue" : "red"

            Text {
                text: modelData
                anchors.verticalCenter: parent.verticalCenter
                padding: 10
            }
        }
    }

    Rectangle {
        width: 250
        height: 20
        color: "red"
        visible: !root.hasSugestions

        Text {
            text: "No sugestions"
            anchors.verticalCenter: parent.verticalCenter
            padding: 10
        }
    }
}
