import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

import "components"

ApplicationWindow {
    id: root
    title: qsTr("Firelight")
    visible: true
    width: 720
    height: 480
    minimumHeight: 400
    minimumWidth: 600

    // Main menu actions

    Action {
        id: openAction
        text: "&Open Project"
        shortcut: StandardKey.Open
        //iconSource: "images/document-open.png"
        //onTriggered: fileDialogroot@pipboy:/media/nas1/downloads#.open()
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
            iconSource: "../res/pointer.png"
        }

        Action {
            id: pointerModeAdd
            text: "Add"
            checkable: true
            iconSource: "../res/ic_add_circle_black_24dp.png"
        }
    }

    Action {
        id: actionShowLabels
        text: "Show Labels"
        checkable: true
        iconSource: checked ? "../res/ic_label_black_24dp.png" : "../res/ic_label_outline_black_24dp.png"
    }

    Action {
        id: actionLockScene
        text: "Lock Scene"
        checkable: true
        iconSource: checked ? "../res/ic_lock_outline_black_24dp.png" : "../res/ic_lock_open_black_24dp.png"
    }

    Action {
        id: actionShowCanvas
        text: "Show Canvas"
        checkable: true
        iconSource:"../res/ic_aspect_ratio_black_24dp.png"
    }

    Action {
        id: actionShowReferenceImage
        text: "Show Reference Image"
        checkable: true
        iconSource:"../res/ic_now_wallpaper_black_24dp.png"
        Component.onCompleted: checked = true
    }

    Action {
        id: actionShowGrid
        text: "Show Grid"
        checkable: true
        iconSource: "../res/ic_border_all_black_24dp.png"
        Component.onCompleted: checked = true
    }

    ExclusiveGroup {
        Action {
            id: actionRun
            tooltip: "Run"
            checkable: true
            iconSource: "../res/ic_play_arrow_black_24dp.png"
            Component.onCompleted: checked = true
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
        iconSource: enabled ? "../res/ic_skip_next_black_24dp.png" : "../res/ic_skip_next_grey600_24dp.png"
    }

    Action {
        id: actionNext
        text: "Next"
        iconSource: "../res/ic_fast_forward_black_24dp.png"
    }

    Action {
        id: actionPrev
        text: "Previous"
        iconSource: "../res/ic_fast_rewind_black_24dp.png"
    }

    Action {
        id: actionBlackout
        text: "Blackout"
        checkable: true
        iconSource: checked ? "../res/ic_brightness_low_black_24dp.png" : "../res/ic_brightness_high_black_24dp.png"
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem { action: openAction }
        }
        Menu {
            title: "&Setup"
            MenuItem {
                text: "test"

            }
        }
    }

    toolBar: ToolBar {
        RowLayout {
            id: toolbarLayout
            spacing: 5
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
            ToolButton { action: actionStep }
            ToolButton { action: actionFreeze }
            ToolButton { action: actionStop }
            ToolButton { action: actionPrev }
            ToolButton { action: actionNext }

            ToolButton { action: actionBlackout }

        }
    }

    Viewport {
        anchors.fill: parent

        Surface {

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
