#include <iostream>
#include <exception>
using namespace std;
/*
    自定义异常类
    No.1 继承异常类, 自己去写构造函数, 以及拷贝构造函数
    No.2 重写what方法, 或者重新初始化__Data.What数据成员



*/

class Out_Range :public exception
{
public:
    explicit Out_Range(const string* message) :exception(message.c_str)
    {

    }
    explicit Out_Range(const char* message) :exception(message)
    {

    }
/*     explicit Out_Range(Out_Range& object)
    {
        *this = object;
    } */
protected:

};

void printArray(int array[],int len)
{
    int i = -1;
    if (i < 0 || i >= len)
    {
        throw Out_Range("数组下标溢出!");
    }
    cout << array[i] << endl;
}
class Error :public exception
{
public:
    const char *what() const
    {
        return "myError";
    }
protected:

};

void printValue()
{
    throw Error();
}

int main()
{
    int array[3] = {1,2,3};
    try
    {
        printArray(array,3);
    }
    catch(Out_Range object)
    {
        std::cerr << object.what() << '\n';
    }
    try
    {
        printValue();
    }
    catch(Error object)
    {
        std::cerr << object.what() << '\n';
    }
    
    

    return 0;
}
/*
    No.4 异常处理的建议
    1.局部控制能够处理的就不需要异常
    2.构造函数中存在问题可以通过抛出异常来检测
    3.避免在析构函数中抛出异常
    4.不是所有类都是继承exception类,也可以继承其他异常子类
*/