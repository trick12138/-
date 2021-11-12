#include<stdio.h>

int main()
{
    char c1,c2,c3,c4,c5;
    scanf("%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5);
    printf("%c%c%c%c%c\n",c1+5,c2+5,c3+5,c4+5,c5+5);
    putchar(c1+5),putchar(c2+5),putchar(c3+5),putchar(c4+5),putchar(c5+5),putchar('\n');
    return 0;
}