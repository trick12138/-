#include <iostream>
#include <queue>
#include <string>

using namespace std;
/*
    No.1 queue的基本操作
    STL: queue:队列 FIFO
    No.2 操作自定义类型

*/

class MM
{
public:
    MM(string name,int age) :name(name), age(age){}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    friend ostream& operator<<(ostream& out,MM object)
    {
        out << object.name << "\t" << object.age;
        return out;
    }
protected:
    string name;
    int age;
};

template <class T>
class myQueue
{
public:
    myQueue(){}
    void push(T data)
    {
        mem.push_back(data);
    }
    void pop()
    {
        mem.erase(mem.begin());
    }
    T front()
    {
        return mem[0];
    }
    int size()
    {
        return mem.size();
    }
    bool empty()
    {
        return mem.size() == 0;
    }
protected:
    vector<T> mem;
};

int main()
{
    //No.1 队列的基本操作
    queue<int> data;
    for (int i = 0; i < 3; i++)
    {
        data.push(i);
    }
    while (!data.empty())
    {
        cout << data.front() << "\t";
        data.pop();
    }
    cout << endl;
    cout << data.size() << endl;
    //No.2 操作自定义类型
    queue<MM> mmQueue;
    mmQueue.push(MM("小可爱",18));
    mmQueue.push(MM("小宝贝",29));
    mmQueue.push(MM("亲爱的",22));
    cout << mmQueue.size() << endl;
    while (!mmQueue.empty())
    {
        cout << mmQueue.front() << endl;
        mmQueue.pop();
    }
    cout << endl;

    myQueue<MM> myMM;
    myMM.push(MM("小可爱",18));
    myMM.push(MM("小宝贝",29));
    myMM.push(MM("亲爱的",22));
    cout << myMM.size() << endl;
    while (!myMM.empty())
    {
        cout << myMM.front();
        myMM.pop();
    }
    cout << endl;
    return 0;
}