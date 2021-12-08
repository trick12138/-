#include <stdio.h>
#include <stdlib.h>
//使用二级指针的无头链表
//第一个节点存放了数据
struct Node
{
    int data;
    struct Node *next;
};

//创建节点
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

//表头法插入
void insertByHead(struct Node **list,int data)
{
    
}

int main()
{
    //创建链表
    struct Node *list = NULL;
    
    system("pause");
    return 0;
}