#include <stdio.h>
#include <stdlib.h>
//创建结构体
struct Node
{
    int data;//数据域
    struct Node *left;
    struct Node *right;//指针域
};

//创建表头
struct Node *createNodeHead()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->left = headNode->right = NULL;
    return headNode;
};

//创建节点
struct Node *createNode(int data)
{
    struct Node *posNode = (struct Node*)malloc(sizeof(struct Node));
    posNode->data = data;
    posNode->left = posNode->right = NULL;
    return posNode;
}

//插入 
void insertNodeByHead(struct Node *List,int data)
{
    struct Node *newNode = createNode(data);
    struct Node *tailNode = List->left;//表尾
    if (tailNode == NULL)
    {
        List->left = newNode;
        newNode->right = List;
        newNode->left = List;
        List->right = newNode;
    }
    else
    {
        tailNode->right = newNode;
        newNode->left = tailNode;
        newNode->right = List;
        List->left = newNode;
    }
}

//打印
void printListByRight(struct Node *List)
{
    if (List->left == List->right)
    {
        printf("链表为空,无法打印");
        return;
    }
    struct Node *pMove = List->right;
    while(pMove != List)
    {
        printf("%d-->",pMove->data);
        pMove = pMove->right;
    }
    printf("\n");
}

int main()
{
    //创建链表
    struct Node *List = createNodeHead();
    //test1
    insertNodeByHead(List,1);
    insertNodeByHead(List,2);
    insertNodeByHead(List,3);
    printListByRight(List);
    system("pause");
    return 0;
}