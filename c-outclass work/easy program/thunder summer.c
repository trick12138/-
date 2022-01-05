#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    //描述地图
    int map[10][10] = {0},col,row;
    //生成雷
    for (int i = 0; i < 10;)
    {
        col = rand() % 10;
        row = rand() % 10;
        if (map[col][row] != -1)
        {
            map[col][row] = -1;
            //旁边＋1
            for (int j = col - 1; j <= col + 1; j++)
            {
                for (int k = row - 1; k <= row + 1; k++)
                {
                    if (j >= 0 && j < 10 && k >= 0 && k < 10 && map[j][k] != -1)
                    {
                        map[j][k]++;
                    }
                }
            }
            ++i;
        }
    }
    //打印地图
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%2d ",map[i][j]);
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}