


#ifndef __CONTROL__H__
#define __CONTROL__H__
#include <vector>

#include "Model.h"
#include "View.h"
#include "../Common/Machine.h"
#include "../Common/FileUtil.h"
#include "../jsoncpp-master/include/json/json.h"
#include "../cpp-httplib-v0.7.15/httplib.h"
namespace ns_Control{
    using namespace std;
    using namespace httplib;
    using namespace ns_Model;
    using namespace ns_View;
    using namespace ns_Machine;
    using namespace ns_FileUtil;
    class Control{
        private:
            Model _model;
            View _view;
            //还要有对应的编译，运行服务的机器的ip，port，来进行网络之间的通信
            vector<Machine> _compile_and_run;
            //配置文件
            const string _conf_path;
        public:
            Control();
           void get_all_question( string* html);
           void get_one_question(const string& id,string* html);
           void judge(const string&id,const string&body,string*html_json);
        
    };
};

#endif