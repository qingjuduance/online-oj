


//这里就是将我们的请求进行重定向操作
#include <iomanip>

#include "../cpp-httplib-v0.7.15/httplib.h"
#include "Server.h"
using namespace std;
using namespace httplib;
int main(int argc,char**argv){

    Server svr;
    ns_Server::Server ctrl;
    svr.Get("/redirect",[&](const Request& req ,Response& resp){
        //我们的server 对象负责进行机器的切换操作
        cout << "get\n";
        resp.set_redirect("http://" + ctrl.get_address());
    });

     svr.Post("/redirect",[&](const Request& req ,Response& resp){
        //我们的server 对象负责进行机器的切换操作
        cout << "post\n";
        resp.set_redirect("http://" + ctrl.get_address());
    });


    int port = 8080;
    if(argc == 2){
        port = atoi(argv[1]);
        cout << "port from 8080 to" << port << endl;
    }
    svr.set_base_dir("./wwwroot");
    cout << "port: " << port << endl;
    svr.listen("0.0.0.0",port);
    return 0;
}