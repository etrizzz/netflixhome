#include "ApplicationController.h"

ApplicationController::ApplicationController(QObject *parent)
    : QObject(parent)
    , m_settings(this)
{
}

QString ApplicationController::version() const
{
    return QStringLiteral(WIZZA_VERSION);
}

SettingsService *ApplicationController::settings()
{
    return &m_settings;
}
