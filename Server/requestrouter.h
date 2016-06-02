#ifndef REQUESTROUTER_H
#define REQUESTROUTER_H

#include "httprequesthandler.h"
#include "httpsessionstore.h"
#include "qwebservercontrol.h"
#include "logincontroler.h"
#include "cookiecontroller.h"
#include "staticfilecontroller.h"

class LoginControler;
class RequestRouter : public HttpRequestHandler
{
    Q_OBJECT
public:
    explicit RequestRouter(QObject *parent = 0);
    void service(HttpRequest& request, HttpResponse& response);
    static HttpSessionStore* sessionStore;
    static StaticFileController* staticFileControler;
signals:

public slots:
private:
    QWebServerControl control;
    LoginControler* loginctrl;
    CookieController* cookies;
};

#endif // REQUESTROUTER_H
