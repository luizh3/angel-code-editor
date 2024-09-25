import QtQuick 2.15

FooterForm {
    id: root

    signal language

    badgetButtonLanguage.onClicked: root.language()
}
