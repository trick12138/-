#include <iostream>
#include <deque>
#include <list>

using namespace std;
/*
    No.1 基本操作
    dequeue: 双向队列


*/
class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    friend ostream& operator<<(ostream& out, MM& object)
    {
        out << object.name << "\t" << object.age;
        return out;
    }
protected:
    string name;
    int age;
};
//借用list模板简单实现deque
template <class T>
class MyDeque
{
public:
    MyDeque() = default;
    void push_back(T data)
    {
        mem.push_back(data);
    }
    void push_front(T data)
    {
        mem.push_front(data);
    }
    int size()
    {
        return mem.size();
    }
    bool empty()
    {
        return mem.size() == 0;
    }
    T& front()
    {
        return mem.front();
    }
    T& back()
    {
        return mem.back();
    }
    void pop_front()
    {
        mem.pop_front();
    }
    void pop_back()
    {
        mem.pop_back();
    }
protected:
    list<T> mem;
};

void print(deque<int> data)
{
    while(!data.empty())
    {
        cout << data.front() << "\t";
        data.pop_front();
    }
}

int main()
{
    deque<int> data;    
    //插入数据
    for (int i = 0; i < 3; i++)
    {
        data.push_back(i);
    }
    //从头到尾遍历
    while (!data.empty())
    {
        cout << data.front() << "\t";
        data.pop_front();
    }
    cout << endl;
    deque<string> str;
    str.push_back("ILoveYou");
    str.push_back("IMissYou");
    while (!str.empty())
    {
        cout << str.back() << "\t";
        str.pop_back();
    }
    cout << endl;
    //No.2 操作自定义类型
    deque<MM> mmDeque;
    mmDeque.push_back(MM("小可爱",18));
    mmDeque.push_back(MM("亲爱的",19));
    while (!mmDeque.empty())
    {
        cout << mmDeque.back() << endl;
        mmDeque.pop_back();
    }
    cout << endl;
    //No.3 简单模拟一下容器
    MyDeque<MM> myMM;
    myMM.push_back(MM("小可爱",18));
    myMM.push_back(MM("亲爱的",19));
    while (!myMM.empty())
    {
        cout << myMM.back() << endl;
        myMM.pop_back();
    }
    cout << endl;
    int array[3] = {1,2,3};
    deque<int> deq;
    deq.assign(array,array + 3);
    print(deq);
    return 0;
}