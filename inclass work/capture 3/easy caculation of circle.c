#include<stdio.h>
#define Pi 3.1415926

int main()
{
    float r,h;
    printf("please enter the circle's radius\n");
    scanf("%f",&r);
    printf("please enter the circle's high\n");
    scanf("%f",&h);
    printf("圆的周长为%0.2f\n",2*r*Pi);
    printf("圆的面积为%f",r*r*Pi);
    printf("圆球表面积为%f",4*Pi*r);
    printf("圆球体积为%f",4/3*r*r*r*Pi);
    printf("圆柱体积为%f",Pi*r*r*h);
}