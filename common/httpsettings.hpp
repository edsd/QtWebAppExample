#ifndef HTTPSETTINGS_H
#define HTTPSETTINGS_H

#include <QSettings>

class HttpSettings : public QSettings
{
public:
    explicit HttpSettings(const QString& fileName, QObject* parent = nullptr)
        : QSettings(fileName,QSettings::IniFormat,parent)
    {
        // Настройки веб-сервера
        setValue("port",             value("port", 8080));
        setValue("minThreads",       value("minThreads", 1));
        setValue("maxThreads",       value("maxThreads", 100));
        setValue("cleanupInterval",  value("cleanupInterval", 1000));
        setValue("readTimeout",      value("readTimeout", 60000));
        setValue("maxRequestSize",   value("maxRequestSize", 16000));
        setValue("maxMultiPartSize", value("maxMultiPartSize", 10000000));

        // Настройки для статических файлов
        setValue("html-static/path",                value("html-static/path", "html-static"));
        setValue("html-static/encoding",            value("html-static/encoding", "UTF-8"));
        setValue("html-static/maxAge",              value("html-static/maxAge", 60000));
        setValue("html-static/cacheTime",           value("html-static/cacheTime", 60000));
        setValue("html-static/cacheSize",           value("html-static/cacheSize", 1000000));
        setValue("html-static/maxCachedFileSize",   value("html-static/maxCachedFileSize", 65536));
    }
};

#endif // HTTPSETTINGS_H
