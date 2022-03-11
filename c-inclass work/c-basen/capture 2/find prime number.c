#include<stdio.h>
int main()
{
    //声明变量
    int a,b;
    a=1;
    //从2开始寻找质数
    while (a<=100000)//此处为最大的值
    {
        a=a+1;
        b=a;
       while (b!=1)
       {
           b=b-1;
           if (a%b==0)
           break;
           else
             if (b==2)
             printf(" %d",a);
       }
    }
}