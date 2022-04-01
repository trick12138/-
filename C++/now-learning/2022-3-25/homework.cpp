#include <iostream>

using namespace std;

class base
{
public:
    virtual void print() = 0;
};

class p :public base
{
public:
    void print()
    {
        cout << "hello world" << endl;
    }
};

int main()
{

    return 0;
}