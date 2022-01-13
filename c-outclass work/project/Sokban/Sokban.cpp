#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "stack.c"
#define STEP 15

//ʹ�ö�ά�����ʾ��ͼ
//0:�յ�;   1:ǽ��  3:���ӵ�Ŀ�ĵ�; 4:����
//6:��  7:���Ӻ�Ŀ�ĵ��غ�;  9:��վ��Ŀ�ĵ�
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

//����UI
PIMAGE g_case = newimage();                 //����ǽ��ͼƬ
PIMAGE g_destination = newimage();          //����Ŀ�ĵ�ͼƬ
PIMAGE g_box = newimage();                  //��������ͼƬ
PIMAGE g_player = newimage();               //��������ͼƬ
PIMAGE g_destination_box = newimage();      //�������Ӻ�Ŀ�ĵ��غ�
PIMAGE g_player_destination = newimage();   //���������Ŀ�ĵ��غ�

//�ýṹ���ʾ����
typedef struct pos
{
    int x;  //�����x����
    int y;  //�����y����
}POS,*LPPOS;

//���յ�
void drawAir(int i,int j);

//��ǽ��
void drawWall(int i,int j);

//�����ӵ�Ŀ�ĵ�
void drawDestination(int i,int j);

//������
void drawBox(int i,int j);

//������
void drawPlayer(int i,int j);

//�����Ӻ������غ�
void drawDestination_Box(int i,int j);

//�������Ŀ�ĵ��غ�
void drawDestination_Player(int i,int j);

//��ȡ����λ��
LPPOS getPlayerPos(int map[10][12]);

//�����ƶ�
void playerMove(LPSTACK stack);

//����������Լ�����
void player_push_box(LPPOS playerPos,LPPOS playerNextPos,int map[10][12],LPSTACK stack);

//���ʤ��
void win(int map[10][12]);

//����
void rollBack(LPSTACK stack,int map[10][12]);

//��ӡ��ͼ
void DrawMap();

//������
int main()
{
    FreeConsole();                  //�رտ���̨
    initgraph(576,480);             //���ô��ڴ�С   ÿһ������Ϊ48�����ش�С
    setbkcolor(WHITE);              //���ñ���
    setbkmode(TRANSPARENT);         //�������ֱ���Ϊ͸��
    setfont(12, 0, "����");         //�������ִ�С������
    setcaption("������");           //���ñ���
    LPSTACK stack = createStack(); //����ջ
    //������
    for (;is_run;delay_fps(60))
    {
        DrawMap();                  //���Ƶ�ͼ
        playerMove(stack);          //�����ƶ�
        win(g_map);                 //���ʤ��
    }
    return 0;
}

//��ӡ��ͼ
void DrawMap()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            switch (g_map[i][j])
            {
            case 0: drawAir(i,j);               //���ƿ���
                break;
            case 1: drawWall(i,j);              //����ǽ��
                break;
            case 3: drawDestination(i,j);       //����Ŀ�ĵ�
                break;
            case 4: drawBox(i,j);               //��������
                break;
            case 6: drawPlayer(i,j);            //��������
                break;
            case 7: drawDestination_Box(i,j);   //�������Ӻ�Ŀ�ĵ��غ�
                break;
            case 9: drawDestination_Player(i,j);//���������Ŀ�ĵ��غ�
                break;
            default:
                break;
            }
        }
    }
}

//������
void drawAir(int i,int j)
{
    setfillcolor(WHITE);        //���û�ͼ��ɫ
    int left = j == 0? 0 : j * 48 - 1;
    int top = i == 0? 0 : i * 48 - 1;
    int right = left + 48;
    int bottom = top + 48;
    bar(left,top,right,bottom);
}

//��ǽ��
void drawWall(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_case,"./Sokban������ͼ/case.png");
    putimage(posX,posY,g_case);
}

//�����ӵ�Ŀ�ĵ�
void drawDestination(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_destination,"./Sokban������ͼ/destination.png");
    putimage(posX,posY,g_destination);
}

//������
void drawBox(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_box,"./Sokban������ͼ/box.png");
    putimage(posX,posY,g_box);
}

//������
void drawPlayer(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_player,"./Sokban������ͼ/player.png");
    putimage(posX,posY,g_player);
}

//�����Ӻ������غ�
void drawDestination_Box(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_destination_box,"./Sokban������ͼ/destination-box.png");
    putimage(posX,posY,g_destination_box);
}

//�������Ŀ�ĵ��غ�
void drawDestination_Player(int i,int j)
{
    //����������Ƶ�λ����������Ƶ����Ͻ�
    int posX = j * 48 - 1;
    int posY = i * 48 - 1;
    getimage(g_player_destination,"./Sokban������ͼ/player_destination.png");
    putimage(posX,posY,g_player_destination);
}

//��ȡ����λ��
LPPOS getPlayerPos(int map[10][12])
{
    LPPOS playPos = (LPPOS)malloc(sizeof(POS));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (map[i][j] == 6 || map[i][j] == 9)
            {
                playPos->x = j;
                playPos->y = i;
                return playPos;
            }
        }
    }
    return NULL;
}

//����λ��
LPPOS createPlayerPos(int y,int x)
{
    LPPOS newPos = (LPPOS)malloc(sizeof(POS));
    newPos->x = x;
    newPos->y = y;
    return newPos;
}

//������
void player_up(LPPOS playerPos,int map[10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y - 1,playerPos->x);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//������
void player_left(LPPOS playerPos,int map[10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y,playerPos->x - 1);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//������
void player_right(LPPOS playerPos,int map[10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y,playerPos->x + 1);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//������
void player_down(LPPOS playerPos,int map[10][12],LPSTACK stack)
{
    LPPOS playerNextPos = createPlayerPos(playerPos->y + 1,playerPos->x);
    player_push_box(playerPos,playerNextPos,map,stack);
}

//����������Լ�����
void player_push_box(LPPOS playerPos,LPPOS playerNextPos,int map[10][12],LPSTACK stack)
{
    int tPosX = playerNextPos->x - playerPos->x;
    int tPosY = playerNextPos->y - playerPos->y;
    //������߹���λ����ջ
    DATA posData[3];
    for (int i = 0; i < 3; i++)
    {
        posData[i].x = playerPos->x + tPosX * i;
        posData[i].y = playerPos->y + tPosY * i;
        posData[i].data = map[playerPos->y + tPosY * i][playerPos->x + tPosX * i];
    }
    push(stack,posData);
    //�����ƶ�������
    if (map[playerPos->y + tPosY][playerPos->x + tPosX] == 0 && map[playerPos->y][playerPos->x] == 6)
    {
        map[playerPos->y][playerPos->x] = 0;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 6;
    }
    //�������������
    if (map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 0 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 4)
    {
        map[playerPos->y][playerPos->x] = 0;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 4;
    }
    //����������Ŀ�ĵ�
    if (map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 4)
    {
        map[playerPos->y][playerPos->x] = 0;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 6;
        map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //�������ӽ�Ŀ�ĵ����˽�Ŀ�ĵ������ڿ���
    if (map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[playerPos->y][playerPos->x] == 6)
    {
        map[playerPos->y][playerPos->x] = 0;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //�������ӽ�Ŀ�ĵ����˽�Ŀ�ĵ�������Ŀ�ĵ�
    if (map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] == 3 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 7 && map[playerPos->y][playerPos->x] == 9)
    {
        map[playerPos->y][playerPos->x] = 3;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[playerPos->y + 2 * tPosY][playerPos->x + 2 * tPosX] = 7;
    }
    //�˽�Ŀ�ĵ�
    if (map[playerPos->y][playerPos->x] == 6 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 3)
    {
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 9;
        map[playerPos->y][playerPos->x] = 0;
    }
    //�˴�Ŀ�ĵ������
    if (map[playerPos->y][playerPos->x] == 9 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 0)
    {
        map[playerPos->y][playerPos->x] = 3;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 6;
    }
    //����Ŀ�ĵ��ƶ�
    if (map[playerPos->y][playerPos->x] == 9 && map[playerPos->y + tPosY][playerPos->x + tPosX] == 3)
    {
        map[playerPos->y][playerPos->x] = 3;
        map[playerPos->y + tPosY][playerPos->x + tPosX] = 9;
    }
    //������λ�õĻ���
    free(playerPos);
    free(playerNextPos);
    playerPos = NULL;
    playerNextPos = NULL;
}

//�����ƶ�
void playerMove(LPSTACK stack)
{
    LPPOS playerPos = getPlayerPos(g_map);
    char key_down = getch();
    switch (key_down)
    {
    case 'w': player_up(playerPos,g_map,stack);
        break;
    case 'a': player_left(playerPos,g_map,stack);
        break;
    case 'd': player_right(playerPos,g_map,stack);
        break;
    case 's': player_down(playerPos,g_map,stack);
        break;
    case 'b': rollBack(stack,g_map);
        break;
    default:
        break;
    }
}

//����
void rollBack(LPSTACK stack,int map[10][12])
{
    //��ȫ�Կ���
    if (stack->headSPOS == NULL)
        return;
    //���λ�ûص���һ��
    for (int i = 0; i < 3; i++)
    {
        map[stack->headSPOS->data[i].y][stack->headSPOS->data[i].x] = stack->headSPOS->data[i].data;
    }
    //��ջ
    pop(stack);
}

//���ʤ��
void win(int map[10][12])
{
    if (map[3][10] == 7 && map[4][10] == 7 && map[5][10] == 7)
    {
        DrawMap();                  //���Ƶ�ͼ
        Sleep(3*1000);
        exit(0);
    }
}