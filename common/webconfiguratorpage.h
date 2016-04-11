#ifndef WEBCONFIGURATORPAGE_H
#define WEBCONFIGURATORPAGE_H

#include <QObject>
#include <httprequesthandler.h>
#include <httplistener.h>
#include <template.h>

class WebConfiguratorPage : public QObject
{
    Q_OBJECT
public:
    WebConfiguratorPage(const QString& title);
    virtual void handleRequest(HttpRequest&, HttpResponse&) {}
    virtual ~WebConfiguratorPage() {}

protected:
    Template commonTemplate() const;

private:
    QString m_title;
};

class IndexPage : public WebConfiguratorPage
{
    Q_OBJECT
public:
    IndexPage() : WebConfiguratorPage("EDISON") {}

    virtual ~IndexPage() {}
public:
    virtual void handleRequest(HttpRequest &request, HttpResponse &response) override;
};

class FirstPage : public WebConfiguratorPage
{
    Q_OBJECT
public:
    FirstPage() : WebConfiguratorPage("First Page") {}

    virtual ~FirstPage() {}
public:
    virtual void handleRequest(HttpRequest &request, HttpResponse &response) override;
};

class SecondPage : public WebConfiguratorPage
{
    Q_OBJECT
public:
    SecondPage() : WebConfiguratorPage("Second Page") {}

    virtual ~SecondPage() {}
public:
    virtual void handleRequest(HttpRequest &request, HttpResponse &response) override;
};

#endif // WEBCONFIGURATORPAGE_H
