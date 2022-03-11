#include <iostream>
using namespace std;
/*
    类中类定义
    1.直接在类中定义
    2.先声明, 在类外定义  需要被类名限定
    类中类的方式去访问
        剥洋葱的方式去访问
    注意问题: 类中类依然受权限限定
*/
class MM
{
public:
    MM(string name) : name(name) {}
    //类中类
    class Boy
    {
    public:
        Boy(int age) : age(age) {}
        void printAge();
    protected:
        int age;
    };
protected:
    string name;
};

void MM::Boy::printAge()
{
    cout << "age:" << age << endl;
}

class A
{
public:
    class B;
protected:

};

class A::B
{
public:
    void print()
    {
        cout << "A::B" << endl;
    }
protected:

};

int main()
{
    MM::Boy boy(1);
    boy.printAge();
    MM::Boy *pB = new MM::Boy(2);
    pB->printAge();
    A::B bObject;
    return 0;
}