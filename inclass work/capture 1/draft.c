#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int map[10][10] = {0},thunder[10],col,row;
    srand((unsigned)time(NULL));
    //随机生成10个不同的数,为生成雷做准备
    for (int i = 0; i < 10;)
    {
        thunder[i] = rand() % 100;
        for (int j = 0; j <= (i + 1); j++)
        {
            if (i == j)
            {
                i++;
                break;
            }
            else if (thunder[i] == thunder[j])
            {
                break;
            }
            
        }
    }
    //埋雷
    for (int i = 0; i < 10; i++)
    {
        col = thunder[i] / 10;
        row = thunder[i] % 10;
        map[col][row] = -1;
        //在雷的附近设置1
        if (map[col-1][row-1] == 0)
        {
            map[col-1][row-1] = 1;
        }
        if (map[col][row-1] == 0)
        {
            map[col][row-1] = 1;
        }
        if (map[col+1][row-1] == 0)
        {
            map[col+1][row-1] = 1;
        }
        if (map[col+1][row] == 0)
        {
            map[col+1][row] = 1;
        }
        if (map[col+1][row+1] == 0)
        {
            map[col+1][row+1] = 1;
        }
        if (map[col][row+1] == 0)
        {
            map[col][row+1] = 1;
        }
        if (map[col-1][row+1] == 0)
        {
            map[col-1][row+1] = 1;
        }
        if (map[col-1][row] == 0)
        {
            map[col-1][row] = 1;
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