#include<stdio.h>
int main()
{
    int a=1,b=1,i;
    for ( i = 0; i <= 20; i++)
    {
        a+=b;
        b+=a;
        printf("%d\n",a);
        printf("%d\n",b);
    }
    return 0;
}