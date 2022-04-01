#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    //1.求和算法 accumulate
    vector<int> vecData = {1,2,3,4,5,6,7,8,9,0};
    int sum = 0;
    sum = accumulate(vecData.begin(), vecData.end(), sum);
    cout << "sum:" << sum << endl;
    //2.逐步求和 partial_sum
    vector<int> result(10);
    partial_sum(vecData.begin(), vecData.end(), result.begin());
    for (auto v : result)
    {
        cout << v << "\t";
    }
    cout << endl;
    partial_sum(vecData.begin(), vecData.end(), ostream_iterator<int> (cout, "\t"));
    //3.求积运算：矩阵的乘法
    vector<int> first(5);
    vector<int> second(5);
    //递增填充
    for (int i = 0; i < 5; i++)
    {
        first[i] = 1;
        second[i] = 2;
    }
    //1 1 1 1 1   2 2 2 2 2
    cout << endl;
    cout << inner_product(first.begin(), first.end(), second.begin(), 0) << endl;
    //4.求差运算, 相邻元素差  adjcent_difference
    vector<int> testData = {1,2,3,4,5,6,7,8,9,0};
    adjacent_difference(testData.begin(), testData.end(), ostream_iterator<int>(cout, "\t"));
    return 0;
}