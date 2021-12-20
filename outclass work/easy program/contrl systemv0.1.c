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

void insertByHash(struct skipList *list,struct dataType data)
{
    
}

int main()
{



    system("pause");
    return 0;
}