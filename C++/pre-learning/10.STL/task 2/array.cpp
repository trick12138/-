#include <iostream>
#include <string>

using namespace std;

struct Info
{
    string name;
    int age;
    int num;
};
class DATA
{
public:
    
protected:
    int age;
    int num;
};

ostream& operator<<(ostream& out,Info data)
{
    out << data.name << "\t" << data.age << "\t" << data.num;
    return out;
}

bool operator>(Info data1,Info data2)
{
    return data1.name > data2.name;
}

template <typename dataType>
dataType Max(dataType a,dataType b)
{
    return a > b ? a : b;
}

template <class dataType>
void print(dataType data)
{
    //基本运算符无法处理自定义类型，所以需要重载
    cout << data << endl;
}

//模板多个类型
template <class dataType1,class dataType2,class dataType3>
void print(dataType1 data,dataType2 data2,dataType3 data3)
{
    cout << data << "\t" << data2 << "\t" << data3 << endl;
}

template <>
void print(int a)
{
    cout << "Hello world" << endl;
}

int main()
{
    //以自定义类型为数据类型的时候
    struct Info objectA = {"Name1",10,1001};
    struct Info objectB = {"Name2",20,1002};
    //大多数原因都是因为没有进行运算符重载
    print(objectA);
    print(objectB);
    cout << Max(objectA,objectB) << endl;
    print(1,1.2f,objectA);
    print(1,2,3);
    system("pause");
    return 0;
}