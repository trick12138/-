#include <iostream>
#include <string>
#include "myHead.hpp"

using namespace std;
//No.1 模板的起源
//为了避免因为类型不同导致需要重复编写代码的问题
//No.2 函数模板
//2.1 声明方式： temple <typename type,...> 函数
//typename 也可以换成class
// int Max(int a,int b)
// {
//     return a > b ? a : b;
// }

// float Max(float a,float b)
// {
//     return a > b? a : b;
// }
template <class T>
T Max(T a, T b)
{
    return a > b ? a : b;
}
//No.3 模板的重载
template <class T>
void print(T data)
{
    cout << "一个参数...." << endl; 
    cout << data << endl;
}
template <class A,class B>
void print(A first,B second)
{
    cout << "两个参数...." << endl;
    cout << first << "\t" << second << endl;
}
void print(char first,char second)
{
    cout << "普通函数...." << endl;
    cout << first << "\t" << second << endl;
}

class Student
{
public:
    Student(string name, int score) :name(name), score(score) {}
    friend ostream& operator<<(ostream& out, Student object)
    {
        out << object.name << "\t" << object.score << endl;
        return out;
    }
    bool operator>(Student object)
    {
        return this->score > object.score;
    }
protected:
    string name;
    int score;
};
//No.4 模板的特化
template <>
void print(int first,int second)
{
    cout << "函数特化...." << "/t" << second << endl;
}
//注意点： 多文件模板特化的写法

//模板重载
template <class T>
void print(T first,T second)
{
    cout << "两个一样...." << endl;
    cout << first << "\t" << second << endl;
}

int main()
{
    //2.2.1 隐士调用
    cout << Max(1, 2) << endl;                               //T=int
    cout << Max(1.1, 1.2) << endl;                           //T=double
    cout << Max(string("ILoveYou"), string("IMissYou"));     //T=string
    //2.2.2 模板的显式调用
    cout << Max<int>(1, 2) << endl;
    //2.2.3 传入自定义类型
    //关键在于函数的重载
    cout << Max(Student("name1", 100), Student("name2",97)) << endl;
    cout << Max<Student>(Student("name1", 100), Student("name2",97)) << endl;
    print('A','B');                                             //优先调用类型一致的普通函数
    print<char,char>('A','B');
    print<int>(1,2);                                            //优先调用两个一样的
    printValue(1,2);
    return 0;
}