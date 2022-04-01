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
private:
    string name;
    int age;
};

class Boy
{
public:
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
    Boy b;
    b.print(mm);

    return 0;
}