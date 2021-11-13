#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a,b;    //声明变量
    srand((unsigned)time(NULL));   //随机播种
    a=rand() % 10;    //取一随机数
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