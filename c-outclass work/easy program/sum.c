/*
事情是这样的,书上有道
*/
#include <stdio.h>
void yuefen(long long int *a,long long int *b);
int main()
{
    long long int i=0,a=2,b=1,c=3,d=2,e=0;
    while (i<19)
    {
        //求和
        a = a * d + b * c;//7 31
        b = b * d;//2 6
        //约分
        yuefen(&a,&b);
        //下一个数字
        e = c + d;
        d = c;//3
        c = e;//5
        i++;
        printf("第%d次结果为%lld/%lld\n",i+1,a,b);
    }
    printf("二十项之和为%lld/%lld",a,b);
    return 0;
}

void yuefen(long long int *a,long long int *b)
{
    //声明三个变量
    long long int c,m,n;
    //寻找更小的数以便化简判断
    if (*a>*b)
      c=*b+1;
    else
      c=*a+1;
    //循环寻找最大公因数
    m = *a;
    n = *b;
    do
    {
        c = m % n;
        m = n;
        n = c;
    }
    while (n);
    //把a,b约分
    *a = *a/m;
    *b = *b/m;
}