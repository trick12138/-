#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,e,f,g;
    scanf("%d",&a);
    g = a;
    while (a != 0)
    {
        b = a / 10;
        b = a - b * 10;
        a = a / 10;
        e = b + c * 10;
        c = e;
        f = ++f;
    }
    printf("位数为%d\n",f);
    while(f != 0)
    {
        f=--f;
        a=pow(10,f);
        b=g/a;
        printf("%d\n",g/a);
        g=g-a*b;
    }
    printf("%d\n",e);
}