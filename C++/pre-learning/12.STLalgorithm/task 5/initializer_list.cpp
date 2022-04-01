#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>

using namespace std;

template<class _Ty>
class myVector
{
public:
    myVector(int size) :curSize(size)
    {
        dataMemory = new _Ty[curSize];
    }
    //以列表数据为参的构造函数
    myVector(initializer_list<_Ty> data) :myVector(data.size())
    {
        for(auto v : data)
        {
            dataMemory[curSize++] = v;
        }
    }
    void print()
    {
        for (int i = 0; i < curSize; i++)
        {
            cout << dataMemory[i] << endl;
        }
        
    }
    myVector()
    {
        curSize = 0;
    }
private:
    _Ty* dataMemory;
    int curSize;
};

//可边长参数函数
template <class _Ty>
_Ty sum(initializer_list<_Ty> data)
{
    int num = 0;
    accumulate(data.begin(),data.end(),num);
    return num;
}

int main()
{
    vector<int> data = {1,2,3,4,5,6,7,8,9};
    initializer_list<int> listData = {1,2,3,4,5,6};     //列表数据
    vector<int> data2 = listData;
    for (auto v : listData)
    {
        cout << v << " ";
    }
    cout << endl;
    for_each(listData.begin(),listData.end(),[](int data){cout << data << " ";});
    cout << endl;
    cout << sum({1,2,5,56,1}) << endl;
    myVector<int> data3 = {1,2,3,4,5,6,7,8,9};
    return 0;
}