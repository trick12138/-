#include <iostream>
#include <functional>
#include <algorithm>
#include <functional>

using namespace std;
/*
    No.1 什么是仿函数
    仿函数: 让类的对象模仿函数调用的行为
    仿函数的实质: 重载运算符()  对象()
    No.2 自己写仿函数
        关键点在于重载()
    No.3 库中的仿函数
        算术类仿函数
*/
class Sum
{
public:
    int operator()(const int a,const int b)const
    {
        return a + b;
    }
protected:

};

void printArray(int array[],int arrayNum)
{
    for (int i = 0; i < arrayNum; i++)
    {
        cout << array[i] << "\t";
    }
}

int main()
{
    Sum object;
    cout << Sum()(1,2) << endl;             //采用的是无名（匿名对象）调用重载函数
    cout << object.operator()(1,2) << endl; //显示调用重载函数
    cout << object(1,2) << endl;            //对象与运算符重载的方式调用
    //算数类
    cout << plus<int>()(1,2) << endl;       //求和
    cout << minus<int>()(2,1) << endl;      //减法
    cout << multiplies<int>()(2,3) << endl; //除法
    cout << divides<int>()(2,1) << endl;    //取余
    cout << modulus<int>()(3,6) << endl;    //取模
    cout << negate<int>()(1) << endl;       //取负数
    //关系类的运算仿函数
    //sort(begin(),end(),compare p)
    int array[10] = {1,2,3,4,5,6,0,9,8,7};
    sort(array,array + 10);     //默认的方式是从小到大
    printArray(array,10);       //greater<int>() 大于仿函数
    printArray(array, 10);
    sort(array,array + 10,less<int>()); //less<int>() 小于的仿函数
    /*
        greater_equal: >=
        less_equal: <=
        not_equa_to: !=
        equal_to: ==
    */
   //逻辑类的运算符的仿函数
   logical_and<int>();          //逻辑与
   cout << logical_and<int>()(1,2) << endl;
   cout << logical_or<int>()(0,0) << endl;
   //选择 证同 投射
   /*
        identity: 主要是用于RB或者hashmap处理键相同时的使用
        select1st:
        select2nd:
        project1st:
        project2st:
   */
    return 0;
}