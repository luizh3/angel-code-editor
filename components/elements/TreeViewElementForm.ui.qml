import QtQuick 2.15

import theme 1.0

Item {
    id: root

    property alias vModel: listView.model
    property int _idSelectedElement: -1
    signal selected(var file)

    ListView {
        id: listView
        delegate: treeNode
        height: parent.height
        contentHeight: contentItem.childrenRect.height
        width: parent.width
    }

    Component {
        id: treeNode
        Rectangle {
            width: 500
            height: rectangleContent.height
                    + (rectangleChildren.visible ? rectangleChildren.height : 0)
            color: Colors.gray800

            Rectangle {
                id: rectangleContent
                width: parent.width
                height: 36
                color: rectangleContent.isSelected ? Colors.gray600 : "transparent"
                radius: 4

                property bool isSelected: modelData.idFile === root._idSelectedElement

                MouseArea {
                    anchors.fill: parent

                    // @disable-check M222
                    onClicked: function handleOnSelectedElement() {
                        // @disable-check M223
                        if (modelData.isFolder) {
                            rectangleChildren.visible = !rectangleChildren.visible
                            // @disable-check M223
                        } else {
                            root._idSelectedElement = modelData.idFile
                            // @disable-check M222
                            root.selected(modelData)
                        }
                    }
                }

                Image {
                    id: imageArrow
                    width: 16
                    height: 16
                    source: rectangleChildren.visible ? "qrc:/resources/icons/down-arrow.png" : "qrc:/resources/icons/rigth-arrow.png"
                    anchors.verticalCenter: parent.verticalCenter
                    visible: modelData.isFolder
                }

                Image {
                    id: imagePath
                    width: 16
                    height: 16
                    source: `qrc:/resources/extensions/${modelData.dsIcon}`
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: imageArrow.right
                    anchors.leftMargin: 4
                }

                Text {
                    id: text
                    text: modelData.dsName
                    height: 16
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: imagePath.right
                    anchors.leftMargin: 4
                    font.pixelSize: 12
                    color: Colors.white100
                    font.family: "Roboto"
                    font.weight: Font.DemiBold
                }
            }

            Rectangle {
                id: rectangleChildren
                width: parent.width
                height: listView.height
                color: "transparent"
                visible: false
                anchors.top: rectangleContent.bottom
                x: parent.x + 10

                ListView {
                    id: listView
                    model: modelData.files
                    delegate: treeNode
                    width: parent.width
                    height: contentItem.childrenRect.height
                    anchors.top: rectangleContent.Bottom
                    interactive: false
                }
            }
        }
    }
}
