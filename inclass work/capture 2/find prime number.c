#include<stdio.h>
int main()
{
    int a,b;
    a=1;
    while (a<=100000)
    {
        a=a+1;
        b=a;
       while (b!=1)
       {
           b=b-1;
           if (a%b==0)
           break;
           else
             if (b==2)
             printf(" %d",a);
       }
    }
}