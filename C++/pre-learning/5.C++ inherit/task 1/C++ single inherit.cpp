#include <iostream>
using namespace std;
/*
    单继承中构造函数的写法
    1.子类的构造函数必须要调用父类的构造函数,因为继承下来的属性,只能通过父类的构造函数进行初始化
    2.子类的构造函数 初始化父类的属性的时候,必须采用初始化参数列表的方式进行初始化
    3.如果你不想要写父类的构造函数,缺省的写法,就是父类中准备一个无参的构造函数
    4.当父类没有无参的构造函数的时候,必须显示的用初始化参数列表调用父类的构造函数
    注意点: 
        No.1 继承具有继承性! 血脉 一直在,所以一般一个类不会被继承太多次数, 一般一个类也不会继承太多个父类
        No.2 采用私有继承可以避免一个类被其他类继承使用(绝育)
*/
class MM
{
public:
    /* MM()
    {
        cout << "父类的构造函数" << endl;
    } */
    MM(string name,int money) :name(name),money(money)
    {
        cout << "调用父类有参构造函数" << endl;
    }
protected:
    string name;
    int money;
};

class Boy : public MM
{
public:
    //父类属性必须使用初始化参数列表
    Boy(string boyName,string name,int money) :MM(name,money)
    {
        this->boyName = boyName;
    }
    void print()
    {
        cout << boyName << ":" << name << ":" << money <<endl;
    }
protected:
    //string name;
    //int money
    string boyName;
};

class Girl :public Boy
{
public:
    Girl(string name,string boyName,int money) :Boy(boyName, name,money)
    {

    }
protected:
    //string name;
    //int money;
    //string boyName;
};

int main()
{
    Boy boy("张三" ,"MM",100);
    boy.print();
    Girl girl("MM","girl",200);
    girl.print();
    return 0;
}