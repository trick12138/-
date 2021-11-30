#include <stdio.h>
char *sum(char *pa,char *pb);
char str3[100];
char str4[100];
//四则运算,加法
char *sum(char *pa,char *pb)
{
    int i=0,j=0,p1,p2,d1=0,a1,a2,a3;
    char c;
    char *pc = str3;//str3用来记录和
    char *pd = str4;//str4用来记录进位情况
    //寻找位数
    while (*(pa+i) != '\0')
    {
        i++;
    }
    while (*(pb+j) != '\0')
    {
        j++;
    }
    //a[]的倒数
    p1 = i;
    a1 = i;//a1为后续pa位数
    if (i & 1 == 1)//字符串为单数位数
    {
        while (i != (p1+1)/2-1)
        {
            c = *(pa + i - 1);//c=9
            *(pa + i - 1) = *(pa + d1);//0换8 1换7 2换6 3换5 4换4
            *(pa + d1) = c;
            i--;
            d1++;
        }
    }
    else//字符串为双数位数
    {
        while (i != p1/2)
        {
            c = *(pa + i - 1);
            *(pa + i - 1) = *(pa + d1);
            *(pa + d1) = c;
            i--;
            d1++;
        }
    }
    //检查pa
/*     printf("pa的倒数为");
    for (;p1>=0;p1--)
    {
        printf("%c",*(pa + p1 - 1));
    }
    printf("\n"); */
    //b[]的倒数
    p1 = j;
    a2 = j;//a2为后续pb位数
    d1 = 0;//重新初始化
    if (j & 1 == 1)//字符串为单数位数
    {
        while (j != (p1+1)/2)
        {
            c = *(pb + j - 1);
            *(pb + j - 1) = *(pb + d1);
            *(pb + d1) = c;
            j--;
            d1++;
        }
    }
    else//字符串为双数位数
    {
        while (j != p1/2)
        {
            c = *(pb + j - 1);
            *(pb + j - 1) = *(pb + d1);
            *(pb + d1) = c;
            j--;
            d1++;
        }
    }
    //检查pb
/*     printf("pb的倒数为");
    for (;p1>0;p1--)
    {
        printf("%c",*(pb + p1));
    }
    printf("\n"); */
    //相加
    i=0;//重新初始化
    //补0
    //判断a1,a2谁大赋值给a3
    a3 = (a1>a2)?a1:a2;
    j = a3 + 1;
    int a4 = a3;
    int a5 = a3;//这俩用来计数
    //补0
    while (i < (a3 + 1))
    {
        if (*(pa+i) >= '0' && *(pa+i) <= '9')
        {
            i++;
            continue;
        }
        else
        {
            *(pa+i) = '0';
            i++;
        }
    }
    i = 0;//再次初始化
    while (i < (a3 + 1))
    {
        if (*(pb+i) >= '0' && *(pb+i) <= '9')
        {
            i++;
            continue;
        }
        else
        {
            *(pb+i) = '0';
            i++;
        }
    }
    i = 0;//再再次初始化
    while (i < a3)
    {
        *(pd + i) = '0';
        i++;
    }
/*     printf("\n"); */
    //检查pa
/*     printf("pa为");
    for (;a4>=0;a4--)
    {
        printf("%c",*(pa + a4));
    }
    printf("\n");
    //检查pb
    printf("pb为");
    for (;a5>=0;a5--)
    {
        printf("%c",*(pb + a5));
    }
    printf("\n"); */
    //相加
    a4 = a3 + 1;
    a5 = a3 + 1;//这俩用来计数
    for (i = 0;i <= a4;i++)
    {
        if ((*(pa + i) + *(pb + i)-'0')>='0' && (*(pa + i) + *(pb + i)-'0')<='9')
        {
            *(pc + i) = *(pa + i) + *(pb + i) - '0';
        }
        else
        {
            *(pc + i) = *(pa + i) + *(pb + i) - ':';
            *(pd + i + 1) = '1';
        }
    }
    for (i = 0;i <= a4;i++)
    {
        *(pc + i) = *(pc + i) + *(pd + i) - '0';
    }
    //检查和
/*     printf("\na4=%d",a4);
    printf("\npc为");
    for (i = 0;i <= a4;i++)
    {
        printf("%c",*(pc + i));
    }
    printf("\n"); */
    //初始化
    j = 0,d1 = 0;
    //寻求pc位数
    while (*(pc + j) != '\0')
    {
        j++;
    }
    p2 = j;
    //再次倒转
    if (j & 1 == 1)//字符串为单数位数
    {
        while (j != (p2+1)/2)
        {
            c = *(pc + j - 1);
            *(pc + j - 1) = *(pc + d1);
            *(pc + d1) = c;
            j--;
            d1++;
        }
    }
    else//字符串为双数位数
    {
        while (j != p2/2)
        {
            c = *(pc + j - 1);
            *(pc + j - 1) = *(pc + d1);
            *(pc + d1) = c;
            j--;
            d1++;
        }
    }
    //再次检查和
/*     printf("\na4=%d",a4);
    printf("\npc倒过来为");
    for (i = 0;i <= a4;i++)
    {
        printf("%c",*(pc + i));
    }
    printf("\n"); */
    return pc;
}