/*
    直接使用C++的queue容器
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> NumArray[10];
    int putNum;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&putNum);
        NumArray[putNum].push(putNum);
    }
    for (int i = 0; i < 10; i++)
    {
        while (!NumArray[i].empty())
        {
            cout << NumArray[i].front() << ' ';
            NumArray[i].pop();
        }
        cout << endl;
    }
    system("pause");
    return 0;
}