#include <stdio.h>
#include <math.h>
/*
  y=a*x*x+b*x+c

*/

int main()
{
    float a,b,c;
    printf("请输入abc的值,用空格隔开");
    scanf("%f %f %f",&a,&b,&c);
    if ((b*b-4*a*c)>=0)
    {
        a=(-b+sqrt(b*b-4*a*c))/2*a;
        b=(-b-sqrt(b*b-4*a*c))/2*a;
        printf("x1=%f,x2=%f",a,b);
    }
    if ((b*b-4*a*c<0))
    {
        printf("没有呢");
    }
}