#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;
/*
//基本查找
    find: 区间查找
    find_if: 条件查找
    find_first_if: 查找区间第一次出现值
    adjacent_find: 查找第一次重复的数
    search: 子序列的查找
    search_n: 子序列查找出现次数
//统计查找
    count: 区间统计
    count_if: 条件统计个数
    equal: 比较
//有序查找
    binary_search: 二分查找
    upper_bound: 查找最后一个大于等于val的值
    lower_bound: 查找
    equal_range: 区间比较---有序序列
*/

int main()
{
    int array[10] = {1,3,5,7,9,0,2,4,6,8};
    vector<int> data;
    data.assign(array,array + 10);
    //1.查找
    auto findIter = find(data.begin(),data.end(),3);
    if (findIter == data.end())
    {
        cout << "未找到相关数据" << endl;
    }
    cout << *findIter << endl;
    //2.条件查找
    auto find_if_iter = find_if(data.begin(),data.end(),[](int i){return i > 8;});
    cout << *find_if_iter << endl;
    //3.第一次找到我们要的值(范围中的任何一个元素)
    int temp[] = {15,0,6};
    cout << *find_first_of(data.begin(),data.end(),temp,temp + 3) << endl;
    int value[] = {1,1,2,2,2,5,5,6,6};
    //4.查找重复的元素
    auto valueIter = adjacent_find(value ,value + 10);
    cout << *valueIter << endl;
    //5.找字串
    int num[] = {1,2,2};
    auto it = search(value,value + 10,num , num + 3);
    cout << *it << endl;
    //6.search_n 找指定出现次数的元素(重复出现，连续的)
    it = search_n(value ,value + 10,4,2);
    cout << *it << endl;
    //查找首次出现连续4元素大于4的位置
    it = search_n(value,value + 10,4,4,[](int i,int j) {return i < j;});
    cout << *it << endl;
    //7.统计次数
    cout << count(value,value + 10,2) << endl;
    //8.条件查找
    cout << count_if(value,value + 10, [](int i,int j = 6) {return i < j;}) << endl;
    //9.比较
    cout << boolalpha << equal(array,array + 10,data.begin(),data.end()) << endl;
    sort(array,array + 10);         //默认从小到大
    for (int i = 0; i < 10; i++)
    {
        cout << "i:" << i << "(" << &array[i] << ")" << "\t";
    }
    auto sortIter = binary_search(array,array + 10,5);
    //10. 返回的是一个bool类型
    cout << boolalpha << sortIter << "\t";
    //11.大于
    cout << "i:" << *upper_bound(array,array + 10,8) << "(" << upper_bound(array,array + 10,8) << ")" << endl;
    //12.大于等于
    cout << "i:" << *lower_bound(array,array + 10,8) << "(" << lower_bound(array,array + 10,8) << ")" << endl;
    //13.equal_range 可以说是上面两个函数的综合体 second是第一次大于查找元素的位置
    cout << "first:" << *equal_range(array,array + 10,8).second << "(" << equal_range(array,array + 10,8).second << ")" << endl;
    //first 存储的是第一次等于查找元素的位置
    cout << "first:" << *equal_range(array,array + 10,8).first << "(" << equal_range(array,array + 10,8).first << ")" << endl;
    return 0;
}