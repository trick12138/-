#include <stdio.h>
#include <stdlib.h>

void sort(int *array,int n)
{
    int exit = 0,change;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (array[j] < array[j + 1])
            {
                change = array[j];
                array[j] = array[j + 1];
                array[j + 1] = change;
            }
        }
    }
}

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&array[i]);
    }
    int n = sizeof(array) / sizeof(array[0]);
    sort(array,n);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    system("pause");
    return 0;
}