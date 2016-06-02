#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

#include "httplistener.h"
#include "requestrouter.h"
#include "httpsessionstore.h"
#include "filelogger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings* listenerSetting = new QSettings("etc/webapp.ini",QSettings::IniFormat,&a);


    //get file logginer system
//    listenerSetting->beginGroup("logging");
//    FileLogger* longer = new FileLogger(listenerSetting,10000,&a);
//    longer->installMsgHandler();
//    listenerSetting->endGroup();

    //get file settings
    listenerSetting->beginGroup("files");
    RequestRouter::staticFileControler = new StaticFileController(listenerSetting,&a);
    qDebug()<<QObject::tr("this root doc path:%1").arg(listenerSetting->value("path").toString());
    listenerSetting->endGroup();

    //get session setting
    listenerSetting->beginGroup("sessions");
    RequestRouter::sessionStore=new HttpSessionStore(listenerSetting,&a);
    listenerSetting->endGroup();

    //Get the listener setting
    //Generatr HTTP server
    listenerSetting->beginGroup("listener");
    new HttpListener(listenerSetting,new RequestRouter(),&a);
    listenerSetting->endGroup();


    return a.exec();
}
