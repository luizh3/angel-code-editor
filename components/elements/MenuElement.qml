import QtQuick 2.7
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

import theme 1.0

Menu {
    id: root
    width: 250

    background: Rectangle {
        id: rectangle
        implicitWidth: root.width
        radius: 4
        layer.enabled: true
        layer.effect: RectangularGlow {
            anchors.fill: rectangle
            glowRadius: 0
            spread: 0.1
            color: Colors.gray800
            cornerRadius: 15
        }
    }
}
