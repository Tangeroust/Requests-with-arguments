#include "URLrequest.h"

const string URLrequest::urlAddr = "http://httpbin.org";

URLrequest::URLrequest() : creat(false)
{   }

URLrequest::~URLrequest()
{   }

void URLrequest::createRequest()
{
    string argName, argValue;

    cout << "\nEnter the argument name: ";
    cin >> argName;

    if(argName == "post")
    {
        postRequest();
        creat = true;
        return;
    }

    else if(argName == "get")
    {
        getRequest();
        creat = true;
        return;
    }

    cout << "\nEnter the argument value: ";
    cin >> argValue;

    if(argValue == "post")
    {
        postRequest();
        creat = true;
        return;
    }

    else if(argValue == "get")
    {
        getRequest();
        creat = true;
        return;
    }

    else
    {
        arg.emplace_back(cpr::Pair(string(argName), string(argValue)));
        return;
    }
}

void URLrequest::postRequest()
{
    resp = cpr::Post(cpr::Url(urlAddr + "/post"),
                     cpr::Payload(arg.begin(), arg.end()));
}

void URLrequest::getRequest()
{
    string urlRequest = urlAddr + "/get";

    for(size_t i = 0; i < arg.size(); i++)
    {
        if(i == 0)
            urlRequest += "?";

        urlRequest += arg[i].key + "=" + arg[i].value;

        if(i < arg.size() - 1)
            urlRequest += "&";
    }

    resp = cpr::Get(cpr::Url(urlRequest));
}

void URLrequest::displayResp() const
{
    if(creat)
        cout << "\n" << resp.text;

    else
        cout << "\nRequest not created yet!";
}

bool URLrequest::created() const
{
    return creat;
}
