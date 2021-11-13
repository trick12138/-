#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,b,d=0;    //声明变量
    srand((unsigned)time(NULL));    //随机播种
    a = rand() % 10;    //取一随机数
    printf("guess what the number is(0-9)?\n");
    while (0)    //一直循环
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