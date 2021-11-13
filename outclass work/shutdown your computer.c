#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    printf("请输入一个数字来执行操作:\n1.立即关机(1分钟后) 2.立即重启 3.等待1.5小时后关机\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:system("shutdown -s");
        break;
    case 2:system("shutdown -r");
        break;
    case 3:system("shutdown -s -t 1800");
    default:
        break;
    }
}