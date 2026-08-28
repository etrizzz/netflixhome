#pragma once

#include <QObject>
#include <QSettings>

class SettingsService final : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool reduceMotion READ reduceMotion WRITE setReduceMotion NOTIFY reduceMotionChanged)

public:
    explicit SettingsService(QObject *parent = nullptr);
    bool reduceMotion() const;
    void setReduceMotion(bool enabled);

signals:
    void reduceMotionChanged();

private:
    QSettings m_settings;
};
