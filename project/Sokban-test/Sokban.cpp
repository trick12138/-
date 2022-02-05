#include "headfile/Sokban.h"

//主程序
int main()
{
    FreeConsole();                  //关闭控制台
    initgraph(576,480);             //设置窗口大小   每一个格子为48个像素大小
    setbkcolor(WHITE);              //设置背景
    setbkmode(TRANSPARENT);         //设置文字背景为透明
    setfont(12, 0, "楷体");         //设置文字大小和字体
    setcaption("推箱子");           //设置标题
    LPSTACK stack = createStack(); //创建栈
    //主程序
    for (;is_run;delay_fps(60))
    {
        DrawMap();                  //绘制地图
        playerMove(stack);          //人物移动
        win(stack,g_map);                 //检测胜利
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
            switch (g_map[LEVEL][i][j])
            {
            case 0: drawAir(i,j);               //绘制空气
                break;
            case 1: drawWall(i,j);              //绘制墙壁
                break;
            case 3: drawDestination(i,j);       //绘制目的地
                break;
            case 4: drawBox(i,j);               //绘制箱子
                break;
            case 6: drawPlayer(i,j);            //绘制人物
                break;
            case 7: drawDestination_Box(i,j);   //绘制箱子和目的地重合
                break;
            case 9: drawDestination_Player(i,j);//绘制人物和目的地重合
                break;
            default:
                break;
            }
        }
    }
}

//画空气
void drawAir(int i,int j)
{
    setfillcolor(WHITE);        //设置绘图颜色
    int left = j == 0? 0 : j * 48 - 1;
    int top = i == 0? 0 : i * 48 - 1;
    int right = left + 48;
    int bottom = top + 48;
    bar(left,top,right,bottom);
}

//画墙壁
void drawWall(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_case,"./Sokban辅助绘图/case.png");
    putimage(posX,posY,g_case);
}

//画箱子的目的地
void drawDestination(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_destination,"./Sokban辅助绘图/destination.png");
    putimage(posX,posY,g_destination);
}

//画箱子
void drawBox(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_box,"./Sokban辅助绘图/box.png");
    putimage(posX,posY,g_box);
}

//画人物
void drawPlayer(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_player,"./Sokban辅助绘图/player.png");
    putimage(posX,posY,g_player);
}

//画箱子和人物重合
void drawDestination_Box(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_destination_box,"./Sokban辅助绘图/destination-box.png");
    putimage(posX,posY,g_destination_box);
}

//画人物和目的地重合
void drawDestination_Player(int i,int j)
{
    //计算所需绘制的位置在所需绘制的左上角
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_player_destination,"./Sokban辅助绘图/player_destination.png");
    putimage(posX,posY,g_player_destination);
}

//获取人物位置
LPPOS getPlayerPos(int map[LEVELS][10][12])
{
    LPPOS playPos = (LPPOS)malloc(sizeof(POS));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (map[LEVEL][i][j] == 6 || map[LEVEL][i][j] == 9)
            {
                playPos->x = j;
                playPos->y = i;
                return playPos;
            }
        }
    }
    return NULL;
}

//创建位置
LPPOS createPlayerPos(int y,int x)
{
    LPPOS newPos = (LPPOS)malloc(sizeof(POS));
    newPos->x = x;
    newPos->y = y;
    return newPos;
}

//向上走
void player_up(LPPOS playerPos,int map[LEVELS][10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y - 1,playerPos->x);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//向左走
void player_left(LPPOS playerPos,int map[LEVELS][10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y,playerPos->x - 1);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//向右走
void player_right(LPPOS playerPos,int map[LEVELS][10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y,playerPos->x + 1);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//向下走
void player_down(LPPOS playerPos,int map[LEVELS][10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y + 1,playerPos->x);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//检测推箱子以及其他
void player_push_box(LPPOS playerPos,LPPOS playerNextPos,int map[LEVELS][10][12],LPSTACK stack)
{
    int tPosX = playerNextPos->x - playerPos->x;
    int tPosY = playerNextPos->y - playerPos->y;
    //将玩家走过的位置入栈
    DATA posData[3];
    for (int i = 0; i < 3; i++)
    {
        posData[i].x = playerPos->x + tPosX * i;
        posData[i].y = playerPos->y + tPosY * i;
        posData[i].data = map[LEVEL][playerPos->y + tPosY * i][playerPos->x + tPosX * i];
    }
    push(stack,posData);
    //把人移动到空气
    if (map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 0 && map[LEVEL][playerPos->y][playerPos->x] == 6)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 0;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
    }
    //人进目的地
    if (map[LEVEL][playerPos->y][playerPos->x] == 6 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 3)
    {
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[LEVEL][playerPos->y][playerPos->x] = 0;
    }
    //人从目的地里出来
    if (map[LEVEL][playerPos->y][playerPos->x] == 9 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 0)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
    }
    //人在空气把箱子推向空气
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 0 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 4 && map[LEVEL][playerPos->y][playerPos->x] == 6)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 0;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 4;
    }
    //人在空气把箱子送入目的地
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 4 && map[LEVEL][playerPos->y][playerPos->x] == 6)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 0;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //人在目的地把箱子推向空气
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 0 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 4 && map[LEVEL][playerPos->y][playerPos->x] == 9)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 4;
    }
    //人在目的地把箱子送入目的地
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 4 && map[LEVEL][playerPos->y][playerPos->x] == 9)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //人送箱子进目的地且人进目的地且人在空气且箱子在目的地
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[LEVEL][playerPos->y][playerPos->x] == 6)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 0;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //人送箱子进目的地且人进目的地且人在目的地且箱子在目的地
    if (map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[LEVEL][playerPos->y][playerPos->x] == 9)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //人在目的地移动
    if (map[LEVEL][playerPos->y][playerPos->x] == 9 && map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 3)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
    }
    //人在空气把箱子从目的地推出来
    if (map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 0 && map[LEVEL][playerPos->y][playerPos->x] == 6)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 0;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 4;
    }
    //人在目的地把箱子从目的地推出来
    if (map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 0 && map[LEVEL][playerPos->y][playerPos->x] == 9)
    {
        map[LEVEL][playerPos->y][playerPos->x] = 3;
        map[LEVEL][playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[LEVEL][playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 4;
    }
    //清空玩家位置的缓存
    free(playerPos);
    free(playerNextPos);
    playerPos = NULL;
    playerNextPos = NULL;
}

//重置本关
void restartLEVEL(LPSTACK stack)
{
    while (stack->headSPOS != NULL)  //将记录的步数全部出栈
    {
        //玩家位置回到上一步
        for (int i = 0; i < 3; i++)
        {
            g_map[LEVEL][stack->headSPOS->data[i].y][stack->headSPOS->data[i].x] = stack->headSPOS->data[i].data;
        }
        //出栈
        pop(stack);
    }
}

//人物移动
void playerMove(LPSTACK stack)
{
    LPPOS playerPos = getPlayerPos(g_map);
    char key = getch();
    switch (key)
    {
    case 'w': case 'W': case key_up:
        player_up(playerPos,g_map,stack);
        break;
    case 'a': case 'A': case key_left:
        player_left(playerPos,g_map,stack);
        break;
    case 'd': case 'D': case key_right:
        player_right(playerPos,g_map,stack);
        break;
    case 's': case 'S': case key_down:
        player_down(playerPos,g_map,stack);
        break;
    case 'b':
        rollBack(stack,g_map);
        break;
    case 'r':
        restartLEVEL(stack);
        break;
    default:
        break;
    }
    
}

//回退
void rollBack(LPSTACK stack,int map[LEVELS][10][12])
{
    //安全性考虑
    if (stack->headSPOS == NULL)
        return;
    //玩家位置回到上一步
    for (int i = 0; i < 3; i++)
    {
        map[LEVEL][stack->headSPOS->data[i].y][stack->headSPOS->data[i].x] = stack->headSPOS->data[i].data;
    }
    //出栈
    pop(stack);
}

//检测胜利
void win(LPSTACK stack,int map[LEVELS][10][12])
{
    //获取箱子目的地数量
    int destination = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[LEVEL][i][j] == 3 || map[LEVEL][i][j] == 9)
            {
                destination++;
            }
        }
    }
    //全部推进去就是赢了
    if (destination == 0)
    {
        DrawMap();      //绘制地图
        Sleep(1*1000);  //等待
        LEVEL++;        //进入下一关
        while(stack->headSPOS != NULL)  //将记录的步数全部出栈
        {
            pop(stack);
        }
    }
    if (LEVEL == LEVELS)
        exit(0);
}