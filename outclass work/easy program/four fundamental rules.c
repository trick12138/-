#include <stdio.h>
void sum(char *pa,char *pb);
char str3[100] = "0";
char str4[100] = "\0";
int main()
{
    char str1[100] = "123456789";
    char str2[100] = "87654321";
    sum(str1,str2);
}

//四则运算,加法
void sum(char *pa,char *pb)
{
    int i=0,j=0,p1,d1=0;
    char c;
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
    if (i & 1 == 1)//字符串为单数位数
    {
        while (i != (p1+1)/2)
        {
            c = *(pa + i);
            *(pa + i) = *(pa + d1);
            *(pa + d1) = c;
            i--;
            d1++;
        }
    }
    else//字符串为双数位数
    {
        while (i != p1/2)
        {
            c = *(pa + i);
            *(pa + i) = *(pa + d1);
            *(pa + d1) = c;
            i--;
            d1++;
        }
    }
    //检查pa
    printf("pa的倒数为");
    for (;p1>0;p1--)
    {
        printf("%c",*(pa + p1));
    }
    printf("\n");
    //b[]的倒数
    p1 = j;
    d1 = 0;//重新初始化
    if (j & 1 == 1)//字符串为单数位数
    {
        while (j != (p1+1)/2)
        {
            c = *(pb + j);
            *(pb + j) = *(pb + d1);
            *(pb + d1) = c;
            j--;
            d1++;
        }
    }
    else//字符串为双数位数
    {
        while (j != p1/2)
        {
            c = *(pb + j);
            *(pb + j) = *(pb + d1);
            *(pb + d1) = c;
            j--;
            d1++;
        }
    }
    //检查pb
    printf("pb的倒数为");
    for (;p1>0;p1--)
    {
        printf("%c",*(pb + p1));
    }
    printf("\n");
    //相加
    i=0;//重新初始化
    while(*(pa + i) != '\0')
    {
        printf("1");
        i++;
    }
    printf("%c",*(pa+10));
}