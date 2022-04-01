#include <iostream>

using namespace std;

int lens(int num)
{
    static int n = 0;
    if (num == 0)
        return n;
    ++n;
    lens(num / 10);
    return n;
}

int main()
{
    int a = 123456;
    cout << lens(a) << endl;
    return 0;
}
/*
运行结果
6
*/