#include <iostream>
#include <cstring>

using namespace std;

/*
    No.1 类和对象的基本概念
        1.1 什么是类
            类: 类别,具体一点就是具有相同属性和行为的事物的抽象
            女朋友类:
                    姓名 年龄 三围 性别 --> 属性    事物的特征 通常用数据类型描述
                            购物 睡觉  --> 能够做什么 通常用函数描述
            类 = 属性 + 行
        1.2 对象: 就是类的具体化
        抽象 封装 继承 多态
    No.2 如何创建一个类
        class 类名
        {
            //1.权限限定词
            //2.数据成员
            //3.成员函数
        };
    No.3 如何创建一个对象
        类名 对象名
    No.4 如何new一个对象
    No.5 如何访问数据-->权限限定词
        1.类外只能访问public属性
        2.默认属性是private
*/

class GirlFriend
{
    int num;
public:     //公有
    int age;
    char name[20];
    void initData(const char *gName, int gAge, int gNum);
    int& getAge()
    {
        return age;
    }
    int& getNum()
    {
        return num;
    }
    char *getName()
    {
        return name;
    }
    void print()
    {
        cout << name << ":" << age << ":" << num << endl;
    }
protected:  //保护

private:    //私有

};

void GirlFriend::initData(const char *gName, int gAge, int gNum)
{
    strcpy(name,gName);
    age = gAge;
    num = gNum;
}

int main()
{
    GirlFriend object;  //创建一个普通的对象
    object.initData("小芳",18,1001);
    object.print();

    GirlFriend *pObject = new GirlFriend;
    pObject->initData("小丽",19,1002);
    pObject->print();
    strcpy(pObject->getName(),"小仙女");
    pObject->getAge() = 1000;
    pObject->getNum() = 999;
    pObject->print();
    
    delete pObject;
    pObject = nullptr;
    return 0;
}