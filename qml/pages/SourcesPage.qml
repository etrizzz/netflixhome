import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    required property QtObject theme
    color: theme.background
    ColumnLayout {
        anchors.centerIn: parent; spacing: 14
        Label { text: qsTr("Sources"); color: theme.textPrimary; font.pixelSize: 32; font.bold: true }
        Label { text: qsTr("Les supports ne sont jamais indexés sans votre accord."); color: theme.textSecondary }
    }
}
