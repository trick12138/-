#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "stack.c"
#define LEVELS 4

//使用二维数组表示地图
//0:空地;   1:墙壁  3:箱子的目的地; 4:箱子
//6:人  7:箱子和目的地重合;  9:人站在目的地
int LEVEL = 0;  //关卡

int g_map[LEVELS][10][12] = 
{
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
    },
    {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,0,0,0,0,0},
        {0,0,0,0,1,3,1,0,0,0,0,0},
        {0,0,1,1,1,4,1,1,1,0,0,0},
        {0,0,1,0,0,6,0,0,1,0,0,0},
        {0,0,1,1,4,0,4,3,1,0,0,0},
        {0,0,0,1,3,1,1,1,1,0,0,0},
        {0,0,0,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        {0,0,0,1,1,1,1,1,0,0,0,0},
        {0,0,1,1,0,0,0,1,1,0,0,0},
        {0,0,1,0,0,1,3,0,1,0,0,0},
        {0,0,1,0,0,0,7,0,1,0,0,0},
        {0,0,1,1,0,0,4,0,1,0,0,0},
        {0,0,0,1,0,7,7,6,1,0,0,0},
        {0,0,0,1,1,1,0,0,1,0,0,0},
        {0,0,0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        {0,0,0,1,1,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,1,0,0,0,0,0},
        {0,0,1,1,6,4,1,0,0,0,0,0},
        {0,0,1,0,4,0,1,1,0,0,0,0},
        {0,1,1,3,1,3,0,1,0,0,0,0},
        {0,1,0,7,0,7,0,1,1,0,0,0},
        {0,1,0,0,0,0,0,0,1,0,0,0},
        {0,1,1,1,1,0,0,0,1,0,0,0},
        {0,0,0,0,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    },
};

//载入UI
PIMAGE g_case = newimage();                 //载入墙壁图片
PIMAGE g_destination = newimage();          //载入目的地图片
PIMAGE g_box = newimage();                  //载入箱子图片
PIMAGE g_player = newimage();               //载入人物图片
PIMAGE g_destination_box = newimage();      //载入箱子和目的地重合
PIMAGE g_player_destination = newimage();   //载入人物和目的地重合

//用结构体表示坐标
typedef struct pos
{
    int x;  //人物的x坐标
    int y;  //人物的y坐标
}POS,*LPPOS;

//画空地
void drawAir(int i,int j);

//画墙壁
void drawWall(int i,int j);

//画箱子的目的地
void drawDestination(int i,int j);

//画箱子
void drawBox(int i,int j);

//画人物
void drawPlayer(int i,int j);

//画箱子和人物重合
void drawDestination_Box(int i,int j);

//画人物和目的地重合
void drawDestination_Player(int i,int j);

//获取人物位置
LPPOS getPlayerPos(int map[LEVELS][10][12]);

//人物移动
void playerMove(LPSTACK stack);

//检测推箱子以及其他
void player_push_box(LPPOS playerPos,LPPOS playerNextPos,int map[LEVELS][10][12],LPSTACK stack);

//检测胜利
void win(LPSTACK stack,int map[LEVELS][10][12]);

//回退
void rollBack(LPSTACK stack,int map[LEVELS][10][12]);

//打印地图
void DrawMap();