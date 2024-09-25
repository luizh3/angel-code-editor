import QtQuick 2.15
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.3

import theme 1.0

GenericModal {
    id: root

    RectangularGlow {
        id: effect
        anchors.fill: rect
        glowRadius: 4
        spread: 0.2
        color: Colors.gray700
        cornerRadius: 8
    }

    property alias vItems: listView.model

    Rectangle {
        id: rect
        anchors.fill: parent
        color: Colors.gray800
        radius: 4
        border.color: Colors.gray300

        ListView {
            id: listView
            anchors.fill: parent
            clip: true
            anchors.margins: 12
            model: 5
            delegate: SelectionItem {
                width: listView.width
                vDsIcon: modelData.dsIcon ?? ""
                vDsOption: modelData.dsOption ?? ""

                Connections {
                    function onSelected() {
                        handleSelectItem(modelData)
                    }
                }
            }
        }
    }
}
