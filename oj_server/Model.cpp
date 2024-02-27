#include "Model.h"


namespace ns_Model{

    Model::Model(){
          //我们读取一个配置文件
        //将配置文件里面的东西全都读出来，然后交给view进行熏染
        const string file_name = "all.txt";
        //我们将文件里面的东西全都读出来
        //再自己进行操作
        string content;
        read_file(_question_dir + file_name,&content);
        //现在所有的内容都在content  我们只要获取就行
        size_t begin = 0;
        size_t end = 0;
        while(end != content.size() -1){
            //
            All_question all;
            end = content.find(' ',begin);
            all.id = content.substr(begin,end-begin);
            begin = end+1;
            end = content.find(' ',begin);
            all.title = content.substr(begin,end-begin);
            begin = end+1;
            end = content.find('\n',begin);
            all.level = content.substr(begin,end-begin);
            begin = end+1;
            Log(INFO) << "id: " << all.id << " title: " << all.title << " level: " << all.level << endl;
            _all_question_list.push_back(all);
        }
       for(All_question item:_all_question_list){
        _all_question_map.insert(make_pair(item.id,item));
       }
    }

    vector<All_question>Model::get_all_question(){
      
        return _all_question_list;
    }

      One_question Model::get_one_question(const string& id){
        if(_one_question_map.count(id) != 0){
          return _one_question_map[id];
        }
        //先读取文件
        //获得文件夹
        const string file_dir = _question_dir + id;
        //我们读取head 文件 和desc 文件，然后将结果返回
        One_question one;
        All_question item = _all_question_map[id];
        one.id = move(item.id);
        one.title = move(item.title);
        one.level = move(item.level);
        //获取desc head
        string head;
        string desc;
        string tail;
        read_file(file_dir+"/head.cpp",&head);
        read_file(file_dir+"/desc.txt",&desc);
        read_file(file_dir+"/tail.cpp",&tail);
        one.desc = move(desc);
        one.head = move(head);
        one.tail = move(tail);
        _one_question_map[id] = one;
        //在这里我们进行缓存的操作
        //这之后可以交给redis 进行操作
        return one;
      }
};