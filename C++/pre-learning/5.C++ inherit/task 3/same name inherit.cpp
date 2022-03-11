#include <iostream>
#include <string>
using namespace std;
class MM
{
public:
    //本类中的数据成员和成员函数中参数同名
    //1.初始化参数列表的方式解决
    MM(string name) :name(name)
    {

    }
    //2.this指针的方式解决
    void init(string name)
    {
        //this->name = name;
        //3.采用作用域分辨符 类名::
        MM::name = name;
    }
    void print()
    {
        cout << this->name << endl;
    }
protected:
    string name;
};

class Boy :public MM
{
public:
    Boy(string mmName,string name) :MM(mmName),name(name)
    {

    }
    void print()
    {
        //在没有特别标识的情况下, 采用就近原则
        cout << name << endl;
        cout << MM::name <<endl;    //作用域分辨符指定数据访问
    }
protected:
    string name;
};

int main()
{
    Boy boy("小芳","小明");
    boy.MM::print();    //在没有特别标识的情况下, 采用就近原则


    return 0;
}