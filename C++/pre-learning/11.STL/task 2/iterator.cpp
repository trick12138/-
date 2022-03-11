#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <ostream>
#include <streambuf>
#include <iterator>

using namespace std;
/*
    介于容器和算法之间的一个桥梁
    可以说是访问容器的一个桥梁,类中类的一个对象,去模仿指针的行为
    No.1 迭代器的分类
    1.1 按照定义方式:
        1.1.1 正向迭代器
            容器类名::iterator 迭代器名;
            begin();
            end();
        1.1.2 常量正向的迭代器
            容器类名::const_iterator 迭代器名;
            cbegin();
            cend();
        1.1.3 反向迭代器
            容器类名::reverse_iterator 迭代器名;
            rbegin();
            rend();
        1.1.4 常量的反向迭代器
            容器类名::const_reverse_iterator 迭代器名;
            crbegin();
            crend();
    1.2 按功能分类
        1.2.1 正向迭代器
        1.2.2 双向迭代器
        1.2.3 随机访问迭代器
    No.2 内置迭代器
        容器                迭代器
        vector              随机访问
        array               随机访问
        deque               随机访问
        list                双向
        set/multiset        双向
        map/multimap        双向
        stack               不支持迭代器
        queue               不支持迭代器
        priority_queue      不支持迭代器
    No.3 迭代器的辅助函数
        3.1 advance(p,n);   移动迭代器p,移动到p+n的位置
        3.2 distrance(iterator begin,iterator end);     测量begin和end之间差了几个++,若end在begin的前面,将会导致死循环
        3.3 iter_swap(iterator first,iterator second);  交换first与second指向的值
    No.4 流迭代器
        4.1 输出流型迭代器
        ostream_iterator<type>(ostream object);
        ostream_iterator<type>(ostream object,char *str);
        ostreamobject = value; 实际含义是把数据打到屏幕上
        4.2 输入流型迭代器
            istream_iterator<type> object;              //错误流, End_of_stream;
            istream_iterator<type> (istream object);
            *istreamObject                              //等效于输入操作 cin

    copy算法
    copy(begin, end(), newbegin
*/

int main()
{
    vector<int> myvec(3);
    for (int i = 0; i < 3; i++)
    {
        myvec[i] = i;
    }
    for (auto v : myvec)
    {
        cout << v << "\t";
    }
    cout << endl;
    //什么容器使用的随机
    //随机型是可以采用<方式去实现
    vector<int>::iterator iter;
    for (iter = myvec.begin(); iter < myvec.end(); iter++)
    {
        cout << *iter << "\t";
    }
    cout << endl;
    vector<int>::reverse_iterator rIter;
    vector<int>::const_iterator cIter;
    vector<int>::const_reverse_iterator crIter;
    list<int> myList;
    for (int i = 0; i < 3; i++)
    {
        myList.push_back(i);
    }
    list<int>::iterator listIter;
    //注意点： 双向迭代器没有重载<
    for (listIter = myList.begin(); listIter != myList.end(); listIter++)
    {
        cout << *listIter << "\t";
    }
    cout << endl;
    //辅助函数
    iter = myvec.begin();
    advance(iter,2);
    cout << *iter << endl;
    cout << "size:" << myvec.size() << endl;
    cout << "size:" << distance(myvec.begin(),myvec.end()) << endl;
    iter_swap(myvec.begin(),myvec.end() - 1);
    for (auto v : myvec)
    {
        cout << v << "\t";
    }
    cout << endl;
    //输出流型迭代器
    ostream_iterator<int> object(cout,"1234");
    object = 1234;
    cout << endl;
    string str = "|";
    copy(myvec.begin(),myvec.end(),ostream_iterator<int>(cout,","));
    cout << endl;
    //输入流型迭代器
    vector<int> inputData;
    istream_iterator<int> endOfStream;
    istream_iterator<int> inputIter(cin);
    while(inputIter != endOfStream)
    {
        inputData.push_back(*inputIter);
        ++inputIter;
    }
    cout << "inputData:" << endl;
    for (auto v : inputData)
    {
        cout << v << "\t";
    }
    cout << endl;
    return 0;
}