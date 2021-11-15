#include<stdio.h>
int main()
{
    int a,c;
    double b;
    a = 465457;
    b = (double)a/10;
    a = a/10;
    printf("%d\n",a);
    b = (b - a)*10;
    printf("%f\n",b);
    c = b;
    printf("%d",c);
}