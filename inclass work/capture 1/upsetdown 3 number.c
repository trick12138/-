#include<stdio.h>
int main()
{
    //声明变量
    int a,b=0,c=0,i3,code_long;
    //输入一个三位数,且将其长度赋值给code_long
    scanf("%d",&a);
    code_long=sizeof(a);
    //检测是否为三位数
    if (code_long == 3)
    "";
    else
    printf("请输入一个三位数");
    return 1;
    //输入三位数以后将其倒转
    while (a%10!=0)
    {
        a=a-1;
        b=b+1;
    }
    while (a%100!=0)
    {
        a=a-10;
        c=c+1;
    }
    i3=a/100+b*100+c*10;
    //打印这个三位数
    printf("%d",i3);
    return 0;
}