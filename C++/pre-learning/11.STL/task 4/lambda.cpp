#include <iostream>

using namespace std;
/*
    Lambda表达式: 最终得到的是一个函数指针, 并且当前函数指针所指向的函数也定义了
    No.1 Lambda表达式组成部分
        [捕获方式](参数列表) mutable exception -> 函数返回值类型{函数体;};
    捕获方式:
        []: 不捕获任何变量
        [=]: 值的方式
        [&]: 引用的方式
        [this]: 成员函数
        [=,&变量]: 组合方式
        [&变量]: 指定变量方式
    注意点: 
        1.Lambda表达式返回的是函数指针:通常使用auto类型变量接受
        2.除了捕获方式和函数体之外的东西, 如果没有或者没必要描述的这些都可以省略
    No.2 Lambda表达式的基本操作
        2.1 完整版的Lambda表达式
        2.2 Lambda的使用
        2.3 缺省写法
        2.4 捕获方式的区别

*/
int Max(int a,int b)
{
    return a > b ? a : b;
}
void print(int a,int b)
{
    //定义和调用分开写
    //cout << Max(a,b) << endl;
    //完整版本的Lambda表达式
    //int (*pMax)(int , int) = [](int a,int b) mutable throw()->int{return a > b ? a : b;};
    //cout << pMax(a,b) << endl;
    //auto pFunc = [](int a,int b) mutable throw()->int{return a > b ? a : b;};
    //cout << pFunc(a,b) << endl;
    cout << [](int a,int b) mutable throw()->int{return a > b ? a : b;}(a,b) << endl;
}

void printMax(int a,int b)
{
    cout << [](int a,int b)->int{return a > b ? a : b;}(1,2) << endl;
}

void printInfo()
{
    cout << "ILoveYou" << endl;
}

int main()
{
    print(1,2);
    printMax(1,2);
    //捕获方式和函数体必备，其余都可以缺省
    []{cout << "ILoveYou" << endl;}();
    auto pFunc = [] {cout << "IMissyou" << endl;};
    pFunc();

    

    return 0;
}