#include <iostream>
#include <string.h>
using namespace std;
//1.C++定义结构体
//C++结构体允许函数存在
struct MM
{
    //数据成员
    char name[20];
    int age;
    //成员函数
    void print()
    {
        cout << name << ":" << age << endl;
    }
    void printInfo();
};

//结构体外实现成员函数
void MM::printInfo()
{
    cout << name << ":" << age << endl;
}

int main()
{
    //2.如何访问结构体中的成员
    //结构体中的成员只能通过结构体变量（结构体指针）去访问
    //C++创建变量时不再需要struct关键字
    MM mm = {"小可爱",18};
    cout << mm.name << mm.age << endl;
    mm.print();     //普通变量用的是变量.成员
    MM *pMM = &mm;
    pMM->print();   //指针：用的是指针指向运算符->
    //如何new一个对象
    int *pInt = new int;
    MM *pObject = new MM;
    strcpy(pObject->name,"小仙女");
    pObject->age = 19;
    pObject->print();
    //new一个结构体数组
    MM *pArray = new MM[4];
    for (int i = 0; i < 4; i++)
    {
        strcpy(pArray[i].name,"MM");
        pArray[i].age = i * 2;
    }
    for (int i = 0; i < 4; i++)
        pArray[i].print();
    delete pObject;
    pObject = nullptr;
    delete[] pArray;
    return 0;
}