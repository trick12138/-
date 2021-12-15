#include <stdio.h>

int main()
{
    int sum = 0,start = 1,stop = 10,i;
    for ( i = start; i <= stop; i++)
    {
        sum+=i;
    }
    printf("%d",sum);
    return 0;
}