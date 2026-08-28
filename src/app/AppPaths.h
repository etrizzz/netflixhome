#pragma once

#include <QString>

class AppPaths final {
public:
    static QString configurationDirectory();
    static QString stateDirectory();
    static QString logDirectory();
    static bool ensureRuntimeDirectories();
};
