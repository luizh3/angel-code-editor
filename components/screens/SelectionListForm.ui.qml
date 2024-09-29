import QtQuick 2.15
import QtQuick.Layouts 1.3

import theme 1.0

GenericModal {
    id: root

    property alias vItems: listView.model

    vTitle: qsTr("Languages")

    contentItem: ListView {
        id: listView
        clip: true
        model: 5
        anchors.fill: parent
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
