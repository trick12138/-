#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char VertexType[4];
#define MAX 10

//����ٽӶ��������
typedef struct ArcNode
{
    int vexIndex;           //�����ڶ�����������
    struct ArcNode* next;   //����ر�
}NODE,*LPNODE;

//�������Ϊ������׼��
LPNODE createNode(int vexIndex)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->vexIndex = vexIndex;
    newNode->next = NULL;
    return newNode;
}

//�ޱ�ͷ����ı�ͷ������
void insertNodeByHead(LPNODE *headNode,int vexIndex)
{
    LPNODE newNode = createNode(vexIndex);
    newNode->next = *headNode;
    *headNode = newNode;
}

//ͼ�ṹ:����  ����
//������Ϣ����
typedef struct VNode
{
    VertexType data;    //����
    LPNODE firstNode;   //ָ��
}VNODE,ARRAY[MAX],*LPVNODE;

typedef struct GRAPH
{
    int arcnum;     //����
    int vexnum;     //������
    ARRAY vextex;   //����
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
    printf("��������Ͷ�����:");
    scanf("%d%d",&G->arcnum,&G->vexnum);
    printf("������%d������:\n",G->vexnum);
    for (int i = 0; i < G->vexnum; i++)
    {
        scanf("%s",G->vextex[i].data);
        G->vextex[i].firstNode = NULL;  //ָ��ĳ�ʼ��
    }
    VertexType v1,v2;
    int posV1;
    int posV2;
    printf("������ߵ���Ϣ:\n");
    for (int i = 0; i < G->arcnum; i++)
    {
        scanf("%s%s",v1,v2);
        posV1 = searchPos(G,v1);
        posV2 = searchPos(G,v2);
        //�漰���������
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