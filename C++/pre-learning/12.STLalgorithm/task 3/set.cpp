#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> one = {1,2,3,4,5,6};
    vector<int> two = {4,5,7,8,9};
    //1.并集, set_union ,两个数据必须有序
    vector<int> result(one.size() + two.size());
    set_union(one.begin(), one.end(), two.begin(), two.end() ,result.begin());
    for_each(result.begin(), result.end(), [](int data) {cout << data << " "; });
    cout << endl;
    set_union(one.begin(), one.end(), two.begin(), two.end() ,ostream_iterator<int>(cout ,"\t"));
    cout << endl;
    //2.求交集 set_intersection
    set_intersection(one.begin(), one.end(), two.begin(), two.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //3. 求差集 set_difference
    set_difference(one.begin(), one.end(), two.begin(), two.end(), ostream_iterator<int>(cout,"\t"));
    cout << endl;
    //4.对称差集（并集减去交集）set_symmetric_difference
    set_symmetric_difference(one.begin(), one.end(), two.begin(), two.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}