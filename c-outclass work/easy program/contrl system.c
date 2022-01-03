#include <stdio.h>
#include <stdlib.h>

struct dataType
{
    int hash;
    char name[20];
    int chinese;
};

struct Node
{
    struct dataType data;
    struct Node *next;
};

//创建节点
struct Node *createNode(struct dataType data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//跳表
struct skipTable
{
    struct dataType data;
    struct skipTable *next;
    struct skipTable *Rnext;
};

//跳表结构描述
struct skipList
{
    struct skipTable *headNode;
    int size;   //跳表大小
    int divisor;    //分类
};

//创建跳表
struct skipList *createSkipTable(int divisor)
{
    struct skipList *list = (struct skipList*)malloc(sizeof(struct skipList));
    list->divisor = divisor;
    list->headNode = NULL;
    list->size = 0;
    return list;
}

void insertByHash(struct skipList *list,struct dataType data)
{
    //求出hash地址
    int dataHashPos = data.hash % list->divisor;
    //创建一个跳表节点
    struct skipTable *newSkipNode = (struct skipTable*)malloc(sizeof(struct skipTable));
    newSkipNode->next = NULL;
    newSkipNode->Rnext = NULL;
    newSkipNode->data = data;
    if (list->headNode == NULL)  //若链表为空,创建第一个节点
    {
        list->headNode = newSkipNode;
    }
    else    //链表至少有一个节点
    {
        struct skipTable *pFrountMove = list->headNode;
        struct skipTable *pMove = list->headNode->next;
        if (pMove == NULL)   //若只有一个节点
        {
            if (dataHashPos < pFrountMove->data.hash % list->divisor)    //hash值小于
            {
                pFrountMove->next = newSkipNode;
                newSkipNode->next = pMove;
                return;
            }
            else if (pFrountMove->data.hash % list->divisor == dataHashPos)     //hash冲突
            {
                struct skipTable *rMove = pFrountMove->Rnext;
                if (pFrountMove->Rnext == NULL)
                {
                    pFrountMove->Rnext = newSkipNode;
                    return;
                }
                else
                {
                    struct skipTable *rFrountMove = pFrountMove;
                    while(newSkipNode->data.hash < rMove->data.hash)
                        newSkipNode = newSkipNode->Rnext;
                    pFrountMove->Rnext = newSkipNode;
                    newSkipNode->Rnext = pMove;
                    return;
                }
            }
            else    //hash大于
            {
                pFrountMove->next = newSkipNode;
                return;
            }
        }
        else    //超过一个节点
        {
            //重置指针
            struct skipTable *pFrountMove = NULL;
            struct skipTable *pMove = list->headNode;
            if (dataHashPos < pMove->data.hash % list->divisor)   //判断第一个节点
            {
                list->headNode = newSkipNode;
                newSkipNode->next = pMove;
                return;
            }
            else if(dataHashPos == pMove->data.hash % list->divisor)
            {
                struct skipTable *rMove = pMove->Rnext;
                if (pMove->Rnext == NULL)
                {
                    pMove->Rnext = newSkipNode;
                    return;
                }
                else
                {
                    struct skipTable *rFrountMove = pFrountMove;
                    rMove = rMove->Rnext; 
                    while(rMove != NULL && data.hash < rMove->data.hash)
                        newSkipNode = newSkipNode->Rnext;
                    rFrountMove->Rnext = newSkipNode;
                    newSkipNode->Rnext = rMove;
                    return;
                }
            }
            else
            {
                pFrountMove = pMove;
                pMove = pMove->next;
                while (pMove != NULL)
                {
                    if (dataHashPos == pMove->data.hash % list->divisor)    //处理hash冲突
                    {
                        struct skipTable *rMove = pFrountMove->Rnext;
                        if (pFrountMove->Rnext == NULL)
                        {
                            pFrountMove->Rnext = newSkipNode;
                            return;
                        }
                        else
                        {
                            struct skipTable *rFrountMove = pFrountMove;
                            while(newSkipNode->data.hash < rMove->data.hash)
                                newSkipNode = newSkipNode->Rnext;
                            pFrountMove->Rnext = newSkipNode;
                            newSkipNode->Rnext = pMove;
                            return;
                        }
                    }
                    pFrountMove = pFrountMove->next;
                    pMove = pMove->next;
                }
                pFrountMove->next = newSkipNode;
                newSkipNode->next = pMove;
                return;
            }
        }
    }
}

//打印列表
void printList(struct skipList *list)
{
    if (list->headNode == NULL)
    {
        printf("链表为空无法打印");
        return;
    }
    struct skipTable *pMove = list->headNode;
    struct skipTable *rMove = list->headNode;
    while(pMove != NULL)
    {
        while(rMove != NULL)
        {
            printf("%d %s %d|",rMove->data.hash,rMove->data.name,rMove->data.chinese);
            rMove = rMove->Rnext;
        }
        printf("\n");
        pMove = pMove->next;
        rMove = pMove;
    }
}

int main()
{
    struct skipList *list = createSkipTable(10);
    struct dataType data1 = {5,"黄世标",99};
    insertByHash(list,data1);
    struct dataType data2 = {6,"黄达",98};
    insertByHash(list,data2);
    struct dataType data3 = {16,"姚勋文",100};
    insertByHash(list,data3);
    struct dataType data4 = {26,"张家瑞",95};
    insertByHash(list,data4);
    struct dataType data5 = {15,"周顺",97};
    insertByHash(list,data5);
    struct dataType data6 = {8,"钟晨",89};
    insertByHash(list,data6);
    struct dataType data7 = {7,"曾毅",80};
    insertByHash(list,data7);
    printList(list);
    system("pause");
    return 0;
}