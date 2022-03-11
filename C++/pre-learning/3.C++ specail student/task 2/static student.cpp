#include <iostream>
using namespace std;
//static数据成员
//1.类中用static修饰的数据成员，就是静态数据成员
//2.通常静态数据必须在类外初始化，初始化的需要static修饰，但需要类名：：限定
//3.静态数据成员的访问：类外访问不需要对象即可访问，也可以对象去访问，但是依然受权限限定，类中访问和普通变量一样的
//4.静态数据成员时所有对象共有的，也就是所有对象用的都是同一个静态数据成员
//静态函数：用static修饰函数
//1.不允许在同一个类中存在同名同参的普通成员
//2.在类外实现函数，不需要static修饰，但要用类名限定
//3.依然受权限限定，一般静态成员一般写public
//4.静态数据成员类外访问，也可以不用对象即可访问(类名::函数名) 也可以采用对象的方式调用
//5.所有类共有的行为
//7.静态函数中是没有this指针的
//8.静态函数中访问非静态数据成员的时候，需要指定一个对象
//9.静态函数中访问静态数据成员

class MM
{
public:
    MM(string name) : name(name)
    {
        this->count++;
    }
    void print()
    {
        cout << name << ":" << count << endl;
    }
    static void printStatic();
    //通过传参的方式去指定对象，去访问非静态数据成员
    static void printValue(MM object);
protected:
    string name;
public:
    static int count;
};

int MM::count = 0;

void MM::printStatic()
{ 
    cout << "静态成员函数" << endl;
    cout << count << endl;
}

void MM::printValue(MM object)
{
    cout << object.name << ":" << object.count << endl;
}

class A
{
public:
    A(int count) :count(count)
    {
        count++;
    }
    int count;
};

void print()
{
    static A a(0);
    static int s_num = 0;
    a.count++;
    s_num++;
    cout << a.count++ << "\t" << s_num++ << endl;
}

int main()
{
    //1.直接访问
    cout << MM::count << endl;
    //2.可以通过对象去访问
    MM mm("小可爱");
    cout << mm.count << endl;
    MM boy("小男孩");
    cout << MM::count << endl;
    MM::printStatic();
    boy.printStatic();
    mm.printValue(mm);
    mm.printValue(boy);
    print();
    print();
    print();
    return 0;
}