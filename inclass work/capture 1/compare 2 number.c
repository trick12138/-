#include<stdio.h>
//主函
int main ()
{
    int max(int x,int y);
    int a,b,c;
    scanf("%d,%d",&a,&b);
    c=max(a,b);
    printf("max=%d\n",c);
    return 0;
}
//比较两个数大小
int max(int x,int y)
{
    int z;
    if(x>y)z=x;
    else z=y;
    return z;
}