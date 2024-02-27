

#include "LogUtil.h"


namespace ns_LogUtil{
    std::ostream& log(const std::string&level,const std::string&file,int line){
        std::cout << "[";
        std::cout << level;
        std::cout << "]";
         std::cout << "[";
        std::cout << file;
        std::cout << "]";
         std::cout << "[";
        std::cout << line;
        std::cout << "]";
        return std::cout;
    }
};