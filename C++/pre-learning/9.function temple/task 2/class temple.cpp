#include <iostream>
#include <string>

using namespace std;
//No.1 类模板， 只要用temple修饰的类 称之为类模板\
//注意点： 类模板必须显示实例化
//  1.1 类模板必须显示实例化
//  1.2 类模板不是一个完整的类，所以我们要用到类名的时候，都要采用显示方式调用
//      类名<类型...>方式使用
template <class T>
class Test
{
public:
    void print()
    {
        cout << "类模板中的函数" << endl;
    }
    void printValue();
protected:
};

template <class T>
void Test<T>::printValue()
{
    cout << "Test<T>::" << endl;
}

template <class T>
class MM
{
public:
    MM(T info) :info(info) {}
    void print()
    {
        cout << info << endl;
    }
protected:
    T info;
};

template <class A, class B>
struct MMinfo
{
    A first;
    B second;
    MMinfo(A first, B second) :first(first), second(second) {}
};
template <class A, class B>
ostream& operator<<(ostream& out, MMinfo<A, B> object)
{
    out << object.first << "\t" << object.second << endl;
    return out;
}
//No.2 类模板的继承
template <class T>
class Boy :public MM<T>
{
public:
    //初始化参数列表其实也是调用父类的构造函数，用就是父类的名字，所以必须采用类名<类型>
    Boy(T info) :MM<T>(info) {}
protected:
};
//No.3 类模板中的静态数据成员
template <class T>
class Man
{
public:
    Man(T info) :info(info)
    {
        count++;
    }
    void print()
    {
        cout << info << "\t" << count << endl;
    }
protected:
    T info;
public:
    static int count;
};
template <class T>
int Man<T>::count = 0;

template <class T>
class Compare
{
public:
    static bool compare(T a, T b)
    {
        return a > b;
    }
protected:
};

template <>
class Compare<int>
{
public:
    static bool compare(int a, int b)
    {
        cout << "完全特化" << endl;
        return a > b;
    }
protected:
};

/* template <class T>
class Compare
{
public:
    static bool compare(const T& a,const T& b)
    {
        cout << "局部特化" << endl;
        return a > b;
    }
}; */

template <class A, class B>
class PrintInfo
{
public:
    static void Print(A first, B second)
    {
        cout << "原生模板" << endl;
        cout << first << "\t" << second << endl;
    }
protected:

};

//两个类型特化成一个类型
template <class T>
class PrintInfo<T,T>
{
public:
    static void Print(T first, T second)
    {
        cout << "局部特化" << endl;
        cout << first << "\t" << second << endl;
    }
protected:

};

//No.5 注意点：类模板多文件的时候，只能在同一个.h文件里写

int main()
{
    Test<int> testObject;
    testObject.print();
    Test<string>* testString = new Test<string>;
    testString->printValue();
    delete testString;
    MM<string> mm(string("小可爱"));
    mm.print();
    //模板类
    //MMinfo<string,int>
    MM<MMinfo<string, int>> girl(MMinfo<string, int>(string("小芳"), 18));
    girl.print();
    Boy<string> boy("帅哥");
    boy.print();
    //静态函数
    Man<string> manObject("帅哥");
    manObject.print();
    cout << Man<string>::count << endl;     //1
    Man<int> coolMan(18);
    cout << Man<int>::count << endl;
    coolMan.print();                        //类型不同时所属类也不同
    Compare<int>::compare(1, 2);
    const int a = 1;
    const int b = 2;
    Compare<int>::compare(1, 2);
    PrintInfo<string, int>::Print(string("小可爱"), 18);
    PrintInfo<string, string>::Print(string("帅哥大叔"), string("美女小姐"));
    return 0;
}