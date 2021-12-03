#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
//有头链表，表头不存放数据去操作
//表头就是结构体变量
struct Node *createList()
{
    //动态内存申请
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    //表头不存放数据去操作
    headNode -> next = NULL;
    return headNode;
}

//创建节点:为插入做准备
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

//表头法插入
void insertByhead(struct Node *headNode,int data)
{
    //插入前先创建插入的节点
    struct Node *newNode = createNode(data);
    newNode -> next = headNode -> next;
    headNode -> next = newNode;
}

//表尾法插入
void insertByTail(struct Node *headNode,int data)
{
    struct Node *newNode = createNode(data);
    struct Node *tailNode = headNode;
    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }
    tailNode->next = newNode;
}

//指定位置插入
//struct Node *headNode 操作的是哪个链表
//int data              新节点数据
//int posData           指定位置
void insertByAppoin(struct Node *headNode,int data,int posData)
{
    struct Node *posFrontNode = headNode;
    struct Node *posNode = headNode->next;
    //移动的节点不为NULL,并且当前节点中的元素不等于查找的元素
    while(posNode != NULL&&posNode->data != posData)
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
    }
    //分析posNode的状态
    if (posNode == NULL)
    {
        printf("没找到指定位置\n");
    }
    else
    {
        struct Node *newNode = createNode(data);
        posFrontNode->next = newNode;
        newNode->next = posNode;
    }

}

//表头法删除
void deleteNodeByHead(struct Node *headNode)
{
    struct Node *nextNode = headNode ->next;
    if (nextNode == NULL)
    {
        printf("链表为NULL,无法删除");
        return;
    }
    
    headNode->next = nextNode ->next;
    free(nextNode);
    nextNode = NULL;
}

//表尾法删除
void deleteNodeByTail(struct Node *headNode)
{
    struct Node *tailNode = headNode->next;//尾节点
    struct Node *tailFrontNode = headNode;//尾节点前一个节点
    if(tailNode == NULL)
    {
        printf("链表为NULL,无法删除");
        return;
    }
    while (tailNode->next != NULL)
    {
        tailFrontNode = tailNode;
        tailNode = tailFrontNode->next;
    }
    tailFrontNode->next = NULL;
    free(tailNode);
    tailNode = NULL;
}

//指定位置删除
void deleteByAppoin(struct Node *headNode,int posData)
{
    struct Node *posFrontNode = headNode;
    struct Node *posNode = headNode->next;
    //移动的节点不为NULL,并且当前节点中的元素不等于查找的元素
    while(posNode != NULL&&posNode->data != posData)
    {
        posFrontNode = posNode;
        posNode = posFrontNode->next;
    }
    //分析posNode的状态
    if (posNode == NULL)
    {
        printf("无法删除\n");
    }
    else
    {
        posFrontNode->next = posNode->next;
        free(posNode);
        posNode = NULL;
    }
}
//打印链表
void printList(struct Node *headNode)
{
    //有表头链表,所以从第二个节点开始打印
    struct Node *pMove = headNode->next;//从第二个节点开始打印
    while(pMove != NULL)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}
int main()
{
/*     //静态链式结构
    struct Node node1 = {1,NULL};
    struct Node node2 = {2,NULL};
    struct Node node3 = {3,NULL};
    Node1.next = &Node2;
    Node2.next = &Node3; */
    //单链表
    struct Node *List = createList();//链表创建
    //测试表头法循环插入
    for (int i = 0; i < 10; i++)
    {
        insertByhead(List,i);
    }
    printList(List);
    //测试表尾法插入
    insertByTail(List,-1);
    printList(List);
    //测试任意位置插入
    insertByAppoin(List,-100,-1);
    printList(List);
    //测试表头法删除
    deleteNodeByHead(List);
    printList(List);
    //表尾法删除
    deleteNodeByTail(List);
    printList(List);
    //指定位置删除
    deleteByAppoin(List,4);
    printList(List);
    //结束
    system("pause");
    return 0;
}