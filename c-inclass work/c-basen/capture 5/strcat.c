#include <stdio.h>
#include <string.h>

int main()
{
    char a[20],b[10];
    gets(a);
    gets(b);
    strcat(a,b);
    printf("%s",a);
    printf("\n");
    puts(a);
    getchar();
    return 0;
}