#include <iostream>
#include <string>
using namespace std;
/*
    C++运算符重载: 赋予运算符新的功能, 赋予运算符能够操作自定义类型
    运算符重载的实质是调用函数
        No.1    类成员函数重载
        No.2    友元重载
    函数返回值类型 operator运算符(参数){函数体:}
    函数参数: 友元重载: 参数个数等于操作数
              类成员函数重载: 参数个数 = 操作数 - 1
    注意: 
        1.一个运算符只能被重载一次
        2.运算符不违背运算符原本运算方式
*/

class Data
{
public:
    Data() {}
    Data(int first,int second) :first(first),second(second){}
    //类的成员函数重载
    Data operator+(Data object)
    {
        return Data(this->first + object.first,this->second + object.second);
    }
    //友元重载
    friend Data operator-(Data object1,Data object2);
    void print()
    {
        cout << first << ":" << second << endl;
    }
protected:
    int first;
    int second;
};

Data operator-(Data object1,Data object2)
{
    return Data(object1.first - object2.first,object1.second - object2.second);
}
//No.3 ++ -- 流运算符(>> <<)重载
class MM
{
public:
    MM(){}
    MM(string name,int money) :name(name),money(money){}
    MM operator++()
    {
        this->money++;
        return (*this);
    }
    MM operator++(int)  //无用参数 标记作用，表示是后置++
    {
        return MM(this->name,this->money++);
    }
    void print()
    {
        cout << name << ":" << money << endl;
    }
    //No.4  流重载
    //cout: ostream类的对象
    //cin:  isteam类的对象
    //注意点: 输入输出重载必须要用友元重载
    friend ostream& operator<<(ostream& out,MM& object);
    friend istream& operator>>(istream& in,MM& object);
protected:
    string name;
    int money;
};

ostream& operator<<(ostream& out,MM& object)
{
    out << object.name << ":" << object.money << endl;
    return out;
}

istream& operator>>(istream& in,MM& object)
{
    cout << "input name and money:" << endl;
    in >> object.name >> object.money;
    return in;
}

//No.4 文本重载
//参数一定是unsigned long long
unsigned long long operator ""_h(unsigned long long num)
{
    return num * 60 * 60;
}
//最后一个点
/*
    1.= () -> [] 只能采用成员函数的方式重载
    2. . .* ?: :: 不能被重载
    3.重载必须存在一种自定义类型(注意项: 1+自定义类型)
    4.通常情况习惯于 : 单目运算符用成员函数重载,双目运算符用友元方式
*/

class Value
{
public:
    Value(int data = 0)
    {
        this->data = data;
    }
    Value operator+(Value object)
    {
        return Value(this->data+object.data);
    }
    void print()
    {
        cout << data << endl;
    }
protected:
    int data;
};

int main()
{
    Data object1(1,2);
    Data object2(2,3);
    Data result;
    //object1 + object2解析为：object1.operator+(object2);
    result = object1 + object2;
    result.print();
    result = object1 - object2;
    result.print();
    //++ --
    //a++ a=a+1
    //++a
    MM mm("小芳",300);
    (++mm).print();
    (mm++).print();
    string str("LoveYou");
    cout << str << endl;

    MM temp;
    cin >> temp;    //operator>>(cin,temp);
    cout << temp;
    float iNum = 1.1f;
    cout << 6_h << endl;

    Value first(100);
    Value second;
    second = first + 1; //first.operator+(1)
    second.print();

    return 0;
}