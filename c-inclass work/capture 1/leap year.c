#include<stdio.h>
int main()
{
    //声明变量
    int a,b,i;
    //输入最大年和最小年
    scanf("%d,%d",&a,&b);
    //循环检测闰年
    for ( i = a; i < b; i++)
    {
        if (i%4==0)
          if(i%100!=0)
          printf("%d\n",i);
          else
            if(i%400==0)
            printf("%d\n",i);
    }
    
    return 0;
}