#include<stdio.h>
int main()
{
    int a,i = 0,b = 0,c,d;
    scanf("%d",&a);
    while(a>0)
    {
    b = b * 10 + a % 10;
    a = a / 10;
    i++;
    }
    printf("%d位数\n", i);
    c = b;
    while(c>0)
    {
    d = c % 10;
    c = c / 10;
    printf("%d\n",d);
    }
    printf("%d", b);
    return 0;