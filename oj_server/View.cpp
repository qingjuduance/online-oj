

#include "View.h"


namespace ns_View{
   void View::set_all_question(const vector<All_question>&all_question, string*html){
        //在这里开始进行渲染操作
        // 题目的编号 题目的标题 题目的难度
            // 推荐使用表格显示
            // 1. 形成路径
            std::string src_html = template_dir + "all_question.html";
            // 2. 形成数字典 这个里面的参数好像是没有什么特别的用处
            ctemplate::TemplateDictionary root("all_question");
            for (const auto& q : all_question)
            {
                //这里的这个用处是很大的
                ctemplate::TemplateDictionary *sub = root.AddSectionDictionary("question_list");
                sub->SetValue("id",q.id);
                sub->SetValue("title", q.title);
                sub->SetValue("level", q.level);
            }

            //3. 获取被渲染的html
            ctemplate::Template *tpl = ctemplate::Template::GetTemplate(src_html, ctemplate::DO_NOT_STRIP);

            //4. 开始完成渲染功能
            tpl->Expand(html,&root);
   }
    void View::set_one_question(const One_question &one_question,string*html){
             std::string src_html = template_dir + "one_question.html";
            // 2. 形成数字典 这个里面的参数好像是没有什么特别的用处
            ctemplate::TemplateDictionary root("one_question");
            
            
            root.SetValue("id",one_question.id);
            root.SetValue("title", one_question.title);
            root.SetValue("level", one_question.level);
            root.SetValue("head",one_question.head);
            root.SetValue("desc", one_question.desc);
             

            //3. 获取被渲染的html
            ctemplate::Template *tpl = ctemplate::Template::GetTemplate(src_html, ctemplate::DO_NOT_STRIP);

            //4. 开始完成渲染功能
            tpl->Expand(html,&root);
    }
}