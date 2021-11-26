#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned)time(NULL));
    int a;
    while (1)
    {
        a = rand()%44;
        if (a == 0 || a == 42 || a == 43 || a == 40 || a == 39 || a == 45 || a == 35)
            continue;
        else
        {
        printf("这个幸运儿是%d",a);
        break;
        }
    }
    getchar();
    return 0;
}