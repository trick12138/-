#include <stdio.h>

int main()
{
    int a[8] = {9,8,7,6,4,3,2};
    int b,j,i;
    scanf("%d",&b);
    //检测大小
    for (int i = (sizeof(a)/4)-1; i >= 0; i--)
    {
        if (b < a[i])
        {
            j = i;
            break;
        }
    }
    //插入
    for (i = (sizeof(a) / 4) - 1; i > j; i--)
    {
        a[i] = a[i-1];
    }
    a[j + 1] = b;
    return 0;
}