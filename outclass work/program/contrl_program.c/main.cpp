#include<stdio.h>
#include<graphics.h>
void screen()
{
    initgraph(640,480);
    setbkcolor(WHITE);
    setcaption("成绩管理系统");
}

int main()
{
    screen();
    getchar();
    return 0;
}