#pragma once

#include <iostream>
#include <cpr/cpr.h>
#include <vector>

using std::cout;   using std::string;
using std::cin;    using std::vector;

class URLrequest {
private:
    static const string urlAddr;
    vector <cpr::Pair> arg;
    cpr::Response resp;
    bool creat;

    void getRequest();
    void postRequest();

public:
    URLrequest();
    ~URLrequest();

    void createRequest();
    void displayResp() const;
    bool created() const;
};


