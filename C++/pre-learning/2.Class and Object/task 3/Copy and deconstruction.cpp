#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*
    1. 拷贝构造函数
        1.1 特殊的构造函数
        1.2 拷贝构造函数只有唯一的一个参数 就是对对象的引用
        1.3 不写拷贝构造函数的时候 默认存在一个拷贝构造函数,如果自己写了拷贝构造函数,默认的就不存在了
    注意: 当使用赋值的方式并且产生了一个新的对象的时候就会调用构造函数
        1. MM girl = gg;   //调用拷贝构造函数
        2. 函数传参的时候
        3. 当作普通的构造函数构造对象
    2. 析构函数: 用来释放数据成员申请的堆内存
        2.1 ~类名(无参){}
        2.2 析构无法重载
        2.3 不写析构函数会存在一个默认的
        2.4 当对象死亡的时候会调用
        2.5 什么时候需要写, 就是对象中有指针且申请了内存
    3. 深拷贝和浅拷贝
*/
class MM
{
public:
    MM(){}
    MM(string name) :name(name)
    {
        cout << "构造函数" << endl;
    }
    //拷贝构造函数
    MM(MM& object)
    {
        cout << "拷贝构造函数" << endl;
    }
    MM& operator = (MM object)
    {
        cout << "重载=" << endl;
        return *this;
    }
    void print()
    {
        cout << name << endl;
    }
    ~MM()
    {
        cout << "析构函数" << endl;
    }
protected:
    string name;
};

void printObject(MM object) //MM object = mm;   实参传给形参的时候也会调用构造函数
{
    object.print();
}
void printObject1(MM& object)
{
    object.print();
}

class Boy
{
public:
    Boy(const char *str) 
    {
        int size = sizeof(str) + 1;
        name = new char[size];
        strcpy(name,str);
    }
    ~Boy()
    {
        if (name != nullptr)
            delete[] name;
    }
protected:
    char *name;
};

int main()
{
    MM mm = {"小可爱"};
    MM girl = mm;       //调用拷贝构造函数
    mm.print();
    MM gg;
    gg = mm;            //没有调用拷贝构造函数: 因为是赋值，并没有创建一个新的对象
    gg.print();
    printObject(mm);
    printObject1(mm);
    //正规的构造函数
    MM beauty(mm);
    beauty.print();

    return 0;
}