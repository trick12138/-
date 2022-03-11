#include <iostream>
#include <iostream>
#include <sstream>      //No.1 字符流的头文件
using namespace std;
/*
    No.2 字符流对象的介绍
    sstream: istringstream ostringstrem stringstream 都存在一个宽字符集的版本
    一般在处理字符流的时候使用stringstream类的对象即可, 处理字符要频繁涉及到输入和输出
    No.3 获取stringstream对象中的string
    string str();                   //获取string
    void str(const string str)      //重置stringstream中的数据
*/
int main()
{
    stringstream object(string("I love you"));
    cout << object.str() << endl;
    object.str(string("I miss you"));
    cout << object.str() << endl;
    object.str("");     //清除操作
    cout << object.str() << endl;
    //No.4  字符流  更多用来做数据的类型或者数据的切割
    //4.1 数据的类型转换 整数转换为字符串
    int num = 256;
    char str[20] = "";
    stringstream stream(str);
    stream << num;
    stream >> str;      //通过字符流的操作实现转换 将数据类型进行转换
    cout << str << endl;
    //4.2 做数据切割
    stringstream ip("ip地址: 192.168.1.1");
    char strIp[20] = "";
    int ipNum[4];
    ip >> strIp;
    for (int i = 0; i < 4; i++)
    {
        char userKey;
        ip >> ipNum[i];
        if(i != 3)
            ip >> userKey;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << ipNum[i] << " ";
    }
    cout << endl;
    //No.5 注意点: 使用同一个流对象进行多次转换的时候, 必须要调用clear函数进行清除处理
    stream.clear();
    stream << num;
    stream >> str;      //通过字符流的操作实现转换 将数据类型进行转换
    cout << str << endl;
    return 0;
}