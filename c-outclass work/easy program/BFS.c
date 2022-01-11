#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  //定义图的最大储存数量
typedef char vertexType[4];  //顶角类型

//存放临接顶点的结构体
typedef struct ArNode
{
    int vexIndex;
    struct ArNode *next;
}NODE,*LPNODE;

//顶点信息描述
typedef struct VNode
{
    vertexType data;
    LPNODE firstNode;
}VNODE,*LPVNOED,ARRAY[MAX];

//图的描述
typedef struct graph
{
    int arcnum;     //顶点数量
    int vexnum;     //边的数量
    ARRAY vextex;   //图的数据存放
}GRAPH,*LPGRAPH;

//封装一个创建邻接顶点的函数
LPNODE createNode(int vexIndex)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->vexIndex = vexIndex;
    return newNode;
}

//封装一个寻找顶点位置的函数
int scearchPos(LPGRAPH G,vertexType x)
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

//无头链表的头插法去插入临界顶点
void insertByHead(LPNODE *headNode,int vexIndex)       //这里只记录下标,节省内存
{
    LPNODE newNode = createNode(vexIndex);
    newNode->next = *headNode;
    *headNode = newNode;
}

//无向无权图的创建
LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));
    printf("请输入顶点和边的数量:");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("请输入%d个顶点类型:\n",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextex[i].data);
        G->vextex[i].firstNode = NULL;
    }
    printf("请输入边的信息:\n");
    vertexType v1,v2;   //存放临时顶点信息
    for (int i = 0; i < G->arcnum; i++)
    {
        scanf("%s%s",v1,v2);
        int posV1 = scearchPos(G,v1);
        int posV2 = scearchPos(G,v2);
        insertByHead(&G->vextex[posV1].firstNode,posV2);
        insertByHead(&G->vextex[posV2].firstNode,posV1);
    }
    return G;
}

//打印测试
void printGraph(LPGRAPH G)
{
    LPNODE pMove = NULL;
    for (int i = 0; i < G->vexnum; i++)
    {
        pMove = G->vextex[i].firstNode;
        printf("%s-->",G->vextex[i].data);
        while (pMove)
        {
            printf("%s-->",G->vextex[pMove->vexIndex].data);
            pMove = pMove->next;
        }
        putchar('\n');
    }
}
void visitVextex(vertexType x)
{
    printf("%s-->",x);
}

void BFSTravels(LPGRAPH G,int inPos)
{
    //访问标记
    int visited[MAX] = { 0 };
    //队列三要素
    int queue[MAX];
    int front = -1;
    int tail = -1;
    //选定一个入口
    visitVextex(G->vextex[inPos].data);
    //访问标记
    visited[inPos] = 1;
    LPNODE pMove = NULL;
    //把选定的元素入队
    queue[++tail] = inPos;
    while (front < tail)
    {
        //出队
        inPos = queue[++front];
        pMove = G->vextex[inPos].firstNode;
        while (pMove)
        {
            if (visited[pMove->vexIndex] == 0)
            {
                visitVextex(G->vextex[pMove->vexIndex].data);
                visited[pMove->vexIndex] = 1;
                queue[++tail] = pMove->vexIndex;
            }
            pMove = pMove->next;
        }
        
    }
    
}

int main()
{
    LPGRAPH G = createGraph();
    BFSTravels(G,0);
    putchar('\n');
    system("pause");
    return 0;
}