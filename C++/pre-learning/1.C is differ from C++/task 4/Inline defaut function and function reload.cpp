#include <iostream>
using namespace std;

//No.1 函数内联：以二进制的形式存在
//1.1 内联函数的特点：短小精悍
//1.2 inline
//1.3 如果在结构体中或者在类中实现的函数默认为内联函数
inline int Max(int a, int b)
{
    return a>b? a : b;
}

//No.2 函数重载: 允许同名不同参的函数存在
//增加标识符的使用率
void print(int a, int b)
{
    cout << a + b << endl;
}

//2.1 参数的个数不同
void print(int a)
{
    cout << a << endl;
}

//2.2 参数的类型不同
void print(int a, char b)
{
    cout << a + b <<endl;
}

//2.3 参数的顺序不同: 一定是在不同类型的基础上
void print(char b, int a)
{
    cout << a + b <<endl;
}

//No.3 函数缺省：就是给函数参数初始化
//注意：缺省的顺序只能从右往左连续性的缺省
//          多文件中,只需在声明中缺省即可
int sum(int a = 0, int b = 0, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main()
{
    //函数重载
    print(1,2);
    print(1);
    print('A',1);
    print(2,'A');
    //函数的缺省
    cout << sum (11,22,33,44) << endl;
    cout << sum() << endl;
    cout << sum(1) << endl;
    cout << sum(1,2) << endl;
    cout << sum(1,2,3) << endl;
    return 0;
}