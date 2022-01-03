#include<stdio.h>

int main()
{
    //函数指针
    void pfun();
    void (*p)() = pfun;
    (*p)();
    return 0;
}

void pfun()
{
    printf("hello world");
}