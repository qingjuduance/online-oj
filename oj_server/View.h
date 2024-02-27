

#ifndef __VIEW__H__
#define __VIEW__H__
#include <vector>
#include <string>
#include <ctemplate/template.h>
#include "Model.h"
namespace ns_View{
    using namespace std;
    using namespace ns_Model;
    class View{
        private:
            const string template_dir = "template/";
        public:
            void set_all_question(const vector<All_question>&all_question,string*html);
            void set_one_question(const One_question &all_question,string*html);
    };
};

#endif