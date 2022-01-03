#include<stdio.h>
int main()
{
    //定义函数max
    int max(int x,int y,int z);
    //声明变量
    int x,y,z,m;
    scanf("%d,%d,%d",&x,&y,&z);
    m=max(x,y,z);
    //打印最大值
    printf("%d",m);
    return 0;
}
    //判断最大值
int max(int x,int y,int z)
{
    int m;
     if(x>y)
      if(x>z)
      m=x;
      else
      m=z;
    else
      if(y>z)
      m=y;
      else
      m=z;
    return(m);
}