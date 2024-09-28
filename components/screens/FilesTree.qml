import QtQuick 2.15
import elements 1.0

import Control.FolderControl 1.0

TreeViewElement {
    id: root

    function handleFilesChanged(files) {
        root.vModel = files
    }

    function open(dsPath) {
        folderControl.open(dsPath)
    }

    FolderControl {
        id: folderControl
        onFilesChanged: root.handleFilesChanged(files)
    }
}
