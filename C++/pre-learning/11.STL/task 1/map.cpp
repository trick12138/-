#include <iostream>
#include <map>
#include <string>

using namespace std;
/*
    No.1 map的基本操作
        1.1 存储的基本类型 pair<int,string>
        1.2 基本操作
        1.3 自带排序 (按照键去做排序) + 键唯一性(相同键最后一次插入数据,采用覆盖的方式)
*/
class MM
{
public:
    MM(){}
    MM(string name,int age) :name(name) ,age(age){}
    friend ostream& operator<<(ostream& out,const MM& object)
    {
        out << object.name << "\t" << object.age;
        return out;
    }
    bool operator<(const MM& object) const
    {
        return this->age < object.age;
    }
protected:
    string name;
    int age;
};


int main()
{
    pair<int,string> data;
    data.first = 1;         //键
    data.second = "string"; //值
    //map基本操作
    map<int,string> mapData;
    //采用下标法插入数据
    mapData[0] = "I Love You";
    mapData[-1] = "I Miss You";
    mapData[-1] = "xxoo";
    //采用成员函数的方式插入数据
    mapData.insert(pair<int,string>(1,"I want to swin"));
    //间接通过构建pair类型的函数去实现
    mapData.insert(make_pair<int,string>(2,"IlikeYou!!!"));
    map<int,string>::iterator iter;
    for (iter = mapData.begin(); iter != mapData.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }
    //No.2 操作自定义类型
    map<MM,MM> mm;
    mm[MM("张三",18)] = MM("小芳",20);
    mm[MM("李四",20)] = MM("小美",24);
    map<MM,MM>::iterator mmIter;
    for (mmIter = mm.begin(); mmIter != mm.end(); mmIter++)
    {
        cout << mmIter->first << "\t对象是:  " << mmIter->second << endl;;
    }
    //No.3 多重映射 mutilmap
    multimap<int,string> mulData;
    //不能直接用下标法，只有排序功能
    mulData.insert(pair<int,string>(1,"Iwantto...."));
    mapData.insert(make_pair<int,string>(2,"IlikeYou!!!"));
    mulData.insert(pair<int,string>(1,"Iwantto...."));
    mapData.insert(make_pair<int,string>(2,"IlikeYou!!!"));
    for (auto v : mulData)
    {
        cout << v.first << "\t" << v.second << endl;
    }
    cout << mulData.size() << endl;
    cout << mulData.empty() << endl;
    return 0;
}