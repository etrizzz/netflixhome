#include "SettingsService.h"

SettingsService::SettingsService(QObject *parent)
    : QObject(parent)
    , m_settings(QStringLiteral("WizzaMedia"), QStringLiteral("WizzaMediaHub"))
{
}

bool SettingsService::reduceMotion() const
{
    return m_settings.value(QStringLiteral("appearance/reduceMotion"), false).toBool();
}

void SettingsService::setReduceMotion(bool enabled)
{
    if (reduceMotion() == enabled)
        return;
    m_settings.setValue(QStringLiteral("appearance/reduceMotion"), enabled);
    emit reduceMotionChanged();
}
