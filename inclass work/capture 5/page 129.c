#include<stdio.h>
int main()
{
    int a=1,b=1,i;
    for ( i = 0; i <= 20; i++)
    {
        a+=b;
        printf("%d\n",a);
        b+=a;
        printf("%d\n",b);
    }
    return 0;
}