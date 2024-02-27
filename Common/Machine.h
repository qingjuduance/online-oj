#ifndef __MACHINE__H__
#define __MACHINE__H__

#include <string>

namespace ns_Machine{
    using namespace std;
    class Machine{
        private:
            string _ip;
            int _port;
        public:
            Machine();
            Machine(const string& ip,int port);
            string get_address();
            string get_ip();
            int get_port();
    };
};
#endif