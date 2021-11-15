#include<stdio.h>
#define Pi 3.1415926
int main()
{
    float r,h;    //声明两个变量
    printf("please enter the circle's radius\n");    //输入
    scanf("%f",&r);
    printf("please enter the circle's high\n");
    scanf("%f",&h);
    printf("圆的周长为%0.2f\n",2*r*Pi);    //输出
    printf("圆的面积为%f\n",r*r*Pi);
    printf("圆球表面积为%f\n",4*Pi*r);
    printf("圆球体积为%f\n",(float)4/(float)3*r*r*r*Pi);//易错点这里如果不用类型转化而直接4/3会直接得到1,因为int和int相乘,得到int,所以要进行类型转化,转一个就行了,因为浮点和整形的运算会自动都转化为浮点
    printf("圆柱体积为%f\n",Pi*r*r*h);
}