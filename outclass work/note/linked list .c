#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct node *next;
};
//有头链表，表头不存放数据去操作
//表头就是结构体变量
struct Node *createList()
{
    //动态内存申请
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //表头不存放数据去操作
    headNode -> next = NULL;
    return headNode;
};

int main()
{
/*     //静态链式结构
    struct node node1 = {1,NULL};
    struct node node2 = {2,NULL};
    struct node node3 = {3,NULL};
    node1.next = &node2;
    node2.next = &node3; */
    //单链表

    system("pause");
    return 0;
}