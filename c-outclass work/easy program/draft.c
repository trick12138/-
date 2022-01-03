#include <stdio.h>
#include <stdlib.h>
struct num
{
    int average;
    int max;
    int min;
};

struct num *average(float *array,int n)
{
    struct num *amm = (struct num*)malloc(sizeof(struct num));
    float sum = 0;
    amm->max = array[0];
    amm->min = array[0];
    for (int i = 0; i < n; i++)
    {
        if (amm->max < array[i])
            amm->max = array[i];
        if (amm->min > array[i])
            amm->min = array[i];
        sum = sum + array[i];
    }
    amm->average = sum / n;
    return amm;
}

int main()
{
    float array[5] = {1,2,3,4,5};
    int n = sizeof(array) / sizeof(array[0]);
    struct num *data = average(array,n);
    printf("最大值%d,最小值%d,平均值%d",data->max,data->min,data->average);
    system("pause");
    return 0;
}