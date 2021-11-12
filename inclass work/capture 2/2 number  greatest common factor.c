#include<stdio.h>
int main()
{
    long long int a,b,c;
    scanf("%I64d,%I64d",&a,&b);
    if (a>b)
      c=b+1;
    else
      c=a+1;
    while (c!=0)
    {
        c=c-1;
        if (a%c==0&&b%c==0)
        {
            printf("%I64d",c);
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