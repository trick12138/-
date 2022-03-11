#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Stu
{
public:
    Stu(){}
    Stu(char* name,int age,bool gender,int grade) :age(age) ,gender(gender) ,grade(grade)
    {
        len = strlen(name);
        this->name = new char[len + 1];
        memset(this->name, 0,len + 1);
        strcpy(this->name,name);
    }
    Stu(const Stu& object)
    {
        len = object.len;
        name = new char[len + 1];
        memset(name,0,len + 1);
        strcpy(name,object.name);
        age = object.age;
        gender = object.gender;
        grade = object.grade;
    }
/*     void operator=(Stu object)
    {
        len = object.len;
        name = new char[len + 1];
        memset(name,0,len + 1);
        strcpy(name,object.name);
        this->age = object.age;
        this->grade = object.grade;
        this->grade = object.grade;
    } */
    friend ostream& operator<<(ostream& out,Stu object)
    {
        out << object.name << ":" << object.age << "\t" << object.gender << "\t" << object.grade;
        return out;
    }
    ~Stu()
    {
        delete[] name;
    }
private:
    char *name;
    int age;
    bool gender;
    int grade;
    int len;
};

int main()
{
    Stu MM;
    Stu Boy(Stu((char *)"张三",18,1,99));
    MM = Boy;
    cout << MM << endl;
    return 0;
}