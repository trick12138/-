#include <iostream>
using namespace std;
/*
    C++友元：打破类的封装性(打破权限限制)
    1.友元函数
        friend在一个类中去修饰函数
        1.友元是一个独立的函数,不属于类,所以在类外实现的时候不需要类名限定
        2.在当前函数中赋予对象具有访问任何属性的权利
        3.以另一个类的成员函数为友元函数时要注意顺序问题
    2.友元类
        把另一个类声明为类的友元类,在另一个类中的所有对象都可以无视权限
        记住一个重点:在一定作用域下,只能赋予自身类的对象访问自身属性的权限
*/

class MM
{
public:
    MM(string name,int age) :name(name),age(age){}
    friend void visitedValue();
    friend void visited(MM object);
private:
    void print()
    {
        cout << name << ":" << age << endl;
    }
protected:
    string name;
    int age;
};

void visitedValue()
{
    //在当前函数中赋予对象具有访问任何属性的权利
    MM girl("小甜心",28);
    girl.print();
    cout << girl.name << ":" << girl.age << endl;
    MM *pMM = new MM("小美",16);
    pMM->print();
    cout << pMM->name << ":" << pMM->age << endl;
}

class Girl
{
public:
    //将某类中将某个类声明为友元类，在该类中的成员可以访问另一个类中的所有成员，类外访问不受权限限定
    friend class Boy;
protected:
    int age;
private:
    void print()
    {
        cout << "private:" << endl;
    }
};

class Boy
{
public:
    void print()
    {
        Girl object;
        object.print();
        gObject.print();
    }
protected:
    Girl gObject;
};

void visited(MM object)
{
    object.print();
}

int main()
{
    MM mm("小可爱",18);
    //mm.print();
    visited(mm);
    Boy boy;
    boy.print();

    return 0;
}