#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {1,7,9,10,12,30,35,40};
    int b;
    int i;
    printf("��������ҪѰ�ҵ�����");
    scanf("%d",&b);
    for (i = 0; i < (sizeof(a) + 1); i++)
    {
        if (a[i] == b)
            break;
        if (a[i] == '\0')
        {
            i = -2;
            break;
        }
    }
    printf("��������ǵ�%d��",++i);
    system("pause");
    return 0;
}