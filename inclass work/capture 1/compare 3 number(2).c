#include<stdio.h>
int main()
{
 int max(int x,int y,int z);
 int x,y,z,m;
 scanf("%d,%d,%d",&x,&y,&z);
 m=max(x,y,z);
 printf("%d",m);
 return 0;
}
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