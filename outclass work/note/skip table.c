#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataType
{
    int first;
    int second[20];
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

struct skipListNode
{
    struct dataType data;   //数据
    struct Node *firstNode;     //储存hash冲突元素
    struct skipListNode *next;  //指向下一个
};

struct skipListNode *createSkipListNode(struct dataType data)
{
    struct skipListNode *newNode = (struct skipListNode*)malloc(sizeof(struct skipListNode));
    newNode->data = data;
    newNode->firstNode = NULL;
    newNode->next = NULL;
    return NULL;
}

//跳表结构描述
struct skipList
{
    struct skipListNode *headNode;  //表示整个调表结构
    int sizeSkip;
    int divisor;
};

//创建跳表
//value%divisor
struct skipList *createSkipList(int divisor)
{
    struct skipList *list = (struct skipList*)malloc(sizeof(struct skipList));
    list->headNode = NULL;
    list->divisor = 0;
    list->divisor = divisor;
    return list;
}

//插入
void insertNodeBySort(struct skipList *list,struct dataType data)
{
    //通过取余法求出hash地址
    int dataHashPos = data.first % list->divisor;
    struct skipListNode *newSkipNode = createSkipListNode(data);
    if (list->headNode == NULL)
    {
        list->headNode == newSkipNode;
        list->sizeSkip++;
    }
    else    //有元素的时候就要做一个有序链表
    {
        //链表的指针位置插入
        struct skipListNode *pMove = list->headNode;
        struct skipListNode *pMoveFrount = NULL;    //记录
        
    }
}

int main()
{


    return 0;
}