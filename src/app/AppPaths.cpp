#include "AppPaths.h"

#include <QDir>
#include <QStandardPaths>

QString AppPaths::configurationDirectory()
{
    return QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
}

QString AppPaths::stateDirectory()
{
    const auto genericState = QStandardPaths::writableLocation(QStandardPaths::GenericStateLocation);
    return QDir(genericState).filePath(QStringLiteral("wizzamedia"));
}

QString AppPaths::logDirectory()
{
    return QDir(stateDirectory()).filePath(QStringLiteral("logs"));
}

bool AppPaths::ensureRuntimeDirectories()
{
    return QDir().mkpath(configurationDirectory()) && QDir().mkpath(logDirectory());
}
