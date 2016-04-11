#include "webconfiguratorpage.h"
#include <QFile>
#include <QDebug>

WebConfiguratorPage::WebConfiguratorPage(const QString &title) :
    m_title(title)
{

}

Template WebConfiguratorPage::commonTemplate() const
{
    /* Для формирования основного шаблона используется файл common.htm.
     * В него устанавилвается название страницы ...
     * */
    QFile file(":/html/common.htm");
    Template common(file, QTextCodec::codecForName("UTF-8"));
    common.setVariable("Title", m_title);

    /* А также формируется меню.
     * Формирование меню сделано с учетом проверки на то,
     * требуется ли данное меню на странице или нет.
     * В данном примере меню будет на всех страницах, поэтому
     * просто обозначим необходимость данного меню.
     * Если вы посмотрите содержимое файла common.htm, то
     * обнаружите там проверку на параметр "Navigation"
     * */
    bool navigation = true;
    common.setCondition("Navigation", navigation);
    if(navigation) {
        /* А само меню будет формироваться с помощью цилического добавления
         * пунктов, что также отражено специальной конструкцией в файле common.htm
         * */
        common.loop("Items", 3);
        common.setVariable("Items0.href", "/index.html");
        common.setVariable("Items0.name", "Main page");

        common.setVariable("Items1.href", "/first.html");
        common.setVariable("Items1.name", "First page");

        common.setVariable("Items2.href", "/second.html");
        common.setVariable("Items2.name", "Second page");
    }
    return common;
}

/* Далее идёт реализация обработчика запроса к каждой из страниц.
 * Фактически они идентичны в данном примере, но в реальном приложении
 * будут скорее всего отличаться по своей логике
 * */

void IndexPage::handleRequest(HttpRequest &request, HttpResponse &response)
{
    if (request.getMethod() == "GET")
    {
        // Получаем родительски щаблон страницы
        Template common = commonTemplate();
        QFile file(":/html/index.htm");
        Template contents(file, QTextCodec::codecForName("UTF-8"));
        /* После чего добавляем собственный контент из шаблона для данной страницы
         * в родительском шаблоне место для добавления информации, равно как и другого шаблона
         * в данном примере обозначено как {Content}
         * */
        common.setVariable("Content", contents);
        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write(common.toUtf8());
        return;
    }
    else
    {
        return;
    }
    return;
}

void FirstPage::handleRequest(HttpRequest &request, HttpResponse &response)
{
    if (request.getMethod() == "GET")
    {
        Template common = commonTemplate();
        QFile file(":/html/first.htm");
        Template contents(file, QTextCodec::codecForName("UTF-8"));
        common.setVariable("Content", contents);
        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write(common.toUtf8());
        return;
    }
    else
    {
        return;
    }
    return;
}

void SecondPage::handleRequest(HttpRequest &request, HttpResponse &response)
{
    if (request.getMethod() == "GET")
    {
        Template common = commonTemplate();
        QFile file(":/html/second.htm");
        Template contents(file, QTextCodec::codecForName("UTF-8"));
        common.setVariable("Content", contents);
        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write(common.toUtf8());
        return;
    }
    else
    {
        return;
    }
    return;
}
