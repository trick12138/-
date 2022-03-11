#include <iostream>
#include <utility>
#include <string>

using namespace std;
/*
    NO.1 STL是什么
    STL: (惠普的)标准模板库(Standard Template Library) 将数据的存储和操作分开进行的一个封装
    No.2 STL组成部分
    STL广义上讲: 算法(algorithm) 容器(container) 迭代器(iterator)
    具体下: 
        容器: 封装的一些数据结构的模板类
        算法: 处理数据的一些常规操作(查找,排序,归并....)
        迭代器: 主要用来对容器中的数据进行读写
        函数对象: 仿函数,让类模仿函数的行为
        适配器: 主要是让类的接口去适应用户的指定的形式
        内存分配器: 内存的申请和释放
    No.3 STL头文件
        iterator: 迭代器
        functional: 仿函数
        //序列式容器
            vector: 向量 动态数组
            array: 固定数组
            deque: 循环队列
            list: 双向链表
            queue: 普通队列
            stack: 栈
        //关联式容器
            map: 映射
            set: 集合
            algorithm: 算法
            numeric: 数字处理类算法
            memory: 内存分配器
            utility: 关系比较符的重载以及pair类型的模板
*/
template <class Type1,class Type2>
struct my_pair
{
    Type1 first;
    Type2 second;
};


int main()
{
    pair<string,int> object;
    object.first = string("小芳");
    object.second = 18;
    cout << object.first << "\t" << object.second << endl;
    return 0;
}