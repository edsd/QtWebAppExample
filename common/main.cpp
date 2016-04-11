#include <QCoreApplication>
#include <QDir>
#include <webconfigurator.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    a.setApplicationName("QtWebAppExample");

    QString configPath = QDir::currentPath() + "/" + QCoreApplication::applicationName() + ".ini";
    new WebConfigurator(configPath);

    return a.exec();
}
