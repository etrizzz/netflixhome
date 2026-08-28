#include "app/AppPaths.h"
#include "core/settings/SettingsService.h"

#include <QSignalSpy>
#include <QDir>
#include <QStandardPaths>
#include <QTest>

class SkeletonTest final : public QObject {
    Q_OBJECT

private slots:
    void initTestCase()
    {
        QStandardPaths::setTestModeEnabled(true);
        QCoreApplication::setOrganizationName(QStringLiteral("WizzaMediaTests"));
        QCoreApplication::setApplicationName(QStringLiteral("Skeleton"));
    }

    void createsRuntimeDirectories()
    {
        QVERIFY(AppPaths::ensureRuntimeDirectories());
        QVERIFY(QDir(AppPaths::logDirectory()).exists());
    }

    void persistsReducedMotionSetting()
    {
        SettingsService settings;
        settings.setReduceMotion(false);
        QSignalSpy spy(&settings, &SettingsService::reduceMotionChanged);
        settings.setReduceMotion(true);
        QCOMPARE(spy.count(), 1);
        QVERIFY(SettingsService().reduceMotion());
    }
};

QTEST_GUILESS_MAIN(SkeletonTest)
#include "tst_skeleton.moc"
