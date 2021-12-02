#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100] = "99900000";
    char str2[100] = "99999990";
    char str3[100] = "";
    char str4[100] = "";
    char *pa = str1;
    char *pb = str2;
    char *pc = str3;
    char *pd = str4;
    int i,a4;
    for (i = 0;i < a4;i++)
    {
        if ((*(pa + i) + *(pb + i)-'0')>='0' && (*(pa + i) + *(pb + i)-'0')<='9')
        {
            *(pc + i) = *(pa + i) + *(pb + i) - '0';
        }
        else
        {
            *(pc + i) = *(pa + i) + *(pb + i) - ':';
            *(pd + i + 1) = '1';
        }
    }
    for (i = 0;i < a4;i++)
    {
        *(pc + i) = *(pc + i) + *(pd + i) - '0';
        if (NULL == strchr(pc,':'))
        {
            "";
        }
        else
        {
            char *pc2 = strchr(pc,':');
            while(*(pc2 + i) == ':')
            {
                *(pc2 + i) = '0';
                if (*(pc2 + i + 1) != ':')
                {
                    *(pc2 + i +1) += 1;
                    break;
                }
                i++;
            }
        }
    }
    printf("%s",str3);
}