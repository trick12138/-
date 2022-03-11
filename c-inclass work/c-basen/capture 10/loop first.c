#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop(int *array)
{
    int change;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (*(array + j) < *(array + j + 1))
            {
                change = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = change;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = rand();
    }
    loop(array);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    system("pause");
    return 0;
}