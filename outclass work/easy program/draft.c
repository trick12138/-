#include<stdio.h>
int main()
{
    int i = 0;
    char a[100] = "1234";
    char b[100] = "12";
    char d[100];
    while(i < 5)
    {
        if ( *(b+i) > '0'&& *(b+i) < '9')
        {
            i++;
            continue;
        }
        else
        {
            *(b+i) = '0';
            i++;
        }
        
    }
/*     while (i < 4)
    {
        *( d + i) = *(a + i) + *(b + i) - '0';
        i++;
    } */
    for ( i = 0; i < 4; i++)
    {
        printf("%c",*( b + i));
    }
}