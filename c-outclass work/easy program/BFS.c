#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  //����ͼ����󴢴�����
typedef char vertexType[4];  //��������

//����ٽӶ���Ľṹ��
typedef struct ArNode
{
    int vexIndex;
    struct ArNode *next;
}NODE,*LPNODE;

//������Ϣ����
typedef struct VNode
{
    vertexType data;
    LPNODE firstNode;
}VNODE,*LPVNOED,ARRAY[MAX];

//ͼ������
typedef struct graph
{
    int arcnum;     //��������
    int vexnum;     //�ߵ�����
    ARRAY vextex;   //ͼ�����ݴ��
}GRAPH,*LPGRAPH;

//��װһ�������ڽӶ���ĺ���
LPNODE createNode(int vexIndex)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->vexIndex = vexIndex;
    return newNode;
}

//��װһ��Ѱ�Ҷ���λ�õĺ���
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

//��ͷ�����ͷ�巨ȥ�����ٽ綥��
void insertByHead(LPNODE *headNode,int vexIndex)       //����ֻ��¼�±�,��ʡ�ڴ�
{
    LPNODE newNode = createNode(vexIndex);
    newNode->next = *headNode;
    *headNode = newNode;
}

//������Ȩͼ�Ĵ���
LPGRAPH createGraph()
{
    LPGRAPH G = (LPGRAPH)malloc(sizeof(GRAPH));
    printf("�����붥��ͱߵ�����:");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("������%d����������:\n",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextex[i].data);
        G->vextex[i].firstNode = NULL;
    }
    printf("������ߵ���Ϣ:\n");
    vertexType v1,v2;   //�����ʱ������Ϣ
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

//��ӡ����
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
    //���ʱ��
    int visited[MAX] = { 0 };
    //������Ҫ��
    int queue[MAX];
    int front = -1;
    int tail = -1;
    //ѡ��һ�����
    visitVextex(G->vextex[inPos].data);
    //���ʱ��
    visited[inPos] = 1;
    LPNODE pMove = NULL;
    //��ѡ����Ԫ�����
    queue[++tail] = inPos;
    while (front < tail)
    {
        //����
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