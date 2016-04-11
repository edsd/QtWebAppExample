#ifndef WEBCONFIGURATOR_H
#define WEBCONFIGURATOR_H

#include <httprequesthandler.h>
#include <httplistener.h>

#include <webconfiguratorpage.h>
#include <httpsettings.hpp>
#include <staticfilecontroller.h>

class WebConfigurator : public HttpRequestHandler
{
    Q_OBJECT
    Q_DISABLE_COPY(WebConfigurator)
public:
    WebConfigurator(QString &configPath);
    virtual ~WebConfigurator();
    virtual void service(HttpRequest& request, HttpResponse& response) override;

private:
    QString                             m_configPath;
    HttpSettings                        m_config;
    HttpListener                        m_httpListener;
    QHash<QString,WebConfiguratorPage*> m_pages;
    StaticFileController                *m_staticFileController;
};

#endif // WEBCONFIGURATOR_H
