#include <stdio.h>
#include <string.h>

int main()
{   //循环寻址进位
    char str[100] = "999999999";
    char *pa = str;
    int i;
    if (NULL == strchr(pa,'9'))
    {

    }
    else
    {
        char *pb = strchr(pa,'9');
        while(*(pb+i) == '9')
        {
            *(pb + i) = '0';
            if (*(pb+i+1) != '9')
            {
                *(pb + i +1) += 1;
                break;
            }
            i++;
        }
    }
    printf("%s",pa);
}