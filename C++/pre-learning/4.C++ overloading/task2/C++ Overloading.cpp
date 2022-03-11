#include <iostream>
#include <string>
using namespace std;
//自己做一个int类出来,把各种运算符重载一下
//自己尝试做一个string类型
class Int
{
public:
    Int(int num = 0) : m_Num(num){}
    //获取里面值,类似string中学过的c_str data函数
    int& data()
    {
        return m_Num;
    }
    int toInt()
    {
        return m_Num;
    }
    string tostring()
    {
        return to_string(m_Num);
    }
    int& operator()()
    {
        return m_Num;
    }
public:
    //算数运算符
    Int operator+(const Int& value)
    {
        return Int(this->m_Num + value.m_Num);
    }
    friend Int operator-(const Int left,const Int right)
    {
        return Int(left.m_Num - right.m_Num);
    }
    Int operator*(const Int& Value)
    {
        return Int(this->m_Num * Value.m_Num);
    }
    Int operator/(const Int& value)
    {
        return Int(this->m_Num / value.m_Num);
    }
    Int operator%(const Int& value)
    {
        return Int(this->m_Num % value.m_Num);
    }

    //自增自减运算
    Int& operator++()
    {
        this->m_Num++;
        return *this;
    }
    Int operator++(int)
    {
        return Int(this->m_Num++);
    }
    Int& operator--()
    {
        this->m_Num--;
        return *this;
    }
    Int operator--(int)
    {
        return Int(this->m_Num--);
    }
    //位运算符
    Int operator|(const Int& value)
    {
        return Int(this->m_Num | value.m_Num);
    }
    Int operator&(const Int& value)
    {
        return Int(this->m_Num & value.m_Num);
    }
    Int operator~()
    {
        return Int(~this->m_Num);
    }
    Int operator^(const Int& value)
    {
        return Int(this->m_Num ^ value.m_Num);
    }
    Int operator>>(const Int& value)
    {
        return Int(this->m_Num >> value.m_Num);
    }
    Int operator<<(const Int& value)
    {
        return Int(this->m_Num << value.m_Num);
    }
    //逻辑运算符
    bool operator!()
    {
        return !this->m_Num;
    }
    //赋值运算符
    Int& operator=(const Int& value)
    {
        *this = value;
        return *this;
    }
    Int& operator+=(const Int& value)
    {
        this->m_Num += value.m_Num;
        return *this;
    }
    //特殊单目运算符
    Int operator+()
    {
        return +this->m_Num;
    }
    Int operator-()
    {
        return -this->m_Num;
    }
    Int* operator&()
    {
        return this;
    }
    Int operator*()
    {
        return *this;
    }
    Int& operator,(Int& value)
    {
        return value;
    }
    friend ostream& operator<< (ostream& out , const Int& object)
    {
        out << object.m_Num;
        return out;
    }
    friend istream& operator>> (istream& in,Int& object)
    {
        in >> object.m_Num;
        return in;
    }
    ~Int()
    {
        cout << "调用析构函数" << endl;
    }
protected:
    int m_Num;
};
//No.2 函数包装器
class Func
{


    typedef void(*PF)();
public:
    Func(PF pf) : pf(pf){}
    void operator()()
    {
        pf();
    }
protected:
    PF pf;

};
void printInfo()
{
    cout << "函数包装器" << endl;
}
//No.3 简单版智能指针
class Auto_ptr
{
public:
    Auto_ptr(Int *ptr) : ptr(ptr){}
    ~Auto_ptr()
    {
        if (ptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }
    Int* operator->()
    {
        return this->ptr;
    }
    Int& operator*()
    {
        return *ptr;
    }
protected:
    Int* ptr;
};

//No.4 简单版动态数组
//重载[]
class myVector
{
public:
    myVector(int capacity) : capacity(capacity)
    {
        size = 0;
        base = new int[capacity] {0};       //new完初始化一下
    }
    void push_back(int data)
    {
        base[size++] = data;
    }
    int operator[](int index)
    {
        return base[index];
    }
    ~myVector()
    {
        if(base)
        {
            delete[] base;
            base = nullptr;
        }
    }
protected:
    int* base;
    int capacity;
    int size;
};

int main()
{
    Int iNum;
    cout << iNum() << endl;
    cin >> iNum;
    cout << iNum;
    if(!iNum)
    {
        cout << "iNum等于0"  << endl;
    }
    Func f(printInfo);
    f();
    {
        Auto_ptr object(new Int(1234));
    }
    myVector object(10);
    cout << object[10] << endl;
    return 0;
}