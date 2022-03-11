#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //No.1 C++基本的输入输出
    //1.1单个数据的时候
    printf("我是最帅的,你也不错\n");
    cout << "我是最帅的,你也不错!" << endl;
    printf("%d\n",1);
    cout << 1 << endl;
    //1.2 输出多个数据
    printf("%d%s%f\n",1,"你好帅",1.1);
    cout << 1 << "你好帅" << 1.1 << endl;
    //1.3 关于格式控制
    //C++ 依旧支持C语言的格式控制字符,不需要考虑C++的格式控制
    //cin和cout也是C++中的类和对象
    //换行
    cout << endl;
    //1.4 输出多个变量
    int iNum = 1;
    char str[] = "我好帅,你也不错";
    double dNum = 1.1;
    cout << iNum << "\t" << str << "\t" << dNum << endl;
    //No.2 C++基本输入
    cin >> iNum;
    cout << "iNUm=" << iNum <<endl;
    //2.输入多个数据
    cin >> iNum >> str >> dNum;
    cout << "iNum=" << iNum << "str=" << str << "dNum=" << dNum << endl;
    //No.3注意几个问题
    //1.命名空间
    //C++的作用域限定了语句的作用范围
    //2.别致写法
    ::cout << "I love you" << ::endl;
    //当全局变量和局部变量冲突时就近原则
    //C++中可以用作用域分辨符来区分::为全局变量
    return 0;
}