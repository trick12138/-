#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4][5]=
    {
        {9,80,205,40},
        {90,-60,96,1},
        {210,-3,101,89}
    };
    int sp = 0;//记录特殊的数字
    int n;//记录最大值的数位置
    for (int i = 0; i < 3; i++)
    {
        int max = a[i][0];
        for (int j = 0; j < 4; j++)  //遍历
        {
            if (max>a[i][j])  //找到最大数
            {
                "";
            }
            else
            {
                max = a[i][j];
                n = j;
            }
            if (j == 3)   //找到了最大数
            {
                for (int m = 0; m < 3; m++)  //看它是否最小
                {
                    if (i == m)
                    {
                        continue;
                    }
                    if (a[i][n] < a[m][n])
                    {
                        if (m == 2)
                        {
                            sp = a[i][n];
                        }
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            } 
        }
    }
    printf("%d",sp);
    system("pause");
    return 0;
}