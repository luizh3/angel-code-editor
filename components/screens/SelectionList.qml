import QtQuick 2.15

SelectionListForm {
    id: root

    signal confirmed(bool isConfirmed)

    function handleSelectItem(model) {
        model.isSelected = true
        root.confirmed(true)
    }
}
