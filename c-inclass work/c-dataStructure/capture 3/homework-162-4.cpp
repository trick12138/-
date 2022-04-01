#include <iostream>

using namespace std;

int ans(int num)
{
    if (num == 0)
        return 1;
    if (num == 1)
        return 1;
    return ans(num - 1) + ans(num - 2);
}

int main()
{
    cout << ans(5) << endl;
    return 0;
}
/*
运行结果
8
*/