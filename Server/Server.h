
#ifndef __SERVER__H__
#define __SERVER__H__

#include <string>
#include <vector>
#include "../Common/Machine.h"
#include "../Common/FileUtil.h"
namespace ns_Server{
    using namespace std;
    using namespace ns_FileUtil;
    class Server{
        private:
        //这里就是一个存放着机器的集合
        vector<ns_Machine::Machine>_machines;
        const string _conf_path = "oj_server.conf";
        public:
            Server(){
                conf_machine(_conf_path,_machines);
            }
            //这里就获得一个机器
            string get_address(){
                static size_t index = 0;
                string addr = _machines[index].get_address();
                index = (index +1)%_machines.size();
                return addr;
            }
    };
};
#endif