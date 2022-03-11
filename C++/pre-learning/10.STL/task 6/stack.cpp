#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
/*
    STL之stack: 栈 --->FILO
    1 2 3
    3 2 1
    1.包含stack的头文件
    2.一些常用的函数
    
*/
//No.2 栈去操作自定义类型
class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    friend ostream& operator<<(ostream& out,MM mm)
    {
        out << mm.name << "\t" << mm.age;
        return out;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
protected:
    string name;
    int age;
};

//简单模拟一下栈结构-->链表栈
template <class T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T data) :data(data) ,next(nullptr){}
};
template <class T>
class my_stack
{
public:
    my_stack()
    {
        stackTop = nullptr;
    }
    bool empty()
    {
        return stackTop == 0;
    }
    void push(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = stackTop;
        stackTop = newNode;
        stackSize++;
    }
    void pop()
    {
        if (stackSize == 0)
            return;
        Node<T>* posNode = stackTop;
        stackTop = stackTop->next;
        delete posNode;
        posNode = nullptr;
        stackSize--;
    }
    T top()
    {
        return stackTop->data;
    }
    int size()
    {
        return stackSize;
    }
protected:
    Node<T> *stackTop;
    int stackSize = 0;
};

//简单模拟一下栈结构-->数组栈
template<class T>
class myStack
{
public:
    myStack(){}
    void push(T data)
    {
        memory.push_back(data);
    }
    T top()
    {
        return memory[memory.size() - 1];
    }
    void pop()
    {
        memory.erase(memory.end() - 1);
    }
    int size()
    {
        return memory.size();
    }
    int empty()
    {
        return memory.size() == 0;
    }
protected:
    vector<T> memory;
};

int main()
{
    //No.2 栈的基本操作
    stack<int> data;
    for (int i = 0; i < 3; i++)
    {
        data.push(i);
    }
    while (!data.empty())
    {
        cout << data.top() << "\t";
        data.pop();                 //出栈
    }
    cout << endl;
    cout << "\t" << data.size() << endl;
    //No.2 栈去操作自定义类型
    stack<MM> mmStack;
    mmStack.push(MM("name1",18));
    mmStack.push(MM("name2",19));
    mmStack.push(MM("name3",20));
    while (!mmStack.empty())
    {
        cout << mmStack.top() << endl;
        mmStack.pop();
    }
    cout << endl;

    my_stack<int> myData;
    for (int i = 0; i < 3; i++)
    {
        myData.push(i);
    }
    while (!myData.empty())
    {
        cout << myData.top() << "\t";
        myData.pop();
    }

    cout << endl;

    myStack<int> myData2;
    for (int i = 0; i < 3; i++)
    {
        myData2.push(i);
    }
    while (!myData2.empty())
    {
        cout << myData2.top() << "\t";
        myData2.pop();
    }
    
    return 0;
}