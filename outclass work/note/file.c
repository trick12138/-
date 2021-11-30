#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n");
    //fgets读取一行
    char str[200];
    char *p = fgets(str,200,fp);
    printf("%s\n",str);
    printf("%s\n",p);
    //fread自由读取,返回读取大小
    char str1[200];
    while (fread(str1, 1 , 100, fp))
    {
        printf("%s", str1);
    }
    //清空并且写入字符
    FILE* hp = fopen("test.txt","rw");
    if(hp == NULL)
    {
        printf("打开文件失败");
        return 0;
    }
    //写入一个字符
    /* fputc('A',hp);
    fputc('B',hp);
    //写入字符串fput
    char *str2 = (char*)"Hello world\r";
    fputs(str2,hp);
    fputs(str2,hp); */
    //文件指针定位
    fseek(hp,0,SEEK_SET);
    //写入任意fwrite,转换为2进制,文件指针写完偏移下一个
    int num = 456123;
    fwrite(&num, 1, sizeof(num), hp);
    int num1;
    fread(&num1, 1, sizeof(num), hp);
    printf("num1=%d",num1);
    //fseek移动文件指针
    int lenth;
    ch = 0;
    fseek(hp, -1, SEEK_END);//指针移动到结尾
    while(fread(&ch,1,1,hp))
    {
        if(ch == '\n')
            break;
        fseek(hp, -2,SEEK_CUR);
        lenth++;
    }
    printf("大概有%d这么长",lenth);
    //关闭文件
    fclose(fp);
    fclose(hp);
    return 0;
}