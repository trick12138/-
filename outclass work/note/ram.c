#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i <= n; i++)
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
    for (int i = 0; i < (n + 1) ; i++)
    {
        printf("%d ",*(pc + i));
    }
    //free 用于释放内存
    free(pa);
    free(pb);
    return 0;
}