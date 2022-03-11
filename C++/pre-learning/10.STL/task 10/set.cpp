#include <iostream>
#include <set>
#include <ctime>
#include <string>

using namespace std;
/*
    No.1 set的基本操作
    set: 集合
        1.1 不允许出现重复的元素,如果插入同样的元素,那么只会保留一份
        1.2 插入数据后,数据会排好序,一般默认的情况下从小到大

*/

class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    bool operator>(const MM& object) const
    {
        return this->age > object.age;
    }
protected:
    string name;
    int age;
};

int main()
{
    srand((unsigned)time(NULL));
    //set<int> data;                //从小到大
    //set<int,less<int>> data;      //同上
    set<int,greater<int>> data;     //从大到小
    for (int i = 0; i < 10; i++)
    {
        data.insert(rand() % 100);
    }
    for (auto v : data)
    {
        cout << v << "\t";
    }
    cout << endl << "size:" << data.size() << endl;
    //No.2 处理自定义类型
    set<MM,greater<MM>> mm;
    mm.insert(MM("小可爱",18));
    mm.insert(MM("小宝贝",28));
    mm.insert(MM("小甜心",23));
    for (auto v : mm)
    {
        cout << v.getName() << "\t" << v.getAge() << endl;
    }
    //No.3 多重集合 ：允许出现重复的元素
    multiset<int> mulData;
    mulData.insert(1);
    mulData.insert(2);
    mulData.insert(3);
    mulData.insert(4);
    mulData.insert(1);
    multiset<int>::iterator mulIter;
    for (mulIter = mulData.begin();mulIter != mulData.end();mulIter++)
    {
        cout << *mulIter << endl;
    }
    
    return 0;
}