#include "app/ApplicationController.h"
#include "core/logging/Logger.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication::setOrganizationName(QStringLiteral("WizzaMedia"));
    QGuiApplication::setApplicationName(QStringLiteral("Wizza Media Hub"));
    QGuiApplication::setApplicationVersion(QStringLiteral(WIZZA_VERSION));
    QGuiApplication application(argc, argv);
    QQuickStyle::setStyle(QStringLiteral("Basic"));
    Logger::install();

    ApplicationController controller;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("applicationController"), &controller);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &application, [] { QCoreApplication::exit(EXIT_FAILURE); }, Qt::QueuedConnection);
    engine.loadFromModule(QStringLiteral("Wizza.Media"), QStringLiteral("Main"));
    const int result = application.exec();
    Logger::shutdown();
    return result;
}
