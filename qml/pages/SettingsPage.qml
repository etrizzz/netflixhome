import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    required property QtObject theme
    color: theme.background
    ColumnLayout {
        anchors.left: parent.left; anchors.top: parent.top; anchors.margins: 42; spacing: 18
        Label { text: qsTr("Paramètres"); color: theme.textPrimary; font.pixelSize: 32; font.bold: true }
        Switch {
            text: qsTr("Réduire les animations")
            checked: applicationController.settings.reduceMotion
            onToggled: applicationController.settings.reduceMotion = checked
            palette.windowText: theme.textPrimary
        }
        Label { text: qsTr("Version %1").arg(applicationController.version); color: theme.textSecondary }
    }
}
