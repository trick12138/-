#include <iostream>
#include <string>
using namespace std;
/*
    No.1 异常处理机制
        �?题的检测和�?题的处理分开
        异常: 任何东西都可当作异常抛出
    No.2 异常的抛出和异常的捕获与处理
        2.1 throw抛出异常
        2.2 try与catch进�?�捕获和处理异常
            注意�?: 
                <1>.try和catch必须同时出现,try必须至少带有一个catch
                <2>.当抛出的异常不做处理会调用默认的abort函数终�?�程�?
        2.3 当函数不存在异常, throw()或者用noexcept;
            noexcept: 如果一定�?�抛出异�?, 则会直接引发�?�?
        2.4 捕获任何类型的异�?,删减�?.....
    No.3 异常处理的传参操�?
        catch�?其实�?以传入参�?, �?要i与抛出数�?类型一致的参数, 都可以进行传参操�?
    No.4 我们也可以抛出自定义类型的异�?
        充分的描述异常的信息
*/
class stackEnpty
{
public:
    stackEnpty(string strInfo) :strInfo(strInfo)
    {

    }
    void printException()
    {
        cout << strInfo << endl;
    }
protected:
    string strInfo;
};

class stack
{
public:
    stack() :stackTop(-1)
    {
        
    }
    void pop()
    {
        if(stackTop = -1)
            throw stackEnpty("栈为�?");
        cout << "出栈成功" << endl;
    }
protected:
    int stackTop;
};


int Max(int a,int b) throw()
{
    return a > b? a : b;
}

int Min(int a,int b) //noexcept
{
    if(a == 1)
        throw 1;
    return a > b? b : a;
}

int result(int a,int b)
{
    if(b == 0)
    {
        cout << "除数不能�?0" << endl;
        return -1;
    }
    return a / b;
}

int resultValue(int a, int b)
{
    if (b == 0)
        throw -1;
    return a / b;
}

void print(int a,int b)
{   
    try
    {
        cout << resultValue(a,b) <<endl;    //当前遇到异常的时候直接跳�?到catch的位�?不会运�?�下面的代码
        cout << "异常处理后面的�??�?....." << endl;
    }
    catch (int)      //根据抛出的异常类型去决定如何处理
    {
        cout << "除数不能�?0" << endl;
    }
    catch (double)
    {
        cout << "catch double" << endl;
    }
}
int resultValueString(int a,int b)
{
    if (b == 0)
    {
        throw string("除数不能�?0");
    }
    return a / b;
}

int main()
{
    //resultValue(5,0);
    print(1,0);
    print(2,1);
    //noexpect�?饰的函数异常不会处理
/*     try
    {
        Min(1,2);
    }
    catch(int)
    {
        std::cerr << "异常产生" << '\n';
    } */
    try
    {
        cout << resultValue(1, 0) <<endl;
    }
    catch(int value)    //隐藏一�?传参的操�?: int value = throw �?
    {
        cout << value << endl;
    }
    catch(...)
    {
        std::cerr << "任何异常类型都可以捕�?" << '\n';
    }
    try
    {
        cout << resultValueString(1,0) << endl;
    }
    catch(string object)
    {
        std::cerr << object << '\n';
    }
    stack myStack;
    try
    {
        myStack.pop();
    }
    catch(stackEnpty object)
    {
        object.printException();
    }
    
    
    return 0;
}