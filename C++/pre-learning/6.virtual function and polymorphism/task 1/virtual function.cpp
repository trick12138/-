#include <iostream>
using namespace std;
//No.1 虚函数  在类中用virtual修饰的函数就是虚函数
//No.2 虚函数对于类的内存的影响
//2.1 空的类的内存: 1字节 (类中不存在虚函数)
//2.2 对于类有数据后,就按照c语言结构体一样的内存对齐方式去计算内存
//2.3 虚函数对于类的内存影响  无论多少个虚函数都是用一个指针去存储,所以只会增加一个指针类型的字节数(4)
//No.3 通过虚函数表  去访问函数

class MM
{
public:
    virtual void print()
    {
        cout << "我是虚函数!" << endl;
    }
    virtual void printMM()
    {
        cout << "第二个虚函数!" << endl;
    }
    virtual void printValue();
protected:

};

//类外实现不需要virtual修饰

void MM::printValue()
{
    cout << "第三个虚函数" <<endl;
}

class Boy
{
public:

protected:

};

int main()
{
    cout << "Boy:" << sizeof(Boy) << endl;
    cout << "MM:" << sizeof(MM) << endl;
    MM mm;
    int** pObject = (int**)&mm;
    pObject[0][1];
    typedef void(*PF)();
    PF pf1 = (PF)pObject[0][0];
    pf1();              //调用第一个虚函数
    pf1 = (PF)pObject[0][1];
    pf1();              //调用第二个虚函数
    return 0;   
}