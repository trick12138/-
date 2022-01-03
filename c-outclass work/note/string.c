#include<stdio.h>
#include<string.h>
//字符串类型函数
int main()
{
    int c;
    char *a= (char*)"helloworld";
    char b[20] = {0};
    //计算字符串长度
    c = strlen(a);
    printf("c=%d",c);
    //连接字符串
    strcat(a,b);
    printf("%s",b);
}