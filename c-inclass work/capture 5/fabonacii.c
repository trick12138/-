#include <stdio.h>

int main()
{
    int i,a[20] = {1,1};
    for (i = 2;i <= 19 ;i++)
    {
        a[i] = a[i-1] + a[i-2];
        printf("a[%d] = %d\n",i+1,a[i]);
    }
}