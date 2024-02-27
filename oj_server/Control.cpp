
#include "Control.h"


namespace ns_Control{

    Control::Control(){
        conf_machine(_conf_path,_compile_and_run);
    }
    void Control::get_all_question( string* html){
        //我们先去model层面去获取数据
        vector<All_question> all_question = _model.get_all_question();
        //再将我们获取到的数据返回
        _view.set_all_question(all_question,html);
    }

      void  Control::get_one_question(const string& id,string* html){
           //我们先去model层面去获取数据
       One_question one_question = _model.get_one_question(id);
        //再将我们获取到的数据返回
        _view.set_one_question(one_question,html);
      }
    void  Control::judge(const string&id,const string&body,string*html_json){
        Json::Reader read;
        Json::Value value;
        One_question q = _model.get_one_question(id);
        //进行解析操作，解析完的值都放置在value里面
        read.parse(body,value);
        //将代码·提取出来,这些是我们在前端代码里面的json值
        string code = value["code"].asString();
        string input = value["input"].asString();
        Json::Value compile_value;
        compile_value["input"] = input;
        compile_value["code"] = code + "\n" + q.tail;
        compile_value["cpu_limit"] = q.cpu_limit;
        compile_value["mem_limit"] = q.mem_limit;
        Json::FastWriter writer;
        //将我们的所有题目都写成了一个Json 方便进行传输的操作
        std::string compile_string = writer.write(compile_value);
        //我们将这个json传给我们的compile_and_run 服务进行操作

        //我们要获得一个机器
        static size_t index = 0;
        //我们在这里创建一个客户端，进行操作
        string ip = _compile_and_run[index].get_ip();
        int port = _compile_and_run[index].get_port();
        Client cli(ip,port);
        //然后我们再用client 发起post请求进行操作
        while(true){
            if(auto res =  cli.Post("/compile_and_run",compile_string,"application/json;charset=utf-8")){
                //这里是主机发送请求成功了
                //res就是我们进行post请求调用之后的返回值，是一个Json格式的字符串，这个字符串
                //会携带是否运行成功，是否编译成功的信息，以及标准错误和标准输出的内容
                //post请求题里面的东西
                res->body;
                *html_json = res->body;
                //结果返回的状态码
                res->status; 
                return;
            }
            else{
                //这里就是主机是断开了
                //说明我们要重新选择一台主机
               
            }
           index = (index+1)%_compile_and_run.size();
        }
       
    }
};