#include <iostream>
#include <string>
using namespace std;
/*
    多继承: 多个父类
    1.和单继承中的继承区别不大,无非就是多个父类
    2.继承构造函数写法:初始化参数列表, 调用多个父类的构造函数即可
    3.class 子类名: 继承方式1,父类1,继承方式2,父类2...
    {


    };
    欧美 阳肖
    欧阳肖美
    4.构造顺序之和继承顺序有关,和初始化参数列表无关

*/
class MM
{
public:
    MM(string mmFName,string mmSName) :mmFName(mmFName),mmSName(mmSName)
    {
        cout << "MM" << endl;
    }
    void printMM()
    {
        cout << "MM:" << mmFName + mmSName << endl;
    }
protected:
    string mmFName;
    string mmSName;
};

class GG
{
public:
    GG(string ggFName,string ggSName) :ggFName(ggFName),ggSName(ggSName)
    {
        cout << "GG" << endl;
    }
    void printGG()
    {
        cout << "GG:" << ggFName + ggSName <<endl;
    }
protected:
    string ggFName;
    string ggSName;
};

//类的构造顺序只和你在继承的顺序有关
class Boy :public MM,protected GG
{
public:
    //构造函数写法
    Boy(string ggFName,string ggSName,string mmFName,string mmSName) :GG(ggFName,ggSName),MM(mmFName,mmSName)
    {
        this->boyFName = ggFName + mmFName;
        this->boySName = ggSName + mmSName;
    }
    void print()
    {
        cout << this->boyFName + this->boySName <<endl;
    }
protected:
    string boyFName;
    string boySName;
};

//虚继承
//一旦用了虚继承, 子类必须用爷爷辈的构造函数,初始化相同数据
class A
{
public:
    A(int a) :a(a){}
protected:
    int a;
};

//虚继承
class B :virtual public A
{
public:
    B(int a,int b) :b(b),A(a){}
protected:
    int b;
};

class C :virtual public A
{
public:
    C(int a,int c) :c(c) ,A(a){}
protected:
    int c;
};

class D :public B,public C
{
public:
    D(int a,int b,int c,int d) :C(a,c),B(a,b),d(d),A(123)
    {

    }
    void print()
    {
        cout << a << b << c << d << endl;
        cout << C::a << B::a << endl;
    }
protected:
    int d;
};

int main()
{
    Boy boy("欧","美","阳","肖");
    boy.print();
    D object(1,2,3,4);
    object.print();
    return 0;
}