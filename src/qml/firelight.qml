import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 720
    height: 480

    // Main menu actions

    Action {
        id: openAction
        text: "&Open Project"
        shortcut: StandardKey.Open
        //iconSource: "images/document-open.png"
        //onTriggered: fileDialog.open()
        tooltip: "Open an existing project"
    }

    // Toolbar actions

    ExclusiveGroup {
        id: pointerModeGroup

        Action {
            id: pointerModeSelect
            text: "Select"
            checkable: true
            Component.onCompleted: checked = true
        }

        Action {
            id: pointerModeAdd
            text: "Add"
            checkable: true
        }
    }

    Action {
        id: actionShowLabels
        text: "Show Labels"
        checkable: true
    }

    Action {
        id: actionLockScene
        text: "Lock Scene"
        checkable: true
    }

    Action {
        id: actionShowCanvas
        text: "Show Canvas"
        checkable: true
    }

    Action {
        id: actionShowReferenceImage
        text: "Show Reference Image"
        checkable: true
    }

    Action {
        id: actionShowGrid
        text: "Show Grid"
        checkable: true
    }

    ExclusiveGroup {
        Action {
            id: actionRun
            tooltip: "Run"
            checkable: true
            iconSource: "../res/ic_play_arrow_black_24dp.png"
            onTriggered: {
                actionStep.enabled = false
            }
        }

        Action {
            id: actionStop
            tooltip: "Stop"
            checkable: true
            iconSource: "../res/ic_stop_black_24dp.png"
            onTriggered: {
                actionStep.enabled = false
            }
        }

        Action {
            id: actionFreeze
            tooltip: "Freeze"
            iconSource: "../res/ic_pause_black_24dp.png"
            checkable: true
            onTriggered: {
                actionStep.enabled = true
            }
        }
    }

    Action {
        id: actionStep
        text: "Step"
        enabled: false
    }

    Action {
        id: actionBlackout
        text: "Blackout"
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem { action: openAction }
        }
        Menu {
            title: "&Setup"
            MenuItem { text: "test" }
        }
    }

    toolBar: ToolBar {
        RowLayout {
            id: toolbarLayout
            spacing: 0
            width: parent.width

            ToolButton { action: pointerModeSelect }
            ToolButton { action: pointerModeAdd }

            Item { Layout.fillWidth: true }

            ToolButton { action: actionShowLabels }
            ToolButton { action: actionLockScene }
            ToolButton { action: actionShowCanvas }
            ToolButton { action: actionShowReferenceImage }
            ToolButton { action: actionShowGrid }

            Item { Layout.fillWidth: true }

            ToolButton { action: actionRun }
            ToolButton { action: actionFreeze }
            ToolButton { action: actionStop }
            ToolButton { action: actionStep }
            ToolButton { action: actionBlackout }

        }
    }


    statusBar: StatusBar {
        RowLayout {
            Image {
                source: "../res/ic_warning_amber_24dp.png"
            }
            Label {
                text: "Output Disabled"
            }
        }
    }
}
