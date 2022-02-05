#include <iostream>
using namespace std;

bool size(int listCurSize)
{
    return listCurSize == 0;
}

//引用充当函数参数
void modifyNum(int& iNum)   //int &iNum == mm;
{
    iNum = 10007;
}

//引用充当函数参数:增加左值使用
int& returnValue(int& iNum)
{
    return iNum;
}

//充当函数右值使用
void print(const int& iNum)
{
    //iNum++ 常引用的局限性 不能修改
    cout << iNum << endl;
}

//充当右值的常引用
void printValue(int&& iNum)
{
    iNum++;
    cout << iNum << endl;
}

int Max(int a,int b)
{
    return a>b ? a : b;
}

struct MM
{
    int age;
};

int main()
{
    //No.1 新的空指针
    int *p = NULL;      //这种写法是将0进行强制类型转换(*void)0
    int *cpp = nullptr; //空类型的空指针
    //No.2 新的数据类型之bool
    //2.1 bool代表的是真和假
    //2.2 bool打印的只有两个0或者1
    //2.3 计算机中非0值都表示成立
    //2.4 bool占用一个字节的内存
    //2.5 通常情况下bool用来充当条件判断的返回值,或者充当开关标记使用
    bool bNum = -1;
    cout << bNum << endl;
    cout << sizeof(bool) << endl;
    //No.3 引用类型
    //3.1 基本用法：起别名
    int mm = 1;
    int &cute = mm;
    cute = 10001;
    cout << mm << endl;
    //3.2 函数返回值或者参数
    modifyNum(mm);
    cout << mm <<endl;
    //3.3 用于函数返回值增加左值使用
    //一般情况下返回值为常量，无法修改
    returnValue(mm) = 122;  //不能返回局部的引用
    //int& x = returnValue(mm) = iNum
    cout << mm << endl;
    //3.3 右值引用
    //3.3.1 常引用可以表达右值
    const int& cNum = 1234;
    print(12);
    printValue(1234);
    //传变量
    printValue(move(mm));        //右值引用如何传左值引用 move可以将左值转换为右值
    //No.4 auto 类型：自动推断类型
    //这里将MAX的返回值地址赋值给了pMax(int, int)
    int (*pMax)(int, int) = Max;
    cout << pMax(4,5) << endl;
    auto pFunc = Max;
    //自动推断类型可以自动推断出转换的类型
    cout << pFunc(1,2) << endl;
    //也可以推断结构体
    struct MM object = {1};
    //直接推断出&object为struct MM*
    auto pObject = &object;
    return 0;
}