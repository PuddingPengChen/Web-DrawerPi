#include <Qtime>
#include "logincontroler.h"

LoginControler::LoginControler()

{
}

void LoginControler::service(HttpRequest& request, HttpResponse& response)
{

    qDebug("method%s",request.getMethod().constData());
    QByteArray world =request.getParameter("svgfile");
    qDebug("content:%s",world.constData());

}
