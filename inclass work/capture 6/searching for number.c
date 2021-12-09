#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {1,7,9,10,12,30,35,40};
    int b;
    int i;
    printf("请输入你要寻找的数字");
    scanf("%d",&b);
    for (i = 0; i < (sizeof(a) + 1); i++)
    {
        if (a[i] == b)
            break;
        if (a[i] == '\0')
        {
            i = -2;
            break;
        }
    }
    printf("这个数字是第%d个",++i);
    system("pause");
    return 0;
}