#include <stdio.h>

int main()
{
    //打开文件
    FILE* fp = fopen("C:\\Users\\雾霾\\Desktop\\笔记.txt","r");
    if(fp == NULL)
    {
        printf("打开文件失败");
        return 0;
    }
    //操作
    //fgetc读取一个字符
    char ch;
    while(EOF != (ch = fgetc(fp)))
    {
        printf("%c",ch);
    }
    //fgets读取一行
    char str[200];
    fgets(str,200,fp);
    printf("%s",str);
    //关闭文件
    fclose(fp);
    return 0;
}