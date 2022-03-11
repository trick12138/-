#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Person
{
public:
    //名字 性别 0 男 1 女 年龄 是否结婚 0 未婚 1 已婚
    Person(string name,bool gender,int age,bool isMarriage) :name(name),gender(gender),age(age),isMarriage(isMarriage){}
    ~Person(){}
    //获取信息
    string& getName()
    {
        return name;
    }
    bool& getGander()
    {
        return gender;
    }
    int& getAge()
    {
        return age;
    }
    bool& getIsMarriage()
    {
        return isMarriage;
    }
    Person *object;
    void Marry(Person* Person2)
    {
        if(this->getGander() == Person2->getGander())
        {
            cout << "同性不能结婚" << endl;
            return;
        }
        if (this->getIsMarriage() == 1)
        {
            cout << "已婚人士不能结婚" << endl;
            return;
        }
        if (this->getGander() == 1 && this->getAge() < 20)
        {
            cout << "女方年龄过小" << endl;
            return;
        }
        if (this->getGander() == 0 && this->getAge() < 22)
        {
            cout << "男方年龄过小" << endl;
            return;
        }
        if (Person2->getIsMarriage() == 1)
        {
            cout << "已婚人士不能结婚" << endl;
            return;
        }
        if (Person2->getGander() == 1 && Person2->getAge() < 20)
        {
            cout << "女方年龄过小" << endl;
            return;
        }
        if (Person2->getGander() == 0 && Person2->getAge() < 22)
        {
            cout << "男方年龄过小" << endl;
            return;
        }
        this->object = Person2;
        Person2->object = this;
        this->getIsMarriage() = 1;
        Person2->getIsMarriage() = 1;
        cout << "结婚成功" << endl;
    }
private:
    string name;
    bool gender;
    int age;
    bool isMarriage;
};

void Marry(Person& Person1,Person& Person2)
{
    if(Person1.getGander() == Person2.getGander())
    {
        cout << "同性不能结婚" << endl;
        return;
    }
    Person *person = nullptr;
    for (int i = 0; i < 2; i++)
    {
        if (person == nullptr)
            person = &Person1;
        else
            person = &Person2;
        if (person->getIsMarriage() == 1)
        {
            cout << "已婚人士不能结婚" << endl;
            return;
        }
        if (person->getGander() == 1 && person->getAge() < 20)
        {
            cout << "女方年龄过小" << endl;
            return;
        }
        if (person->getGander() == 0 && person->getAge() < 22)
        {
            cout << "男方年龄过小" << endl;
            return;
        }
    }
    Person1.object = &Person2;
    Person2.object = &Person1;
    Person1.getIsMarriage() = 1;
    Person2.getIsMarriage() = 1;
    cout << "结婚成功" << endl;
}

int main()
{
    Person MM("小青",1,20,0);
    Person GG("小明",0,22,0);
    Marry(MM,GG);
    system("pause");
    return 0;
}