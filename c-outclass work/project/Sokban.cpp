#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

//使用二维数组表示地图
//0:空地;   1:墙壁  3:箱子的目的地; 4:箱子
//6:人  7:箱子和目的地重合;  9:人站在目的地
int g_map[10][12] = 
{
    {1,1,1,1,1,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,1,1,1,0,0,0},
    {1,0,4,0,1,0,1,1,1,1,1,1},
    {1,0,4,6,1,0,1,0,0,0,3,1},
    {1,1,1,4,1,1,1,0,0,0,3,1},
    {0,1,0,0,0,0,0,0,0,0,3,1},
    {0,1,0,0,0,1,0,0,0,0,0,1},
    {0,1,0,0,0,1,0,0,0,0,0,1},
    {0,1,1,1,1,1,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,1,1,1,1,1},
};

//打印地图
void DrawMap();

int main()
{
    //设置窗口大小
    initgraph(250,300);
    //主程序
    while (1)
    {

        system("pause");
    }
    return 0;
}

//打印地图
void DrawMap()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            switch (g_map[i][j])
            {
            case 0: printf("  ");
                break;
            case 1: printf("■");
                break;
            case 3: printf("○");
                break;
            case 4: printf("@");
                break;
            case 6: printf("♀");
                break;
            case 7: printf("●");
                break;
            case 9: printf("♂");
                break;
            default:
                break;
            }
        }
        
    }
    
}