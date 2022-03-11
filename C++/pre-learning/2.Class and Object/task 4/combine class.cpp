#include <iostream>
using namespace std;
/*
    组合类: 一个类以另一个类的对象为数据成员, 组合关系一般似乎用在描述一部分的关系
    1.构造函数的写法
        1.1 组合类必须要调用分支类的构造函数
        1.2 组合类的构造写法必须时初始化参数列表的写法
    2.构造与析构的顺序
        2.1 优先按照分支类的对象,顺序按照组合类中的声明对象顺序去构造,和初始化参数列表无关
        2.2 析构顺序: 一般情况和构造顺序相反(栈)
        2.3 delete释放对象指针(非nullptr)的时候 就会调用构造函数
*/

class Mouse
{
public:
/*     Mouse()
    {
        cout << "mouse" << endl;
    } */
    Mouse(string mouse):mouseType(mouse)
    {
        cout << "mouse" << endl;
    }
    string& getMouseType()
    {
        return mouseType;
    }
    ~Mouse()
    {
        cout << "A" << endl;
    }
protected:
    string mouseType;
};

class Eye
{
public:
/*     Eye()
    {
        cout << "Eye" << endl;
    } */
    Eye(int count)
    {
        this->count = count;
        cout << "Eye" << endl;
    }
    int& getCount()
    {
        return count;
    }
    ~Eye()
    {
        cout << "B" << endl;
    }
protected:
    int count;
};

class Head
{
public:
    //1.必须调用分支类的构造函数
    //2.当分支类存在无参构造函数的时候,组合类的构造函数可以不用写出来
    //但是要明白，虽然没有写出来，但还是会调用分支类的无参构造函数
    //注意是：初始化参数列表的写法
    //构造函数(参数表) : 数据成员1(形参)
    Head(string whoHead,int count,string mouseType) : mouseType(mouseType),eye(count)
    {
        this->whoHead = whoHead;
    }
    void print()
    {
        cout << "姓名:" << whoHead << endl;
        cout << "眼睛数" << eye.getCount() << endl;
        cout << "嘴型:" << mouseType.getMouseType() << endl;
    }
    ~Head()
    {
        cout << "C" << endl;
    }
protected:
    string whoHead;
    //以另一个类的对象为数据成员
    //构造顺序和这里有关系，按照声明的顺序去构造
    Eye eye;
    Mouse mouseType;
};

class MM
{
public:
    MM(string info) : info(info)
    {
        cout << info << endl;
    }
    ~MM()
    {
        cout << info << endl;
    }
protected:
    string info;
};

int main()
{
    {
        Head boy("歪嘴邪神",3,"歪嘴");
        //boy.print();
    }
    cout << "普通的构造和析构顺序问题" << endl;
    {
        MM *pMM = new MM("3");
        MM mm1("1");
        delete pMM;
        pMM = nullptr;
        MM mm2("2");
    }
    //创建对象指针的时候，是否会调用构造函数
    //创建对象指针，不会调用构造函数
    MM *pMM = nullptr;
    cout << "不会调用构造函数" << endl;
    return 0;
}