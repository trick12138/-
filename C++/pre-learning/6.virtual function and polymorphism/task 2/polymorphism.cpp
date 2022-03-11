#include <iostream>
using namespace std;
//No.1 继承中成员的访问问题
//1.1 如果只有一个函数, 不存在同名情况下, 调用那个函数, 看函数名就可以
//1.2 同名情况
//  1.2.1 正常情况: 采用就近原则
class MM
{
public:
    virtual ~MM()
    {
        cout << "~MM" << endl;
    }
    void print()
    {
        cout << "MM::print" << endl;
    }
    virtual void printVirtual()
    {
        cout << "MM::printVirtual" << endl;
    }
protected:

};

class Boy :public MM
{
public:
    ~Boy()
    {
        cout << "~Boy" << endl;
    }
    void print()
    {
        cout << "Boy::print" << endl;
    }
    virtual void printVirtual()
    {
        cout << "Boy::printVirtual" << endl;
    }
protected:

};

class Girl :public Boy
{
public:
    void printVirtual()
    {
        cout << "Girl::printVirtual" << endl;
    }
    //virtual void printVirtual()
protected:

};

int main()
{
    //No.2 多态访问
    //正常情况下的对象: 就近原则, 是哪个类的对象就调用哪个类的成员
    MM mm;
    Boy boy;
    mm.print();
    boy.print();
    MM *pM = new MM;
    Boy *pB = new Boy;
    pM->print();
    pB->print();
    //子类想要访问继承下来的同名函数, 可以强制指定: 类名::
    boy.MM::print();
    pB->MM::print();
    //非正常情况: 父类指针被子类对象初始化, 但子类对象不能被父类对象初始化
    //不存在virtual的情况下: 看指针的类型
    MM *pMM = new Boy;
    pMM->print();
    //Boy *pB = new MM; 危险,报错
    //父类中存在virtual的情况
    pMM->printVirtual();    //子类中的同名函数
    pMM = &mm;
    pMM->printVirtual();    //父类中的函数
    //C++ 多态, 因为赋值的不同而导致的相同行为的不同结果, 把这一现象称之为多态(重写)
    //多态的必要因素: 1.必须父类存在virtual 2.子类必须存在同名函数 3.必须存在这样非正常的指针的使用
    //父类指针被子类对象初始化
    pMM = &boy;
    pMM->printVirtual();
    Boy *pBG = new Girl;
    pBG->printVirtual();    //Girl
    //虚函数被继承无论多少次, 都是虚函数
    {
        //使用子类对象初始化父类的时候会引发析构问题, 只调用父类中的析构函数
        //所以在父类中使用virtual修饰析构函数, 这样也可以调用子类中的
        MM *pObject = new Boy;
        pObject->printVirtual();
        delete pObject;
    }

    cout << "......!!!!!!!!!" << endl;

    return 0;
}