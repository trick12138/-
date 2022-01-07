/*
    ��Ȩͼ:����
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char VertexType[4]; //��������
typedef int VRType;         //Ȩֵ����
#define MAX 10              //��󶥵���
typedef struct graph
{
    int arcnum;             //�ߵ���Ŀ
    int vexnum;             //������
    VertexType vextex[MAX]; //��ά����  vextex[MAX][4]
    VRType matrix[MAX][MAX];//���д��ڵıߵ�Ȩֵ
}GRAPH,*LPGRAPH;

int searchPos(LPGRAPH G, VertexType x)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (strcmp(G->vextex[i],x) == 0)
        {
            return i;
        }
    }
    return -1;
}

LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));
    printf("����������Ͷ�����:");
    scanf("%d%d",&G->arcnum,&G->vexnum);
    printf("������%d������",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        //ÿһ�ж���һ���ַ���
        scanf("%s",G->vextex[i]);
    }
    //��ʼ��Ȩֵ����
    memset(G->matrix,0,sizeof(int) * (MAX * MAX));
    //����ȷ��һ����
    printf("������%d���ߵ���Ϣ:\n",G->arcnum);
    VertexType v1,v2;
    VRType vrt;
    for (int i = 0; i < G->arcnum; i++)
    {
        scanf("%s%s%d",v1,v2,&vrt);
        //��Ȩֵ����ȥ��λ
        int posV1 = searchPos(G,v1);
        int posV2 = searchPos(G,v2);
        G->matrix[posV1][posV2] = vrt;
    }
    return G;
}

void printGraph(LPGRAPH G)
{
    //  A   B   C   D
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("\t%s",G->vextex[i]);
    }
    putchar('\n');
    for (int i = 0; i < G->vexnum; i++)
    {
        //ÿһ�е���ʼλ�ô�ӡ����
        printf("%s\t",G->vextex[i]);
        for (int j = 0; j < G->vexnum; j++)
        {
            printf("%d\t",G->matrix[i][j]);
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