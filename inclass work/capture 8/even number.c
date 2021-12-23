#include <stdio.h>
#include <stdlib.h>
int envenumber(int a)
{
    int b,c = 0;
    while(a != 0)
    {
        b = a % 10;
        a = a / 10;
        if (!(b & 1))
        {
            c = b  + c * 10;
        }
    }
    return c;
}

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",envenumber(a));
    system("pause");
    return 0;
}