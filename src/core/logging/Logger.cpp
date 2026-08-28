#include "Logger.h"

#include "app/AppPaths.h"

#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QMutex>
#include <QTextStream>

#include <memory>

namespace {
QMutex mutex;
std::unique_ptr<QFile> file;

void writeMessage(QtMsgType type, const QMessageLogContext &, const QString &message)
{
    const char *level = "INFO";
    if (type == QtDebugMsg) level = "DEBUG";
    else if (type == QtWarningMsg) level = "WARN";
    else if (type == QtCriticalMsg) level = "ERROR";
    else if (type == QtFatalMsg) level = "FATAL";

    QMutexLocker lock(&mutex);
    if (file && file->isOpen()) {
        QTextStream stream(file.get());
        stream << QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs)
               << ' ' << level << ' ' << message << '\n';
        stream.flush();
    }
    if (type == QtFatalMsg)
        abort();
}
}

bool Logger::install()
{
    if (!AppPaths::ensureRuntimeDirectories())
        return false;
    const QString path = AppPaths::logDirectory() + QStringLiteral("/wizza-media.log");
    const QFileInfo currentLog(path);
    if (currentLog.exists() && currentLog.size() >= 5 * 1024 * 1024) {
        const QString previousPath = path + QStringLiteral(".1");
        QFile::remove(previousPath);
        if (!QFile::rename(path, previousPath))
            return false;
    }
    file = std::make_unique<QFile>(path);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        file.reset();
        return false;
    }
    qInstallMessageHandler(writeMessage);
    return true;
}

void Logger::shutdown()
{
    qInstallMessageHandler(nullptr);
    QMutexLocker lock(&mutex);
    file.reset();
}
