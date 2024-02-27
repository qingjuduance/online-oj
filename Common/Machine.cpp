
#include "Machine.h"

namespace ns_Machine{
     Machine::Machine(){

    }
    Machine:: Machine(const string& ip,int port):
    _ip(move(ip)),_port(port){}
    string Machine::get_address(){
        return _ip + ":" + to_string(_port);
    }

     string Machine::get_ip(){
        return _ip;
     }
    int Machine::get_port(){
        return _port;
    }
};
