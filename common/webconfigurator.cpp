#include "webconfigurator.h"

WebConfigurator::WebConfigurator(QString &configPath) :
    m_configPath(configPath),
    m_config(m_configPath),
    m_httpListener(&m_config, this)
{
    /* Помещаем в QHash объекты всех динамических страниц,
     * которые будут использоваться на нашем веб-сервере
     * */
    m_pages.insert("/index.html", new IndexPage());
    m_pages.insert("/second.html", new SecondPage());
    m_pages.insert("/first.html", new FirstPage());

    /* Для работы контроллера статических файлов
     * необходимо обратиться к объекту настроек, перейти к группе
     * параметров настройки контроллера и создать новый контроллер
     * используя состояния объекта настроек, выставленное на группу
     * параметров статического контроллера файлов
     * */
    m_config.beginGroup("html-static");
    m_staticFileController = new StaticFileController(&m_config);
    m_config.endGroup();
}

WebConfigurator::~WebConfigurator()
{
    foreach(WebConfiguratorPage* page, m_pages) {
        delete page;
    }
    delete m_staticFileController;
}

void WebConfigurator::service(HttpRequest &request, HttpResponse &response)
{
    /* В данном методе осуществляется проверка адреса запроса
     * на соответствие существующим страницам.
     * В данном случае, если страница существует, то мы
     * обращаемся к объекту страницы и передаём запрос на дальнейшую обработку.
     * В противном случаем возвращаем ошибку 404
     * */
    QByteArray path = request.getPath();
    for(auto i = m_pages.begin(); i != m_pages.end(); ++i) {
        if(path.startsWith(i.key().toLatin1())) {
            return i.value()->handleRequest(request,response);
        }
    }
    if(path=="/") {
        response.redirect("/index.html");
        return;
    }
    if(path.startsWith("/style.css") ||
            path.startsWith("/favicon-32x32.png") ||
            path.startsWith("/favicon.png")){
        return m_staticFileController->service(request, response);
    }
    response.setStatus(404,"Not found");
}
