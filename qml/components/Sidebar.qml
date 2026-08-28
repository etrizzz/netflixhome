import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    required property QtObject theme
    required property string currentPage
    signal pageRequested(string page)
    Layout.preferredWidth: 236
    Layout.fillHeight: true
    color: theme.surface

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10
        Label { text: "WIZZA"; color: theme.textPrimary; font.pixelSize: 26; font.bold: true }
        Label { text: qsTr("MEDIA HUB"); color: theme.accentBright; font.letterSpacing: 2 }
        Item { Layout.preferredHeight: 28 }
        Repeater {
            model: [
                { key: "home", label: qsTr("Accueil") },
                { key: "library", label: qsTr("Bibliothèque") },
                { key: "sources", label: qsTr("Sources") },
                { key: "settings", label: qsTr("Paramètres") }
            ]
            delegate: Button {
                required property var modelData
                Layout.fillWidth: true
                text: modelData.label
                flat: true
                highlighted: currentPage === modelData.key
                onClicked: pageRequested(modelData.key)
                palette.buttonText: highlighted ? theme.textPrimary : theme.textSecondary
                Accessible.name: text
            }
        }
        Item { Layout.fillHeight: true }
        Label { text: qsTr("Local · Privé · Sans publicité"); color: theme.textSecondary; wrapMode: Text.Wrap }
    }
}
