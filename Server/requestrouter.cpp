
#include <QDebug>
#include "requestrouter.h"

HttpSessionStore* RequestRouter::sessionStore=0;
StaticFileController* RequestRouter::staticFileControler=0;

RequestRouter::RequestRouter(QObject *parent) :
    HttpRequestHandler(parent)
{
    loginctrl = new LoginControler();
    cookies = new CookieController();

}

void RequestRouter::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if (path=="/" || path=="/hello")
    {
        control.service(request, response);
    }
    else if(path=="/login")
    {
        loginctrl->service(request,response);
    }
    else if(path=="/cookie")
    {
        cookies->service(request,response);
    }
    else if(path.startsWith("/files"))
    {
        staticFileControler->service(request,response);
    }
    else
    {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

    qDebug("RequestMapper: finished request");
}
