#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void findMAXnumber(int *a)
{
    int top,tail;
    int max = *a,min = *a;
    for (int i = 0; i < MAX; i++)
    {
        if (max < *(a + i))
        {
            max = *(a + i);
            top = i;
        }
    }
    printf("�����±�Ϊ%d�������Ϊ%d",top,max);
    for (int i = 0; i < MAX; i++)
    {
        if (min > *(a + i))
        {
            min = *(a + i);
            tail = i;
        }
    }
    printf("�����±�Ϊ%d������СΪ%d",tail,min);
}

int main()
{
    int *a = (int *)malloc(sizeof(int) * MAX);
    printf("������10����\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d",(a + i));
    }
    findMAXnumber(a);
    system("pause");
    return 0;
}