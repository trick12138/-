#include <iostream>
#include <list>
#include <string>
#include <ctime>

using namespace std;
/*
    list: 双向链表
    No.1 基本操作
        1.1 包含list头文件
        1.2 插入元素
        1.3 遍历
                删除方式：1 2 3
                不删除
    No.2 操作自定义类型  重点在于重载

*/
template<class T>
void printData(list<T>& Data)
{
    for (auto v : Data)
    {
        cout << v << "\t";
    }
    cout << endl;
}

//list操作自定义类型
class MM
{
public:
    MM(string name, int age) :name(name),age(age){}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    friend ostream& operator<<(ostream& out,MM& object)
    {
        out << object.name << "\t" << object.age;
        return out;
    }
    //通过重载<的方式使得排序可用
    bool operator<(MM& object2)
    {
        return this->age < object2.age;
    }
protected:
    string name;
    int age;
};

bool compareByName(MM& object1,MM& object2)
{
    return object1.getName() < object2.getName();
}

void printMM(list<MM>& mm)
{
    for (auto v : mm)
    {
        cout << v.getName() << "\t" << v.getAge() << endl;
    }
}

//No.3 简单模拟
template <class T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T data) : data(data) ,next(nullptr){}
};
template <class T>
class my_list
{
public:
    my_list()
    {
        frountNode = NULL;
        tailNode = NULL;
    }
    T frount()
    {
        return frountNode;
    }
    T back()
    {
        return tailNode;
    }
    int size()
    {
        return curSize;
    }
    bool empty()
    {
        return curSize == 0;
    }
    void push_frount(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = frountNode;
        if (empty())
            tailNode = newNode;
        frountNode = newNode;
        curSize++;
        
    }
    void push_back(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        tailNode->next = newNode;
        if (empty())
            frountNode->next = newNode;
        tailNode = newNode;
        curSize++;
    }
public:
    class iterator
    {
    public:
        iterator(Node<T>* pMove) :pMove(pMove) {}
        iterator() = default;       //系统默认无参构造函数
        iterator operator++()
        {
            this->pMove = this->pMove->next;
            return (*this);
        }
        bool operator!=(iterator object)
        {
            return this->pMove != object.pMove;
        }
        T operator*()
        {
            return this->pMove->data;
        }
    protected:
        Node<T>* pMove;
    };
    iterator begin()
    {
        return iterator(frountNode);
    }
    iterator end()
    {
        return iterator(tailNode->next);
    }
protected:
    Node<T>* frountNode;
    Node<T>* tailNode;
    int curSize = 0;
};

int main()
{
    //测试自己写的容器
    my_list<int> myList;
    for (int i = 0; i < 3; i++)
    {
        myList.push_frount(i);
    }
    my_list<int>::iterator myIter = myList.begin();
    while (myIter != myList.end())
    {
        cout << *myIter << "\t";
        ++myIter;
    }
    cout << endl;
    for (auto v : myList)
    {
        cout << v << "\t";
    }
    cout << endl;
    
    srand((unsigned)time(NULL));
    list<MM> mm;
    for (int i = 0; i < 3; i++)
    {
        string temp;
        for (int j = 0; j < 4; j++)
        {
            temp = temp + (char)(rand() % 26 + 'A');
        }
        mm.push_back(MM(temp,i * 10));
        temp.clear();
    }
    printMM(mm);
    mm.sort();
    printData(mm);
    mm.sort(compareByName);
    printData(mm);
    //不删除的打印方式
    list<int> intList;
    int array[5] = {1,2,2,2,3};
    //直接用一段区间内存去初始化
    intList.assign(array,array + 5);
    printData(intList);
    list<int>::iterator intIter;
    for (intIter = intList.begin(); intIter != intList.end(); intIter++)
    {
        cout << *intIter << "\t";
    }
    cout << endl;
    //删除容器中所有相同元素
    for (intIter = intList.begin(); intIter != intList.end(); intIter++)
    {
        if (*intIter == 2)
        {
            intIter = intList.erase(intIter);
            intIter--;
        }
    }
    printData(intList);
    list<string> str;
    for (int i = 0; i < 3; i++)
    {
        char userKey = rand() % 26 + 'A';
        string temp;
        temp.assign(1,userKey);
        string data = "name";
        data += temp;
        str.push_back(data);
    }
    printData(str);
    //删除的方式遍历表
    str.sort();     //排序
    printData(str);
    str.reverse();  //反转
    printData(str);
    while (!str.empty())
    {
        //从头到尾打印
        /* cout << str.front() << endl;
        str.pop_front(); */
        cout << str.back() << "\t";
        str.pop_back();
    }
    cout << endl;
    
    return 0;
}