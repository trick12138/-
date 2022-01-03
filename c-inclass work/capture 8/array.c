#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i;
    for(i = 0;i < 10;i++)
    {
        scanf("%d",&a[i]);
    }
    int max = -1,maxi;
    for ( i = 0; i < 10; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxi = i;
        }
    }
    printf("这是第%d个数的值为%d",maxi+1,max);
    system("pause");
    return 0;
}