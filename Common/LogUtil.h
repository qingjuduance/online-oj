


#ifndef __LOGUTIL__H__
#define __LOGUTIL__H__
#include <iostream>
#include <string>
namespace ns_LogUtil{
    enum{
        DEBUG,
        INFO,
        WARING,
        ERROR,
        FATAL
    };
    std::ostream& log(const std::string&level,const std::string&file,int line);

#define Log(level) log(#level,__FILE__,__LINE__)
};
#endif