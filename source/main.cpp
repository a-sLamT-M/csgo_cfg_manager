#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "../header/mainwindow.h"
#include "../header/cfgmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "csgo_cfg_manager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }

    CfgManager *cfgManager = new CfgManager("csgo","steam");
    std::string str =  cfgManager->getSteamPathFromSystem();


    MainWindow w;
    w.show();
    return a.exec();
}
