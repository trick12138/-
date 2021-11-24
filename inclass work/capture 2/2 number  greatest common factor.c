#include<stdio.h>
int main()
{
    //声明三个变量
    int a,b,c;
    //输入三个变量
    scanf("%d,%d",&a,&b);
    //寻找更小的数以便化简判断
    if (a>b)
      c=b+1;
    else
      c=a+1;
    //循环寻找最大公因数
    while (c!=0)
    {
        c=c-1;
        if (a%c==0&&b%c==0)
        {
            printf("%d",c);
            break;
        }
        else
        {
            if (c==1)
            printf("no!");
        }
    }
    return 0;
    
}
//9998000099,9996200261