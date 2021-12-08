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
    struct Node *newNode = createNode(data);
    newNode->next = (*list);
    (*list) = newNode;
}

//打印
void printList(struct Node *list)
{
    struct Node *pMove = list;
    while(pMove != NULL)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

//指定位置插入
void insertByAppoin(struct Node **list,int cmpdata,int data)
{
    struct Node *frountNode = (*list);
    struct Node *posNode = (*list)->next;
    while (posNode != NULL && posNode->data != cmpdata)
    {
        frountNode = frountNode->next;
        posNode = posNode->next;
    }
    //判断是否找到
    if (posNode == NULL)
    {
        printf("未找到指定数据,或者你寻找的数据在表头,请用表头法插入");
    }
    else
    {
        struct Node *newNode = createNode(data);
        frountNode->next = newNode;
        newNode->next = posNode;
    }
}

int main()
{
    //创建链表
    struct Node *list = NULL;
    //test
    insertByHead(&list,1);
    insertByHead(&list,2);
    insertByHead(&list,3);
    printList(list);
    //test2
    insertByAppoin(&list,2,100);
    printList(list);
    system("pause");
    return 0;
}