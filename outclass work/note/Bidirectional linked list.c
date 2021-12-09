#include <stdio.h>
#include <stdlib.h>

//双向链表
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//创建表头
struct Node *createNodeList()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->left = NULL;
    headNode->right = NULL;
    return headNode;
};

//创建节点
struct Node *createNode(int data)
{
    struct Node *posNode = (struct Node*)malloc(sizeof(struct Node));
    posNode->data = data;
    posNode->left = NULL;
    posNode->right = NULL;
    return posNode;
}

//插入节点通过右指针
void insertNodeByHeadRight(struct Node *List,int data)
{
    struct Node *newNode = createNode(data);
    newNode->data = data;
    if (List->right == NULL)
    {
        List->right = newNode;
        newNode->left = List;
    }
    else
    {
        List->right->left = newNode;
        newNode->right = List->right;
        newNode->left = List;
        List->right = newNode;
    }
}

//通过右指针打印
void printListByRight(struct Node *List)
{
    struct Node *pMove = List->right;
    while(pMove != NULL)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->right;
    }
}

//通过左指针插入
void insertNodeByHeadLeft(struct Node *List,int data)
{
    struct Node *newNode = createNode(data);
    newNode->data = data;
    if (List->left == NULL)
    {
        List->left = newNode;
        newNode->right = List;
    }
    else
    {
        List->left->right = newNode;
        newNode->left = List->left;
        newNode->right = List;
        List->left = newNode;
    }
}

//通过左指针打印
void printListByLeft(struct Node *List)
{
    struct Node *pMove = List->left;
    while(pMove != NULL)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->left;
    }
}

int main()
{
    //创建链表表头
    struct Node *List = createNodeList();
    //test1
    insertNodeByHeadRight(List,1);
    insertNodeByHeadRight(List,2);
    insertNodeByHeadRight(List,3);
    printListByRight(List);
    printf("\n");
    //test2
    insertNodeByHeadLeft(List,100);
    insertNodeByHeadLeft(List,101);
    insertNodeByHeadLeft(List,102);
    printListByLeft(List);
    getchar();
}