#include <stdio.h>
int fab(int a)
{
    if (a == 1)
        return a;
    else
        return fab(a - 1) * a;
}

int main()
{
    printf("%d",fab(9));
    return 0;
}