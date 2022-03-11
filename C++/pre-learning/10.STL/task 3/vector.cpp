#include <iostream>
#include <vector>

using namespace std;
/*
No.1 vector: 动态数组
    1.1 #include <vector>
    1.2 带参数构造方式以及不带参构造方式
        1.2.1 不带参构造方式: 只能通过成员函数的方式进行插入数据
            push_back() 进行插入
        1.2.2 带参数  可以直接使用下标的方式进行操作
            下标是从0开始的和学习的数组是一样的
            超过了定义的长度, 如果还需要进行插入, 我们一定采用成员函数的方式
        1.3 遍历: 直接通过数组下标这种形式
                    或者通过迭代器
No.2 操作自定义类型(关键点还是重载)

*/
class MM
{
public:
    MM(string name,int age) :name(name) ,age(age){}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    friend ostream& operator<<(ostream& out,MM& object)
    {
        out << object.name << "\t" << object.age;
        return out;
    }
protected:
    string name;
    int age;
};

template <class T>
class my_vector
{
public:
    my_vector()
    {

    }
    my_vector(int size) :size(size)
    {
        memory = new T[size];
    }
    T& operator[](int index)
    {
        return memory[index];
    }
    T* begin()
    {
        return memory;
    }
    T* end()
    {
        return memory + size;
    }
public:
    class iterator
    {
    public:
        iterator operator=(T* pMove)
        {
            this->pMove = pMove;
            return *this;
        }
        bool operator!=(T* pMove)
        {
            return this->pMove != pMove;
        }
        iterator& operator++(int)
        {
            pMove++;
            return (*this);
        }
        T& operator*()
        {
            return pMove[0];
        }
    protected:
        T* pMove;
    };
protected:
    T* memory;
    int size = 0;
};

int main()
{
    vector<int> array;
    my_vector<int> myArray;
    cout << array.capacity() << endl;
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    vector<string> str(4);
    my_vector<string> myStr;
    for(int i = 0;i < 4;i++)
    {
        str[i] = string("name");
    }
    str.push_back("I Love You");
    vector<int> num = {1,2,3,4};
    for (int i = 0; i < 4; i++)
    {
        cout << num[i] << endl;
    }
    vector<string>::iterator strIter = str.begin();
    for (;strIter != str.end(); strIter++)
    {
        cout << *strIter << "\t";
    }
    cout << endl;
    //操作自定义类型
    vector<MM> mm;
    for (int i = 0; i < 3; i++)
    {
        mm.push_back(MM("小可爱",18));
    }
    for (auto v : mm)
    {
        cout << v.getName() << "\t" << v.getAge() << endl;
    }
    vector<MM>::iterator mmIter;
    for (mmIter = mm.begin();mmIter != mm.end(); mmIter++)
    {
        /* cout << mmIter->getName() << "\t" << mmIter->getAge() << endl; */
        cout << *mmIter << endl;
    }
    cout << mm.at(2) << endl;
    cout << mm[2] << endl;
    cout << mm.size() << endl;
    cout << mm.capacity() << endl;
    cout << mm.empty() << endl;\
    int array1D[3] = {1,2,3};
    vector<int> myvec;
    myvec.assign(array1D,array1D + 3);
    for (auto v : myvec)
    {
        cout << v << "\t";
    }
    cout << endl;

    my_vector<int> myvector(3);
    for (int i = 0; i < 3; i++)
    {
        myvector[i] = i;
    }

    for (auto v : myvector)
    {
        cout << v << "\t";
    }
    cout << endl;
    my_vector<int>::iterator myIter;
    for (myIter = myvector.begin(); myIter != myvector.end(); myIter++)
    {
        cout << *myIter << "\t";
    }
    cout << endl;
    return 0;
}