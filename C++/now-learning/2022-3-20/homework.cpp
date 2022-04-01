#include <iostream>
#include <string>

using namespace std;

class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    MM operator-(MM& object)
    {
        return MM(this->name + object.name,this->age - object.age);
    }
    friend class Boy;
    virtual void print()
    {
        cout << "hello world" << endl;
    }
private:
    string name;
    int age;
};

class Boy :public MM
{
public:
    Boy(string mmName,int mmAge,string bName,int bAge) :MM(mmName,mmAge) ,bName(bName) ,bAge(bAge){}
    void print(MM& object)
    {
        cout << object.name << ":" << object.age << endl;
    }
private:
    string bName;
    int bAge;
};



int main()
{
    MM mm("MM",18);
    Boy boy("MM2",20,"Boy",19);
    mm.print();
    boy.print(mm);
    return 0;
}