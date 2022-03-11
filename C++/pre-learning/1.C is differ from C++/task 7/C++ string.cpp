#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    //No.1 了解C++string常见的几种创建方式

    string s1;
    s1 = "ILoveYou";
    std::string s2 = "IMissYou";
    string s3("我很帅,你也不错");   //错误写法：string s3(123) string s3('3');
    string s4(4,'o');       //四个o创建string对象
    string s5("ILikeYou",1,3);  //从下标1开始长度为3的字串
    string s6(s5);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    //No.2 C++string和C语言的char* 是有区别的
    //C++string是一个类
    //如果想要得到它的字符串可以采用成员函数获取
    printf("%s",s3.data());
    cout << endl;
    printf("%s",s3.c_str());
    //No.3 C++string的基本操作
    //增删改查 比较大小 连接 拷贝 复制
    //3.1基本的赋值
    string str;
    str = "我很帅";
    str = 'k';
    cout << str << endl;
    //特殊的赋值： assign 辅助函数赋值
    char name[5] = "1234";
    str.assign(name,name+5);
    cout << str << endl;
    cout << str.size() << endl;
    str = "1234";
    //关于string长度问题， 不算\0
    cout << str.size() << endl;
    str.assign(4,'o');
    str.assign(s1);
    str.assign("IMissYou",1,4);
    cout << str << endl;
    //长度
    cout << str.length() << endl;
    //string的连接操作
    string str2 = "IMissYou";
    string str3 = "ILoveYou";
    str2 = str2 + str3;
    cout << str2 << endl;
    str2.append(str3);
    cout << str2 <<endl;
    str2.append("12345",1,2);
    cout << str2 << endl;
    //string的比较 可以直接用比较运算符比较> < = != >= <=
    string first = "1234";
    string second = "1324";
    cout << (first > second) << endl;
    //compara();
    cout << first.compare(second) << endl;
    cout << first.compare("1234") << endl;
    cout << first.compare(3,1,second,3,1) << endl;
    //C++string字串
    string substr = "I Love You";
    string sub = substr.substr(1,8);
    cout << sub << endl;
    //C++string查找
    //find() 从左往右找 rfind() 从右往左找 
    //find_first_of find_last_of
    //find_first_not_of find_last_not_of
    //string::npos    //string no pos
    string::npos;
    string findStr = "I Love You";
    if (findStr.find('x') == string::npos)
        cout << "没找到" << endl;
    if (findStr.find('o') == string::npos)
        cout << findStr.find('o') << endl;
    //string 替换 replace函数
    findStr.replace(5,7,"你");
    cout << findStr << endl;
    //删除字串
    string deleteStr = "ILoveYou";
    deleteStr.erase(1,4);
    cout << deleteStr << endl;
    deleteStr.erase();
    cout << deleteStr << endl;
    return 0;
}