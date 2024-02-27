

#ifndef __FILEUTIL__H__
#define __FILEUTIL__H__
#include <string>
#include <fstream>
#include <vector>
#include "LogUtil.h"
#include "Machine.h"
namespace ns_FileUtil{
    using namespace std;
    using namespace ns_LogUtil;
    using namespace ns_Machine;
    void read_file(const string&path,string*content);
    void conf_machine(const string&path,vector<Machine>&machines);
};

#endif