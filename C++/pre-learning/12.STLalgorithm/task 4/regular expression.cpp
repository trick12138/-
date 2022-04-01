#include <iostream>
#include <regex>
#include <string>

using namespace std;
/*
//正则表达式：有一些特殊的字符组成的字符串，
//字符串的处理,数据的处理
    正则匹配    regex_match()       //验证用到
    正则查找    regex_search()  函数
    正则替换    regex_replace()     //数据处理
*/

int main()
{
    char userName[100] = "";
/*     while(1)
    {
        cin >> userName;
        //1.构建正则对象
        //注意的点是：'\' 变为 '\\'
            //为什么要了解正则表达式的基本要素:
                //1.1 写特殊需求
                //1.2 识别正则表达式的正确和错误
        //2663495373@qq.com
        //\w :ydpatjj
        //.和特殊字符 :.com .com
        regex regexStr("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$");
        bool result = regex_match(userName, regexStr);
        //返回ture就是邮箱
        if (result)
        {
            cout << "是邮箱!" << endl;
        }
        else
        {
            //授权
            cout << "用户名必须是邮箱" << endl;
        }
    } */
    //非正则字符串，必须完全匹配
    string str = "I Love You,but you don't Love me";
    regex regexStr2("I Love You");
    cout << regex_replace(str,regexStr2,"You Love Me") << endl;
    //会修改所有匹配项
    regex regexStr3("but you don't Love me");
    cout << regex_replace(str,regexStr3,"I") << endl;
    //regex::icase忽略大小写
    cout << regex_replace("ILoveYou",regex("love",regex::icase),"Hate") << endl;
    system("pause");
    return 0;
}