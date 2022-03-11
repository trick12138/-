#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void sort(int *a)
{
    int pos;
    for (int j = 0; j < (MAX - 1); j++)
    {
        for (int i = 0; i < (MAX - 1); i++)
        {
            if (*(a + i) < *(a + i + 1))
            {
                pos = *(a + i);
                *(a + i) = *(a + i + 1);
                *(a + i + 1) = pos;
            }
        }
    }
    return;
}

int main()
{
    int *a = (int *)malloc(sizeof(int) * MAX);
    printf("ÇëÊäÈë10¸öÊý\n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d",(a + i));
    }
    sort(a);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ",*(a + i));
    }
    system("pause");
    return 0;
}