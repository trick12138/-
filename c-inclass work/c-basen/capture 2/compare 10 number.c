#include<stdio.h>
int main()
{
   //声明变量
    int max,n,a[10];
    //循环输入
    for(n=0;n<=9;n++)
    {
       scanf("%d",&a[n]);
    }
    //令max=0
    max=0;
    //循环检测使得max取最大
    for(n=0;n<=9;n++)
    {
       if (max>=a[n])
       "";
       else
         max=a[n];
    }
    printf("%d",max);
    return 0;
}