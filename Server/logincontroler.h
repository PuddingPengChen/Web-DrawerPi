#ifndef LOGINCONTROLER_H
#define LOGINCONTROLER_H
#include "httprequesthandler.h"
#include "requestrouter.h"

class LoginControler : public HttpRequestHandler
{

public:
    explicit LoginControler();
    void service(HttpRequest& request, HttpResponse& response);
signals:

public slots:

};

#endif // LOGINCONTROLER_H
