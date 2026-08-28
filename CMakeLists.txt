cmake_minimum_required(VERSION 3.24)

project(WizzaMediaHub VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include(CTest)

find_package(Qt6 6.4 REQUIRED COMPONENTS
    Concurrent
    Network
    Quick
    QuickControls2
    Sql
    Svg
    Test
    WebEngineQuick
)

qt_standard_project_setup(REQUIRES 6.4)

add_executable(wizza-media
    src/main.cpp
    src/app/AppPaths.cpp
    src/app/AppPaths.h
    src/app/ApplicationController.cpp
    src/app/ApplicationController.h
    src/core/logging/Logger.cpp
    src/core/logging/Logger.h
    src/core/settings/SettingsService.cpp
    src/core/settings/SettingsService.h
)

qt_add_qml_module(wizza-media
    URI Wizza.Media
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/components/Sidebar.qml
        qml/pages/HomePage.qml
        qml/pages/LibraryPage.qml
        qml/pages/SourcesPage.qml
        qml/pages/SettingsPage.qml
        qml/theme/Theme.qml
)

target_link_libraries(wizza-media PRIVATE
    Qt6::Concurrent
    Qt6::Network
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Sql
    Qt6::Svg
    Qt6::WebEngineQuick
)

target_compile_definitions(wizza-media PRIVATE
    WIZZA_VERSION="${PROJECT_VERSION}"
    QT_NO_CAST_FROM_ASCII
)

if(BUILD_TESTING)
    add_executable(wizza-core-tests
        tests/unit/tst_skeleton.cpp
        src/app/AppPaths.cpp
        src/app/AppPaths.h
        src/core/settings/SettingsService.cpp
        src/core/settings/SettingsService.h
    )
    target_include_directories(wizza-core-tests PRIVATE src)
    target_link_libraries(wizza-core-tests PRIVATE Qt6::Core Qt6::Test)
    add_test(NAME wizza-core-tests COMMAND wizza-core-tests)
endif()

install(TARGETS wizza-media RUNTIME DESTINATION bin)
