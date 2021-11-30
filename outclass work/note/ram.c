#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   //动态开辟内存空间
    //malloc 直接分配
    int n;
    printf("你需要多少字节的空间呢？");
    scanf("%d",&n);
    char *pa = (char*)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++)
    {
        *(pa + i) = i * 10;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(pa + i));
    }
    //calloc 会像全局变量一样赋初值
    char *pb = (char*)calloc(1,sizeof(char) * n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(pb + i));
    }
    //reallco 可以改变动态内存大小
    char *pc = (char*)realloc(pb,sizeof(char) * (n + 1));
    for (int i = 0; i < n ; i++)
    {
        printf("%d ",*(pc + i));
    }
    printf("\n");
    //free 用于释放内存
    free(pa);
    free(pb);
    //内存操作函数
    //memccpy函数
    //定义一个结构体
    typedef struct ram
    {
        int a;
        char b;
    }ram1;
    ram1 node1 = {1,'A'},node2;
    memcpy(&node2,&node1,sizeof(ram1));
    char *pd = (char*)&node2;
    printf("第一个为%d,第二个为%c\n",*(pd + 0),*(pd + 4));
    //memmove函数用法和memcpy类似
    //memmove(void *_Dst,const void *_Src, size_t);

    //memchr用于查找字符，返回指针,找不到返回null
    char *pe = (char*)memchr(pa,'(',sizeof(char) * n);
    printf("pe=%d\n",pe);

    //memset设置内存
    memset(pd,'h',5);
    printf("pd=%s",pd);
    return 0;
}