#include <stdio.h>
#include <stdlib.h>

int my_strcmp(const char *s1,const char *s2)
{
    int i = 0;
    while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
    {
        if (*(s1 + i) == *(s2 + i))
        {
            i++;
        }
        else
        {
            return *(s1 + i) - *(s2 + i);
        }
    }
    return 0;
}

int main()
{
    const char *s1 = "mynameisyxw";
    const char *s2 = "mynameiszyg";
    printf("比较结果是%d",my_strcmp(s1,s2));
    system("pause");
    return 0;
}