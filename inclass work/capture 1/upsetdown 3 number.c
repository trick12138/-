#include<stdio.h>
int main()
{
    int a,b=0,c=0,i3;
    scanf("%d",&a);
    while (a%10!=0)
    {
        a=a-1;
        b=b+1;
    }
    while (a%100!=0)
    {
        a=a-10;
        c=c+1;
    }
    i3=a/100+b*100+c*10;
    printf("%d",i3);
    return 0;
}