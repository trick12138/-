/*
    有项有权图
    英文单词
    顶点 vextex
    权值 value
    边   edge
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//取别名
typedef char VextexType[4]; //顶点名称
typedef int VLType;         //权值类型
#define MAX 10              //最大顶点数

//图的描述
typedef struct graph
{
    int egdenum;                    //边的数量
    int vexnum;                     //顶点数量
    VextexType vextexArray[MAX];    //用一个数组去储存顶点,实际是vextexArray[MAX][4]
    VLType VLArray[MAX][MAX];       //用一个二维数组去储存所有边的权值
}GRAPH,*LPGRAPH;

//寻找结点所在位置
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

//图的创建
LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));     //创建一个新的图
    printf("请输入图的边数和顶点数:");
    scanf("%d%d",&G->egdenum,&G->vexnum);             
    printf("请输入%d个顶点的名称\n",G->vexnum);
    //初始化二维数组
    memset(G->VLArray,0,sizeof(int) * MAX * MAX);
    //循环去读取
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextexArray[i]);
    }
    //循环去连接结点
    printf("请输入%d条边的信息:\n",G->egdenum);
    VextexType V1,V2;   //储存两个结点做连接
    VLType vrt;         //权值储存
    for (int i = 0; i < G->egdenum; i++)
    {
        scanf("%s%s%d",V1,V2,&vrt);
        int posV1 = searchPos(G,V1);
        int posV2 = searchPos(G,V2);
        G->VLArray[posV1][posV2] = vrt;
    }
    return G;
}

//图的打印
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
        //打印结点
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