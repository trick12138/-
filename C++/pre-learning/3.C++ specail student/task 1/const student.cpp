#include <iostream>
using namespace std;

/*
    const数据成员
        1.具备const特性, 常:只读, 不可修改
        2.必须要初始化
        3.初始化必须要用初始化参数列表的方式去初始化
        构造函数(形参1,形参2,形参3...):数据1(形参1)...
    const 成员函数
        1.注意的写法: const写在被修饰的函数的后面
        2.常成员函数不可修改数据
        3.常成员函数可与普通同名函数共存,类似于重载
        普通对象优先调用普通函数
        如果没有普通函数,肯定调用有的函数
    const 对象
        常对象只能调用常成员函数
*/

//const数据成员
class MM
{
public:
    MM(string name, int num) : age(num)
    {
        name = this->name;
    }
    MM():age(1)
    {
        cout << "无参的构造函数" << endl;
    }
    void print()
    {
        //age++ 常数据成员不可修改
        cout << age << endl;
    }
protected:
    string name;
    const int age;
};

class Boy
{
public:
    Boy(int money) : money(money){} 
    //常成员函数
    void print() const
    {
        //money++ 常成员函数不能修改数据成员
        cout << "money_const:" << money << endl;
    }
    void print()
    {
        money++;
        cout << "money:" << money << endl;
    }
protected:
    int money;
};

int main()
{
    MM mm;
    mm.print();
    MM mm2("小可爱",111);
    mm2.print();

    Boy boy(100);

    const Boy constBoy(101);
    constBoy.print();

    return 0;
}