//C++标准输入输出流的头文件
#include <iostream>
//C++的字符串头文件
#include <string>

//C++的命名空间,也可以自己定义
using namespace std;

//C语言的头文件
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
//自己定义的命名空间
namespace mm1
{
    char name[20];
    int age;
    void print()
    {
        cout<<name<<age<<endl;
    }
    void printHello_World()
    {
        cout<<"hellow world"<<endl;
    }
}

namespace boy
{
    namespace mm
    {
        int age;
        void print()
        {
            printf("boy::mm\n");
        }
    }
}
/*
    1.命名空间的写法
    namespace 空间名
    {
        //函数
        //变量
        //自定义类型
    }
    2.如何自己使用命名空间
        空间名::成员;
    3.如何使用省略的方式去调用空间中的成员
        在作用域中添加using namespace 作用域名
        同时也要注意同名问题
    4.命名空间的嵌套
        剥洋葱
    作用:
        NO.1 在一定程度上增加标识符的使用率
        NO.2 在大型项目中避免命名冲突
*/

//C++的入口函数
int main()
{
    strcpy(mm1::name,"小可爱");
    mm1::age = 18;
    mm1::print();
    mm1::printHello_World();
    {
        using namespace mm1;
        printf("%s\n",name);
    }
    boy::mm::print();
    system("pause");
    return 0;
}