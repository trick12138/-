#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

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

//��ӡ��ͼ
void DrawMap();

int main()
{
    //���ô��ڴ�С
    initgraph(250,300);
    //������
    while (1)
    {

        system("pause");
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
            case 0: printf("  ");
                break;
            case 1: printf("��");
                break;
            case 3: printf("��");
                break;
            case 4: printf("@");
                break;
            case 6: printf("��");
                break;
            case 7: printf("��");
                break;
            case 9: printf("��");
                break;
            default:
                break;
            }
        }
        
    }
    
}