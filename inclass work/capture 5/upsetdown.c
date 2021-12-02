#include <stdio.h>

int main()
{
    int i,j,j1=0;
    int a[] = {9,8,7,6,5,4,3};
    i = sizeof(a) / 4;
    printf("i=%d\n",i);
    //数组个数判断调换
    if (i & 1)
    {
        for (j = (i - 1); j >= (i-1)/2; j--)
        {
            a[j] += a[j1];
            a[j1] = a[j] - a[j1];
            a[j] = a[j] - a[j1];
            j1++;
        }
    }
    else
    {
        for (j = (i - 1); j >= (i/2 + 1); j--)
        {
            a[j] += a[j1];
            a[j1] = a[j] - a[j1];
            a[j] = a[j] - a[j1];
            j1++;
        }
    }
    //遍历检测
    for (int k = 0; k < i; k++)
    {
        printf("a[%d]=%d\n",k,a[k]);
    }
    
    
}