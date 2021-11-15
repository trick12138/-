#include<stdio.h>
int main()
{
    int a,b,c,e,f;//a输入,b储存a的个位,c和e储存倒过来的a,f用来计数
    scanf("%d",&a);
    while (a != 0)//判断a为0时停止循环
    {
        //计算个位
        b = a / 10;
        b = a - b * 10;
        //令a失去个位
        a = a / 10;
        //e为a倒过来
        e = b + c * 10;
        c = e;
        //打印每一位
        printf("%d\n",b);
        //循环计数
        f = ++f;
    }
    //打印a倒过来的数
    printf("%d\n",e);
    //循环次数即为位数
    printf("位数为%d",f);
}