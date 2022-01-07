/*
    带权图:矩阵法
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char VertexType[4]; //顶点类型
typedef int VRType;         //权值类型
#define MAX 10              //最大顶点数
typedef struct graph
{
    int arcnum;             //边的数目
    int vexnum;             //顶点数
    VertexType vextex[MAX]; //二维数组  vextex[MAX][4]
    VRType matrix[MAX][MAX];//所有存在的边的权值
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
    printf("请输入边数和顶点数:");
    scanf("%d%d",&G->arcnum,&G->vexnum);
    printf("请输入%d个顶点",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        //每一行都是一个字符串
        scanf("%s",G->vextex[i]);
    }
    //初始化权值数组
    memset(G->matrix,0,sizeof(int) * (MAX * MAX));
    //两点确定一条边
    printf("请输入%d条边的信息:\n",G->arcnum);
    VertexType v1,v2;
    VRType vrt;
    for (int i = 0; i < G->arcnum; i++)
    {
        scanf("%s%s%d",v1,v2,&vrt);
        //在权值数组去定位
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
        //每一行的起始位置打印顶点
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