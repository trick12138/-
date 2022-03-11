#include <iostream>
using namespace std;
//No.1 纯虚函数就是没有函数体的虚函数  虚函数=0;
//No.2 具有至少一个纯虚函数的类叫抽象类
//  2.1 抽象类不能构建对象
//  2.2 抽象类可以构建对象指针
//No.3 ADT abstract data type :抽象数据类型
//抽象类被继承下来, 子类如果想要构建对象, 必须要把父类中的纯虚函数重写
//ADT习惯结合多态去使用

class MM
{
public:
    virtual void print() = 0;
protected:

};

class stack
{
public:
    virtual ~stack() {}
    virtual void push(int data) = 0;
    virtual void pop() = 0;
    virtual bool empty()const = 0;
    virtual int size()const = 0;
    virtual int top() = 0;
protected:

};

class arrayStack :public stack
{
public:
    virtual ~arrayStack() {}
    virtual void push(int data)
    {

    }
    virtual void pop()
    {

    }
    virtual bool empty()const
    {

    }
    virtual int size()const
    {

    }
    virtual int top()
    {
        
    }
protected:

};

class listStack :public stack
{
public:

protected:

};

int main()
{
    //MM mm;    抽象不能构建对象
    MM *pM = nullptr;
    stack *pStack = new arrayStack;
    for (int i = 0; i < 3; i++)
    {
        pStack->push(i);
    }
    

    return 0;
}