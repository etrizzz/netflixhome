import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    required property QtObject theme
    color: theme.background
    ColumnLayout {
        anchors.centerIn: parent; spacing: 14
        Label { Layout.alignment: Qt.AlignHCenter; text: qsTr("Votre bibliothèque vous attend"); color: theme.textPrimary; font.pixelSize: 30; font.bold: true }
        Label { Layout.alignment: Qt.AlignHCenter; text: qsTr("L'indexation locale sera activée après la fondation applicative."); color: theme.textSecondary }
    }
}
