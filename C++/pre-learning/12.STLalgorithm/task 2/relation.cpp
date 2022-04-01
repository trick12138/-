#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    //1.比较算法 equal
    vector<int> one = {1,2,3,4,5,6};
    vector<int> two = {1,2,3,5,5,6};
    cout << boolalpha << equal(one.begin(), one.end(), two.begin()) << endl;
    //2.判断容器是否是包含关系
    vector<int> thrid = {1,2,3};
    cout << includes(one.begin(),one.end(),thrid.begin(),thrid.end()) << endl;
    //3.比较序列 lexicograohical_compare
    //第一个学列的值小于第二个，返回true
    cout << lexicographical_compare(one.begin(), one.end(), two.begin(), two.end()) << endl;
    //4.max
    cout << max(1,2) << endl;
    cout << *max_element(one.begin(),one.end()) << endl;
    //5.min
    cout << min(1,2) << endl;
    cout << *min_element(one.begin(), one.end()) << endl;
    cout << *minmax_element(one.begin(), one.end()).first << endl;
    cout << *minmax_element(one.begin(), one.end()).second << endl;
    //6.查异算法：找两个序列中第一次不同的位置
    //minmatch
    cout << *mismatch(one.begin(), one.end(), two.begin()).first << endl;
    cout << *mismatch(one.begin(), one.end(), two.begin()).second << endl;
    return 0;
}