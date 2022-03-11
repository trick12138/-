#include <iostream>
#include <string>

using namespace std;

class student
{
public:
    student(string name,int age,int grade) :name(name),age(age),grade(grade){}
    void print()
    {
        cout << name << ' ' << age << ' ' << grade << endl;
    }
private:
    string name;
    int age;
    int grade;    
};

int main()
{
    student lihua(string("lihua"),28,99);
    student lili(string("lili"),5,98);
    student hehe(string("hehe"),10,98);
    lihua.print();
    lili.print();
    hehe.print();
    student *p = nullptr;
    p = &lihua;
    p->print();
    return 0;
}