#include <stdio.h>

int max2(int a,int b)
{
    return (a>b?a:b);
}

int max4(int a,int b,int c, int d)
{
    int m;
    m = max2(a,b);
    m = max2(m,c);
    m = max2(m,d);
    m = max2(m,d);
    return m;
}
int main()
{
    int a,b,c,d,max;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    max = max4(a,b,c,d);
    printf("最大值为%d",max);
    return 0;
}