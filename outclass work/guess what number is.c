#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a;
    srand((unsigned)time(NULL));
    a=rand() % 10;
    int b;
    printf("guess what the number is(0-9)?\n");
    scanf("%d",&b);
    if (b==a)
    {
        printf("congratulations!");
    }
    else
    {
        printf("oh no the number is %d",a);
    }
    return 0;
    
}