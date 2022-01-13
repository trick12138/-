#include <iostream>     //表准头文件
#include <cstdio>
#include <cstdlib>
using namespace std;    //标准命名空间

/*
    1.c++只支持int类型的返回值
    2.c++对参数没有要求,可以写参数,也可以不写
*/
namespace helloworld
{
    void print()
    {
        printf("hellow world\n");
    }
}



int main()              //入口函数
{
    helloworld::print();
    cout<<"我是最帅的,你也不错\n";
    system("pause");
    return 0;
}