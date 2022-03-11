#include <iostream>
#include <string>
using namespace std;
/*
    No.1 构造函数
        1. 没有返回值
        2. 名字和类名相同
        3. 不需要自己调用,一般是构造对象的时候被自动调用
        4. 不写构造函数, 就会默认存在一个构造函数
        5. 可以使用delete删除默认的构造函数 default 关键词表示使用的是默认的
        6. 当我们自己写了构造函数,默认的就不存在了
    No.2 构造函数与构造对象的过程
        1. 如果我们想要构造不同参数的对象的时候, 意味着我们需要不同类型参数的构造函数
        2. new一个对象的时候,首先是创建一个无名(匿名)对象 把对象的首地址赋值给指针
    No.3 初始化参数列表
        构造特殊写法
        类名(参数1,参数2,...)数据成员1(参数)...{}
    No.4 this指针代表每一个对象本身的地址

*/
class MM
{
public:
    //通过传参的方式
    //MM() = delete;    //删除默认的函数
    //MM() = default;   //表示当前使用的函数就是默认函数
    MM()
    {
        cout << "自己写了构造函数, 默认的构造函数就不存在了" << endl;
    }
    MM(string gName, int gAge)  //当我们用expicit修饰构造函数,意味着不能用 类名 对象 = （） 构造对象
    {
        name = gName;
        age = gAge;
        cout << "有参数的构造函数" << endl;
    }

    //通过传参的方式
    void init(string gName, int gAge)
    {
        name = gName;
    }
    //通过返回引用的方式初始化数据
    int& getAge()
    {
        return age;
    }
    string& getName()
    {
        return name;
    }
    void print()
    {
        cout << name << "\t" << age << endl;
    }
protected:
    int age;
    string name;
};

void print(MM object)
{
    object.print();
}

class Boy
{
public:
    Boy(string name,int age,int num):name(name),age(age),num(num){}
    void print()
    {
        cout << name << ":" << age << ":" << num << endl;
    }
protected:
    string name;
    int age;
    int num;
};

class Girl
{
public:
    Girl(string name,int age)
    {
        this->name = name;
        this->age = age;
    }
    void print()
    {
        cout << this->name << "\t" << this->age << endl;
    }
    Girl *getObject()
    {
        return this;
    }
protected:
    string name;
    int age;
};

int main()
{
    //无参对象调用无参构造函数
    MM object;  //构建对象的过程就是调用构造函数的过程
    object.getAge() = 11;
    object.getName() = "小可爱";
    MM objectMM("小甜心",18);
    objectMM.print();
    MM *pMM = new MM("Baby",28);
    pMM->print();
    //定义一个对象并且初始化的过程也是调用构造函数的过程
    MM mm = {"小baby",18};  //也是调用构造函数的过程
    mm.print();
    cout << "函数传参的时候" << endl;
    print(mm);
    //初始化参数列表
    cout << "初始化参数列表" << endl;
    Boy boy("可可",18,1001);
    boy.print();
    //this指针的测试
    Girl *pG = new Girl("Girl",18);
    pG->print();
    pG->getObject()->getObject()->getObject()->print();     //无实际作用

    return 0;
}