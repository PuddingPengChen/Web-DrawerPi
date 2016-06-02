#ifndef COOKIECONTROLLER_H
#define COOKIECONTROLLER_H

#include "httprequesthandler.h"

class CookieController : public HttpRequestHandler
{
public:
    CookieController();
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // COOKIECONTROLLER_H
