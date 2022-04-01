#include <iostream>

using namespace std;
/*
    const_cast<要转换的类型>(expression)
    1.去掉const属性 (提供一个可以修改的接口去操作const类型的变量)
    2.加上const属性 (相对来讲用的比较少)

*/
class A
{
public:
    int m_num;
    A(){m_num = 0;}
};

int main()
{

    return 0;
}