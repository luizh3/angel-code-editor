import QtQuick 2.15
import Control.LanguageSelectorModalControl 1.0

LanguageSelectorModalForm {
    id: root

    onConfirmed: root.handleOnConfirmed(isConfirmed)

    signal selected(var language)

    function handleOnConfirmed(isConfirmed) {
        root.vItems = []
        control.confirmed(isConfirmed)
    }

    function handleOnSelected(language) {
        root.selected(language)
        root.close()
    }

    function handleOptions(options) {
        root.vItems = options
    }

    LanguageSelectorModalControl {
        id: control

        onSelectOption: root.handleOptions(options)
        onSelected: root.handleOnSelected(language)
    }

    Component.onCompleted: control.doStart()
}
