#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iomanip>

using namespace std;
/*
    next_permutation:   下一个排序序列的组合
    prev_permutation:   上一个排序序列的组合
    序列: {a,b,c}       前提条件: a < b < c;
    a c b上一个序列就是a b c
*/
int main()
{
    array<int, 3> data = {1,2,3};
    next_permutation(data.begin(), data.end());
    for (auto v : data)
    {
        cout << v;
    }
    cout << endl;
    prev_permutation(data.begin(), data.end());
    for (auto v : data)
    {
        cout << v;
    }
    cout << endl;
    //很多算法题： 给定一些数组，问能组合多少个数 （数字不能重复）
    int arrayData[] = {1,2,3,4};
    vector<int> vecData;
    vecData.assign(arrayData, arrayData + 4);
    cout << "排列组合问题" << endl;
    int i = 0;
    do
    {
        cout << "第 " << setw(2) << ++i << "种序列:";
        for (auto v : vecData)
        {
            cout << v;
        }
        cout << endl;
    } while (next_permutation(vecData.begin(),vecData.end()));      //组合和结果是： 升序的方式
    vector<int> testData;
    testData.assign(vecData.begin(), vecData.end());
    i = 0;
    do
    {
        cout << "第 " << setw(2) << ++i << "种序列:";
        for (auto v : vecData)
        {
            cout << v;
        }
        cout << endl;
    } while (prev_permutation(testData.begin(), testData.end()));   //降序的方式
    cout << "降序正确案例" << endl;
    reverse(testData.begin(),testData.end());
    for (auto v : testData)
    {
        cout << v;
    }
    cout << endl;
    return 0;
}