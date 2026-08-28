import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    required property QtObject theme
    color: theme.background
    ScrollView {
        anchors.fill: parent
        contentWidth: availableWidth
        ColumnLayout {
            width: parent.width
            spacing: 28
            anchors.margins: 42
            Label { text: qsTr("Bonsoir"); color: theme.textSecondary; font.pixelSize: 18 }
            Label { text: qsTr("Votre cinéma, enfin réuni."); color: theme.textPrimary; font.pixelSize: 38; font.bold: true }
            Rectangle {
                Layout.fillWidth: true; Layout.preferredHeight: 260; radius: theme.radius
                gradient: Gradient {
                    GradientStop { position: 0; color: theme.surfaceRaised }
                    GradientStop { position: 1; color: theme.accent }
                }
                Column {
                    anchors.left: parent.left; anchors.bottom: parent.bottom; anchors.margins: 30; spacing: 10
                    Label { text: qsTr("Bienvenue dans Wizza Media"); color: theme.textPrimary; font.pixelSize: 28; font.bold: true }
                    Label { text: qsTr("Ajoutez une bibliothèque pour commencer votre collection."); color: theme.textPrimary }
                }
            }
            Label { text: qsTr("Continuer à regarder"); color: theme.textPrimary; font.pixelSize: 24; font.bold: true }
            Label { text: qsTr("Vos lectures en cours apparaîtront ici."); color: theme.textSecondary }
        }
    }
}
