

#ifndef __MODEL__H__
#define __MODEL__H__

#include <vector>
#include <unordered_map>
#include "../Common/Machine.h"
#include "../Common/FileUtil.h"

namespace ns_Model{
    using namespace std;
    using namespace ns_Machine; 
    using namespace ns_FileUtil;

    class All_question{
        public:
            //题目标号
              string id;
            //题目名称
              string title;
            //难度
              string level;
            All_question() = default;
    };
    class One_question{
       public:
        std::string id; //题目编号，唯一
        std::string title;  //题目的标题
        std::string level;   //难度: 简单 中等 困难
      
        std::string desc;   //题目的描述
        std::string head; //题目预设给用户在线编辑器的代码
        std::string tail;   //题目的测试用例，需要和header拼接，形成完整代码

        int cpu_limit;      //题目的时间要求(S)
        int mem_limit;      //题目的空间要去(KB)
    };

    class Model{
        private:
            const string _question_dir = "question/";
            //缓存
            unordered_map<string,All_question> _all_question_map;
            vector<All_question> _all_question_list;
            //缓存
            unordered_map<string,One_question> _one_question_map;
        public:
           Model();
            vector<All_question>get_all_question();
           One_question get_one_question(const string& id);
    };
};

#endif