#include <stdio.h>
#include <stdlib.h>
//链表
struct Node
{
    int data;//数据域
    struct Node *next;//指针域
};

//创建表头
struct Node *createNodeHead()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));//动态内存申请
    headNode->next = NULL;//表头指针
    return headNode;//返回表头地址
}

//创建节点
struct Node *createPosNode(int data)
{
    struct Node *posNode = (struct Node*)malloc(sizeof(struct Node));
    posNode->data = data;
    posNode->next = NULL;
    return posNode;
}

//插入节点
void insertByHead(struct Node *headNode,int data)
{
    //创建节点
    struct Node *newNode = createPosNode(data);
    newNode->data = data;
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//打印数据
void printList(struct Node *headNode)
{
    struct Node *pMove = headNode->next;
    while(pMove != NULL)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->next;
    }
}
struct Node List;
int main()
{
    struct Node *List = createNodeHead();
    insertByHead(List,1);
    insertByHead(List,2);
    insertByHead(List,3);
    printList(List);
}