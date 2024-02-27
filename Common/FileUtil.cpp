

#include "FileUtil.h"


namespace ns_FileUtil{
     void read_file(const string&path,string*content){
        if(content == nullptr){
            Log(WARING) << "content is nullptr\n";
        }
        ifstream ifs(path);
        char buf[1024];
        while(ifs.getline(buf,1024)){
             content->append(buf );
            content->append("\n" );
             Log(INFO) << "content get a line :" << buf << endl;;
        }
       
     }

      void conf_machine(const string&path,vector<Machine>&machines){
         //先将配置文件里面的配置读取出来
                string content;
                read_file(path,&content);
                if(content.size() == 0){
                    Log(WARING) << "content is empty\n";
                }
                //我们要将后面面的\n去掉
               
                //这里是已经读取完了
                size_t begin = 0;
                size_t end = 0;
                while(end != content.size() -1){
                end =  content.find(' ',begin);
                    string ip = content.substr(begin,end-begin);
                begin = end+1;
                end =  content.find('\n',begin);
                    string port = content.substr(begin,end-begin);
                begin = end+1;

                    Log(INFO) << "ip: " << ip << " port: " << port << endl;
                    machines.push_back(ns_Machine::Machine(ip,atoi(port.c_str())));
                    
                }

                Log(INFO) << "conf_machine over\n";
      }
}