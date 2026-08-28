#pragma once

#include "core/settings/SettingsService.h"

#include <QObject>

class ApplicationController final : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString version READ version CONSTANT)
    Q_PROPERTY(SettingsService *settings READ settings CONSTANT)

public:
    explicit ApplicationController(QObject *parent = nullptr);
    QString version() const;
    SettingsService *settings();

private:
    SettingsService m_settings;
};
