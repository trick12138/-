#include <iostream>
using namespace std;
//No.1 ���麯������û�к�������麯��  �麯��=0;
//No.2 ��������һ�����麯������г�����
//  2.1 �����಻�ܹ�������
//  2.2 ��������Թ�������ָ��
//No.3 ADT abstract data type :������������
//�����౻�̳�����, ���������Ҫ��������, ����Ҫ�Ѹ����еĴ��麯����д
//ADTϰ�߽�϶�̬ȥʹ��

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
    //MM mm;    �����ܹ�������
    MM *pM = nullptr;
    stack *pStack = new arrayStack;
    for (int i = 0; i < 3; i++)
    {
        pStack->push(i);
    }
    

    return 0;
}