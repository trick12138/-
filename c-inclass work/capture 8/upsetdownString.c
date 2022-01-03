#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *upsetDown(char *array,int n)
{
    char pos;
    n--;
    for (int i = 0;i != n && i != (n + 1); i++,n--)
    {
        pos = *(array + i);
        *(array + i) = *(array + n);
        *(array + n) = pos;
    }
    return array;
}

int main()
{
    char str[100];
    scanf("%s",str);
    int n = strlen(str);
    printf("%s",upsetDown(str,n));
    system("pause");
    return 0;
}