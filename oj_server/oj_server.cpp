


//这里就是将我们的请求进行重定向操作
#include <iomanip>
#include <vector>
#include "../cpp-httplib-v0.7.15/httplib.h"

#include "Control.h"

using namespace std;
using namespace httplib;
using namespace ns_Control;
int main(int argc,char**argv){

    Server svr;
    ns_Control::Control ctrl;
    svr.Get("/all_question",[&](const Request& req ,Response& resp){
        //我们的server 对象负责进行机器的切换操作
        cout << "oj_server  all_question  get\n";
        //调用获取所有题目的操作
        string html;
        //control 会直接将已经渲染好的页面返回来
        ctrl.get_all_question(&html);
        resp.set_content(html,"text/html; charset=utf-8");
    });
        //这个表明了我们获取到的题目
     svr.Get(R"(/one_question/(\d+))",[&](const Request& req ,Response& resp){
        //我们的server 对象负责进行机器的切换操作
        cout << "oj_server one_question get\n";
        //调用获取一个题目的操作
        //我们要获取题号
        const string id = req.matches[1];
        string html;
        ctrl.get_one_question(id,&html);
        resp.set_content(html,"text/html; charset=utf-8");
    });
    svr.Post(R"(/judge/(\d+))",[&](const Request& req ,Response& resp){
        //我们的server 对象负责进行机器的切换操作
        cout << "oj_server one_question get\n";
        //调用获取一个题目的操作
        //我们要获取题号
        const string id = req.matches[1];
        string html_json;
        ctrl.judge(id,req.body,&html_json);
        resp.set_content(html_json,"application/json; charset=utf-8");
    });


    int port = 8081;
    if(argc == 2){
        port = atoi(argv[1]);
        cout << "port from 8081 to" << port << endl;
    }
    svr.set_base_dir("./wwwroot");
    cout << "port: " << port << endl;
    svr.listen("0.0.0.0",port);
    return 0;
}