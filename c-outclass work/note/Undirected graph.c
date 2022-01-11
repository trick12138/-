#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char VertexType[4];
#define MAX 10

//存放临接顶点的链表
typedef struct ArcNode
{
    int vexIndex;           //顶点在顶点数组的序号
    struct ArcNode* next;   //链表必备
}NODE,*LPNODE;

//创建结点为插入做准备
LPNODE createNode(int vexIndex)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->vexIndex = vexIndex;
    newNode->next = NULL;
    return newNode;
}

//无表头链表的表头法插入
void insertNodeByHead(LPNODE *headNode,int vexIndex)
{
    LPNODE newNode = createNode(vexIndex);
    newNode->next = *headNode;
    *headNode = newNode;
}

//图结构:数组  链表
//顶点信息描述
typedef struct VNode
{
    VertexType data;    //数据
    LPNODE firstNode;   //指针
}VNODE,ARRAY[MAX],*LPVNODE;

typedef struct GRAPH
{
    int arcnum;     //边数
    int vexnum;     //顶点数
    ARRAY vextex;   //数组
}GRAPH,*LPGRAPH;

int searchPos(LPGRAPH G,VertexType x)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (strcmp(G->vextex[i].data,x) == 0)
        {
            return i;
        }
        
    }
    return -1;
}

LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));
    printf("输入边数和顶点数:");
    scanf("%d%d",&G->arcnum,&G->vexnum);
    printf("请输入%d个顶点:\n",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextex[i].data);
        G->vextex[i].firstNode = NULL;  //指针的初始化
    }
    VertexType v1,v2;
    int posV1;
    int posV2;
    printf("请输入边的信息:\n");
    for (int i = 0; i < G->arcnum; i++)
    {
        scanf("%s%s",v1,v2);
        posV1 = searchPos(G,v1);
        posV2 = searchPos(G,v2);
        //涉及到链表操作
        //v1-v2
        insertNodeByHead(&G->vextex[posV1].firstNode,posV2);
        //v2-v1
        insertNodeByHead(&G->vextex[posV2].firstNode,posV2);
    }
    return G;
}

void printGraph(LPGRAPH G)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("%s-->",G->vextex[i].data);
        LPNODE pMove = G->vextex[i].firstNode;
        while (pMove)
        {
            printf("%s-->",G->vextex[pMove->vexIndex].data);
            pMove = pMove->next;
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