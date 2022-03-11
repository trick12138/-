#include <iostream>
#include <string>
using namespace std;
/*
    No.1    继承中的基本概念
    父类    子类
    基类    派生类(子类中有新增东西)
    No.2    如何写一个继承
    class 子类:继承方式  父类名
    {

    };
    继承方式  public protected private
    No.2    继承的实质: 表示父类的属性在子类当中存在
    No.3    继承的权限问题
        继承方式    public      protected       private
        父类属性
        public:     public:    protected        private
        protected:  protected: protected        private 
        private:    不可访问    不可访问        不可访问
    权限限定词只会增强权限(public:低----private:高)
    No.4 继承中的构造函数的写法
    
*/
class Father
{
public:
    void print()
    {
        cout << "钱" << endl;
    }
protected:
    int money;
private:
    string name;
};
//共有继承
class Son1 :public Father
{
public:
    void printSon()
    {
        //print();
        cout << money << endl;
        //cout << name << endl; //父类中私有属性无论什么继承方式,子类都无法访问.
        cout << "钱" << endl;
    }
    //void print()
protected:
    //int money
private:
    //string name
};

class Son2 :protected Father
{
public:

protected:
    //void print()
    //int money
};

class Son3 :private Father
{
public:
    void printF()
    {
        print();
    }
private:
    //void print();
    //int moeny;
};

int main()
{
    Son1 son;
    son.print();
    Son2 son2;
    //son2.print(); 权限不够
    Son3 son3;
    son3.printF();

    return 0;
}