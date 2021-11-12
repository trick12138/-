#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,c=0,d=0;
    srand((unsigned)time(NULL));
    a = rand() % 10;
    int b;
    printf("guess what the number is(0-9)?\n");
    while (c <= 1)
    {
        scanf("%d", &b);
        if (b == a)
        {
            printf("congratulations!\n",d);
            break;
        }
        else
        {
            if (a < b)
            {
                printf("smaller!\n");
            }
            else
            {
                printf("bigger!\n");
            }
        }
    }
    return 0;
}