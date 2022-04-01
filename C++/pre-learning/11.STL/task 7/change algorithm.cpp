#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <iterator>
//总共是有十五个

using namespace  std;

//打印辅助函数
template <class _Ty>
void print(string info,_Ty data)
{
    cout << info << endl;
    for (auto v : data)
    {
        cout << v << ' ';
    }
    cout << endl;
}

int main()
{
    //1.拷贝算法：从前往后复制元素
    array<int, 10> arrayData = {1,3,5,7,9,0,2,4,6,8};
    vector<int> vecData(arrayData.size());          //一定要确定长度，否则存在迭代器非法访问
    copy(arrayData.begin(),arrayData.end(),vecData.begin());
    print("正向拷贝:",vecData);
    //2.逆向拷贝，从最后一个元素开始赋值
    vector<int> rvecData(arrayData.size());
    copy_backward(arrayData.begin(),arrayData.end(),rvecData.end());
    print("逆向拷贝:",rvecData);
    //3.删除算法 此类算法并不会影响容器中元素个数 remove 类似数组的伪删除
    //如果删除元素不存在，返回一个容器的结束的位置  xx.end()
    vector<int>::iterator rs = remove(rvecData.begin(),rvecData.end(),100);
    if (rs == rvecData.end())
    {
        cout << "删除失败,没有找到" << endl;
    }
    rs = remove(rvecData.begin(),rvecData.end(),1);
    print("删除操作",rvecData);
    //4.把删除后的结果保存到新的容器中去  remove_copy
    vector<int> result(vecData.size() - 1);
    remove_copy(vecData.begin(),vecData.end(),result.begin(),1);
    print("原容器:",vecData);
    print("新容器",result);
    //5.条件删除操作  remove_if  
    array<int,10> testArray = {1,3,5,7,9,0,2,4,6,8};
    vector<int> testVector;
    testVector.assign(testArray.begin(),testArray.end());
    array<int,10>::iterator removeIter = \
    remove_if(testArray.begin(),testArray.end(),[](int data){return data & 1 == 1;});
    print("条件删除", testArray);
    //6.条件删除，删除后的序列结果存到另一个容器中 remove_copy_if
    int num = count_if(testVector.begin(),testVector.end(),[](int data,int data2 = 1){return data & data2 == 1;});
    vector<int> riResult(num);
    remove_copy_if(testVector.begin(),testVector.end(),riResult.begin(),[](int data){return data & 1 == 1;});
    print("原容器:",testVector);
    print("新容器",riResult);
    //7.替换算法(修改) replace 区间中所有的元素替换为0
    vector<int> rData;
    rData.assign(testArray.begin(),testArray.end());
    print("原数据:",testArray);
    replace(rData.begin(),rData.end(),2,3);
    print("替换后的数据:",rData);
    //8.替换后的结果保存到新的容器中去 replace_copy
    vector<int> rcData(rData.size());
    replace_copy(rData.begin(),rData.end(),rcData.begin(),3,2);
    print("原数据",rData);
    print("替换结果储存到新容器中",rcData);
    //9.条件替换 修改原来的容器 replace_if
    int testData[] = {1,2,3,4,5,6,7,8,9,0};
    vector<int> riData;
    riData.assign(testData,testData + 10);
    print("原数据:",riData);
    replace_if(riData.begin() ,riData.end() ,[](int data){return data <= 5;} ,0);
    print("新数据",riData);
    //10.条件替换，结果存到新容器中
    vector<int> ricData(riData.size());
    replace_copy_if(riData.begin(),riData.end(),ricData.begin(),[](int data){return data <= 5;},6);
    print("新容器",ricData);
    //11.交换函数  通过迭代器进行交换  iter_swap
    list<int> sData;
    int sArray[] = {1,2,3,4,5,6,7,8,9,0};
    sData.assign(sArray,sArray + 10);
    print("list:",sData);
    list<int>::iterator move = sData.end();
    advance(move,-1);
    iter_swap(sData.begin(),move);
    print("list:",sData);
    //12.交换容器中的元素 swap 可以忽略长度交换两个相同容器的值
    vector<int> firstData;
    firstData.assign(sArray, sArray + 5);
    vector<int> secondData;
    secondData.assign(sArray + 5, sArray + 10);
    print("firstData:", firstData);
    print("secondData:",secondData);
    swap(firstData,secondData);
    print("firstData:", firstData);
    print("secondData:",secondData);
    //13.区间交换 swap_ranges
    swap_ranges(firstData.begin(),firstData.begin() + 3,secondData.begin());
    print("firstData:", firstData);
    print("secondData:",secondData);
    //14.去重操作  不影响原容器数目 uniqueue
    int reArray[] = {1,2,2,3,3,3,3,4,4,4};
    vector<int> reData;
    reData.assign(reArray, reArray + 10);
    print("去重前:", reData);
    vector<int>::iterator uniqueIter = \
    unique(reData.begin(),reData.end());        //默认情况去掉重复的，重载，条件可以自己描述
    print("去重后:", reData);
    //15.去重，每个只保留一份序列保存到新的容器 unique_copy
    vector<int> unData;
    unData.assign(reArray, reArray + 10);
    vector<int> uniqueData(4);
    unique_copy(unData.begin(), unData.end(), uniqueData.begin());
    print("原序列:", unData);
    print("新序列",uniqueData);

    return 0;
}