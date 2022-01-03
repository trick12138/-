#include <stdio.h>

int main()
{
    char a[20]= "china";
    char b[7]= "people";
    int strlen = 0;
    for (int i = 0; i < sizeof(a); i++)
    {
        if (a[i] == '\0')
        {
            break;
        }
        strlen++;
    }
    for (int i = strlen; i < sizeof(a); i++)
    {
        a[i] = b[i - strlen];
    }
    //测试结果
    printf("%s",a);
    getchar();
    return 0;
}