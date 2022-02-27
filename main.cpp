#include "URLrequest.h"

int main() {

    URLrequest request;

    do{
        request.createRequest();
    }while(!request.created());

    request.displayResp();

    return 0;
}