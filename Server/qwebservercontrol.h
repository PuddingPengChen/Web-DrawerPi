#ifndef QWEBSERVERCONTROL_H
#define QWEBSERVERCONTROL_H

#include "httprequesthandler.h"

class QWebServerControl : public HttpRequestHandler
{
public:
    QWebServerControl();
    void service(HttpRequest& request, HttpResponse& response);

private:
    QList <QString> list;
};

#endif // QWEBSERVERCONTROL_H
