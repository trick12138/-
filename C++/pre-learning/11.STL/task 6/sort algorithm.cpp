#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>

using namespace std;
/*
    14个排序以及通用性算法




*/
//辅助函数
template <class _Ty>
void printData(_Ty object)
{
    for (auto v : object)
    {
        cout << v << "\t";
    }
    cout << endl;
}

template<class _Ty>
void printArray(_Ty array[], int arrayNum)
{
    for (int i = 0; i < arrayNum; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    
}

//1.sort算法
struct MM
{
    string name;
    int age;
    int num;
    bool operator<(MM object)
    {
        return this->name < object.name;
    }
};

bool compareByNum(MM& objectOne,MM& objectTwo)
{
    return objectOne.num < objectTwo.num;
}

ostream& operator<<(ostream& out,MM& mm)
{
    out << mm.name << "\t" << mm.age << "\t" << mm.num << endl;
    return out;
}

void testSort()
{
    //1.1 数组也适用有些算法
    int array[] = {1,3,5,7,9,0,2,4,6,8};
    vector<int> vecData(10);
    vecData.assign(array,array + 10);
    sort(array,array + 10);         //默认从小到大
    printData(vecData);
    //1.2 排序准则
    //默认方式等效一下写法
    sort(vecData.begin(),vecData.end(),less<int>());
    printData(vecData);
    sort(vecData.begin(),vecData.end(),greater<int>());
    //1.3 自定义类型数据的时候
    struct MM mm[3] = {"name3",19,1001,"name2",18,6666,"name6",15,5455};
    vector<MM> mmData;
    for (int i = 0; i < 3; i++)
    {
        mmData.push_back(mm[i]);
    }
    sort(mmData.begin(),mmData.end());
    printData(mmData);
    sort(mmData.begin(),mmData.end(),compareByNum);
    printData(mmData);
    //1.4 注意点：不支持随机型迭代器的容器不支持sort算法 stack queue list
    list<int> listData;
    listData.assign(array,array + 10);
    listData.sort();
}

//2.保持相对位置进行排序 stable_sort
bool compare_as_int(double a,double b)
{
    return (int(a) < int(b));
}

void testStable_sort()
{
    double num[] = {3.14,1.41,2.72,4.67,1.73,1.32,1.62,2.58};
    vector<double> dData;
    vector<double> ddData;
    dData.assign(num,num + 8);
    ddData.assign(num,num + 8);
    sort(dData.begin(),dData.end());
    printData(dData);
    stable_sort(ddData.begin(),ddData.end(),compare_as_int);
    printData(ddData);
}

int main()
{
    //testSort();
    //2.保持相对位置进行排序
    //testStable_sort();
    //3.归并排序 merge: 保持原容器顺序
    int array[] = {1,3,5,7,9,2,4,6,8,10};
    vector<int> num(10);
    merge(array,array + 5,array + 5,array + 10,num.begin());
    printData(num);
    //4.改变原容器数据的归并 inplace_merge
    inplace_merge(array,array + 5,array + 10);
    printArray(array,10);
    //5.关键字排序
    int elemnt[] = {1,3,5,7,9,2,4,6,8,10};
    nth_element(elemnt,elemnt + 2,elemnt + 10);
    printArray(elemnt,10);
    //6.分类处理
    //谓词 true元素放左边 false放右边
    int partition_data[] = {1,3,5,7,9,2,4,6,8,10};
    partition(partition_data,partition_data + 10,[](int data) {return data < 6;});
    printArray(partition_data,10);
    //7.保持原容器数据顺序 stable_partition
    double dNum[] = {3.14,1.41,2.72,4.67,1.73,1.32,1.62,2.58};
    stable_partition(dNum,dNum + 8,bind(compare_as_int,placeholders::_1,2.0));
    printArray(dNum,8);
    //8.局部排序partial_sort
    //前面n个元素是最小的有序的,后面元素无序的
    vector<int> numbers{22,7,93,45,19,56,88,12,8,7};
    partial_sort(numbers.begin(),numbers.begin() + 3,numbers.end());
    printData(numbers);
    return 0;
}