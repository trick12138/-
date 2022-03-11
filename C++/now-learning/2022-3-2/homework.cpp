#include <iostream>
#include <time.h>
#define MAX 10

using namespace std;

void sort(int *array,int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1]; 
            }
        }
}

void sort(float *array,int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1]; 
            }
        }
}

void sort(double *array,int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j + 1]; 
            }
        }
}

int main()
{
    srand((unsigned)time(NULL));
    int array[MAX];
    float fArray[MAX] = {3.14,4.13,5.12,6.18,9.14,3.15,4.16,5,11,6.17};
    for (int i = 0; i < MAX; i++)
    {
        array[i] = rand() % 100;
    }
    sort(array,MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ",array[i]);
    }
    putchar('\n');
    sort(fArray,MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("%f ",fArray[i]);
    }
    return 0;
}