/*
    ������Ȩͼ
    Ӣ�ĵ���
    ���� vextex
    Ȩֵ value
    ��   edge
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ȡ����
typedef char VextexType[4]; //��������
typedef int VLType;         //Ȩֵ����
#define MAX 10              //��󶥵���

//ͼ������
typedef struct graph
{
    int egdenum;                    //�ߵ�����
    int vexnum;                     //��������
    VextexType vextexArray[MAX];    //��һ������ȥ���涥��,ʵ����vextexArray[MAX][4]
    VLType VLArray[MAX][MAX];       //��һ����ά����ȥ�������бߵ�Ȩֵ
}GRAPH,*LPGRAPH;

//Ѱ�ҽ������λ��
int searchPos(LPGRAPH G,VextexType x)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (strcmp(G->vextexArray[i],x) == 0)
        {
            return i;
        }
    }
    return -1;
}

//ͼ�Ĵ���
LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));     //����һ���µ�ͼ
    printf("������ͼ�ı����Ͷ�����:");
    scanf("%d%d",&G->egdenum,&G->vexnum);             
    printf("������%d�����������\n",G->vexnum);
    //��ʼ����ά����
    memset(G->VLArray,0,sizeof(int) * MAX * MAX);
    //ѭ��ȥ��ȡ
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextexArray[i]);
    }
    //ѭ��ȥ���ӽ��
    printf("������%d���ߵ���Ϣ:\n",G->egdenum);
    VextexType V1,V2;   //�����������������
    VLType vrt;         //Ȩֵ����
    for (int i = 0; i < G->egdenum; i++)
    {
        scanf("%s%s%d",V1,V2,&vrt);
        int posV1 = searchPos(G,V1);
        int posV2 = searchPos(G,V2);
        G->VLArray[posV1][posV2] = vrt;
    }
    return G;
}

//ͼ�Ĵ�ӡ
void printGraph(LPGRAPH G)
{
    printf("  ");
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%s ",G->vextexArray[i]);
    }
    putchar('\n');
    for (int i = 0; i < G->vexnum; i++)
    {
        //��ӡ���
        printf("%s ",G->vextexArray[i]);
        for (int j = 0; j < G->vexnum; j++)
        {
            printf("%d ",G->VLArray[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    LPGRAPH G = createGraph();
    printGraph(G);
    system("pause");
    return 0;
}