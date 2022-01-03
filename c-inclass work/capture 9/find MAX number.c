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
    printf("数组下标为%d的数最大为%d",top,max);
    for (int i = 0; i < MAX; i++)
    {
        if (min > *(a + i))
        {
            min = *(a + i);
            tail = i;
        }
    }
    printf("数组下标为%d的数最小为%d",tail,min);
}

int main()
{
    int *a = (int *)malloc(sizeof(int) * MAX);
    printf("请输入10个数\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d",(a + i));
    }
    findMAXnumber(a);
    system("pause");
    return 0;
}