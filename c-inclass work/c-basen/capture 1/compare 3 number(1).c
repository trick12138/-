#include<stdio.h>
int main()
{
    //声明参数
    int a;
    int b;
    int c;
    int max;
    //输入abc三个数
    scanf("%d,%d,%d",&a,&b,&c);
    //判断谁更大
    if(a>b)
      if(a>c)
      max=a;
      else
      max=c;
    else
      if(b>c)
      max=b;
      else
      max=c;
    //返回max
    return max;  
}