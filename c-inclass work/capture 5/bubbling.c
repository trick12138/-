#include <stdio.h>

int main()
{
    int a[] = {89,100,65,160,210,66,999,78,45,87};
    int j;
    for (int i = 0;; i++)
    {
        //冒泡排序
        if (a[i] >= a[i+1])
        {
            if (i == 8)
                i = -1;
            continue;
        }
        else
        {
            a[i] += a[i+1];
            a[i+1] = a[i] - a[i+1];
            a[i] = a[i] - a[i+1];
            if (i == 8)
                i = -1;
        }
        //退出条件
        for (j = 0; j <= 8; j++)
        {
            if (a[j] >= a[j+1])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j == 9)
        {
            break;
        }
    }
    //遍历数组检查
    for (int i = 0; i <= 9; i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
    
    
}