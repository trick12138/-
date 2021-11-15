#include<stdio.h>
int main()
{
    int a,b,c,e,f;
    scanf("%d",&a);
    while (a != 0)
    {
        b = a / 10;
        b = a - b * 10;
        a = a / 10;
        e = b + c * 10;
        c = e;
        printf("%d\n",b);
        f = ++f;
    }
    printf("%d\n",e);
    printf("位数为%d",f);
}