import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Wizza.Media

ApplicationWindow {
    id: window
    width: 1360
    height: 820
    minimumWidth: 900
    minimumHeight: 600
    visible: true
    title: qsTr("Wizza Media Hub")
    color: theme.background

    Theme { id: theme }
    property string currentPage: "home"

    RowLayout {
        anchors.fill: parent
        spacing: 0
        Sidebar {
            theme: window.theme
            currentPage: window.currentPage
            onPageRequested: page => window.currentPage = page
        }
        Loader {
            Layout.fillWidth: true
            Layout.fillHeight: true
            sourceComponent: currentPage === "library" ? libraryPage
                           : currentPage === "sources" ? sourcesPage
                           : currentPage === "settings" ? settingsPage : homePage
        }
    }

    Component { id: homePage; HomePage { theme: window.theme } }
    Component { id: libraryPage; LibraryPage { theme: window.theme } }
    Component { id: sourcesPage; SourcesPage { theme: window.theme } }
    Component { id: settingsPage; SettingsPage { theme: window.theme } }
}
