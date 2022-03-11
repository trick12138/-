#include <iostream>
#include <queue>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
    No.1 基本操作
    priority_queue: 优先队列 (排好序的队列)




*/
class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    string getName() const
    {
        return name;
    }
    int getAge() const
    {
        return age;
    }
    bool operator>(const MM& object) const
    {
        return this->age > object.age;
    }
    bool operator<(const MM& object) const
    {
        return this->age < object.age;
    }
protected:
    string name;
    int age;
};
//_Ty表示数据类型，_Contaner表示容器，采用缺省的方式，默认使用vector向量，_Py表示比较方式
template <class _Ty,class _Contaner = vector<_Ty>,class _Py = less<_Ty>>
class My_Priority_queue
{
public:
    My_Priority_queue(){}
    void push(_Ty data)
    {
        mem.push_back(data);
        sort(mem.begin(),mem.end(),_Py());
    }
    void pop()
    {
        mem.erase(mem.begin());
    }
    const _Ty& top()
    {
        return mem.front(); 
    }
    bool empty() const
    {
        return mem.empty();
    }
protected:
    _Contaner mem;
};


int main()
{
    srand((unsigned)time(NULL));
    //最完整版的
    //int: 代表储存的数据类型
    //vector<int>: 底层实现容器
    //less<int>: 排序准则 从小到大
    priority_queue<int, vector<int>, less<int>> data;      //从大到小
    priority_queue<int> num;                               //默认也是从大到小
    priority_queue<int,vector<int>> cNum;                  //默认从大到小
    for (int i = 0; i < 10; i++)
    {
        num.push(rand() % 100);                             //入队
    }
    while(!num.empty())
    {
        cout << num.top() << "\t";                          //出队
        num.pop();
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> info;    //从大到小
    for (int i = 0; i < 10; i++)
    {
        info.push(rand() % 100);                             //入队
    }
    while (!info.empty())
    {
        cout << info.top() << "\t";
        info.pop();
    }
    cout << endl;
    //No.2 priority_queue 操作自定义类型
    priority_queue<MM,vector<MM>,greater<MM>> mm;
    mm.push(MM("小可爱",19));
    mm.push(MM("小甜心",29));
    mm.push(MM("小白甜",23));
    while (!mm.empty())
    {
        //优先队列中Top函数返回的是常对象
        cout << mm.top().getName() << "\t" << mm.top().getAge() << endl;
        mm.pop();
    }
    cout << endl;
    //操作自定义类型时需查看stl源码，参考返回值类型去写重载函数
    //No.3 简单实现优先队列
    My_Priority_queue<MM,vector<MM>,greater<MM>> mm2;
    mm2.push(MM("小可爱",19));
    mm2.push(MM("小甜心",29));
    mm2.push(MM("小白甜",23));
    while (!mm2.empty())
    {
        //优先队列中Top函数返回的是常对象
        cout << mm2.top().getName() << "\t" << mm2.top().getAge() << endl;
        mm2.pop();
    }
    cout << endl;
    return 0;
}