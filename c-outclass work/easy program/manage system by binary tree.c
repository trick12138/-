#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数据
struct dataType
{
    char name[20];
    int chinese;
};

//二叉树结点描述
struct treeNode
{
    struct dataType data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

//二叉树的封装
struct tree
{
    struct treeNode *root;
    int size;
};

//二叉树的创建
struct tree *createTree()
{
    struct tree *binaryTree = (struct tree*)malloc(sizeof(struct tree));
    binaryTree->size = 0;
    binaryTree->root = NULL;
    return binaryTree;
}

//二叉树结点的创建
struct treeNode *createTreeNode(struct dataType data)
{
    struct treeNode *newTreeNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newTreeNode->data = data;
    newTreeNode->leftChild = NULL;
    newTreeNode->rightChild = NULL;
    return newTreeNode;
}

//插入
void insertBychinese(struct tree *Tree,struct dataType data)
{
    struct treeNode *newNode = createTreeNode(data);
    if (Tree->root == NULL)     //若没有结点就创建根结点
    {
        Tree->root = newNode;
    }
    else    //若有结点就按数据大小寻找插入位置
    {
        struct treeNode *pMove = Tree->root;
        struct treeNode *pFMove = NULL;
        //循环查找
        while (pMove != NULL)
        {
            if (newNode->data.chinese < pMove->data.chinese)
            {
                pFMove = pMove;
                pMove = pMove->leftChild;
            }
            else if (newNode->data.chinese > pMove->data.chinese)
            {
                pFMove = pMove;
                pMove = pMove->rightChild;
            }
            else    //处理相同的值
            {
                strcpy(pMove->data.name,newNode->data.name);
                pMove->data.chinese = newNode->data.chinese;
                Tree->size++;
                return;
            }
        }
        //插入
        if (newNode->data.chinese < pFMove->data.chinese)
        {
            pFMove->leftChild = newNode;
        }
        else
        {
            pFMove->rightChild = newNode;
        }
        
    }
}


//打印结点
void printNode(struct treeNode *Node)
{
    printf("%8s %3d\n",Node->data.name,Node->data.chinese);
}

//打印中序遍历
void midOrder(struct treeNode *Tree)
{
    if (Tree == NULL)
        return;
    struct treeNode *pMove = Tree;
    if (pMove != NULL)
    {
        midOrder(pMove->leftChild);
        printNode(pMove);
        midOrder(pMove->rightChild);
    }
}

//二叉树的查找
void searchBinaryTree(struct treeNode *root,int chinese)
{
    //定义一个移动的指针
    struct treeNode *pMove = root;
    //查找
    while (pMove != NULL && pMove->data.chinese != chinese)
    {
        if (chinese < pMove->data.chinese)
        {
            pMove = pMove->leftChild;
        }
        else if (chinese > pMove->data.chinese)
        {
            pMove = pMove->rightChild;
        }
        else
        {
            break;
        }
    }
    if (pMove == NULL)
    {
        printf("未找到指定数据,无法打印");
        return;
    }
    else
    {
        printNode(pMove);
    }
}

//二叉树的删除
void deleteTreeNodeByChinese(struct tree *Tree,int chinese)
{
    //准备
    struct treeNode *pMove = Tree->root;
    struct treeNode *pFMove = NULL;
    //查找
    while(pMove != NULL && pMove->data.chinese != chinese)
    {
        if (chinese < pMove->data.chinese)
        {
            pFMove = pMove;
            pMove = pMove->leftChild;
        }
        else if (chinese > pMove->data.chinese)
        {
            pFMove = pMove;
            pMove = pMove->rightChild;
        }
        else
        {
            break;
        }
    }
    if (pMove == NULL)      //没找到结点
    {
        printf("未找到指定位置,无法删除");
        system("pause");
        return;
    }
    else    //找到了
    {
        if (pMove->leftChild != NULL && pMove->rightChild != NULL)
        {
            struct treeNode *nodeMove = pMove->leftChild;
            struct treeNode *nodeFMove = NULL;
            while (nodeMove->rightChild != NULL)
            {
                nodeFMove = nodeMove;
                nodeMove = nodeMove->rightChild;
            }
            //找到结点放上去
            struct treeNode *newNode = createTreeNode(nodeMove->data);
            //做连接
            if (pMove == pFMove->leftChild)
                pFMove->leftChild = newNode;
            else if (pMove == pFMove->rightChild)
                pFMove->rightChild = newNode;
            else
                Tree->root = newNode;
            newNode->leftChild = pMove->leftChild;
            newNode->rightChild = pMove->rightChild;
            //删除
            free(pMove);
            //改变指针位置,做相同的事情
            pMove = nodeMove;
        }
        //记录结点
        struct treeNode *sNode = pMove;
        //如果删除结点的左右有结点就记录下来
        if (pMove->leftChild != NULL)
            sNode = pMove->leftChild;
        else if (pMove->rightChild != NULL)
            sNode = pMove->rightChild;
        if (Tree->root == pMove)
            Tree->root = sNode;
        else
        {
            if (pMove == pFMove->leftChild)
                pFMove->leftChild = sNode;
            else
                pFMove->rightChild = sNode;
        }
        free(pMove);
        Tree->size--;
    }
}

void menu()
{
    printf("--------二叉树--------\n");
    printf("--------0.退出--------\n");
    printf("--------1.插入--------\n");
    printf("--------2.查找--------\n");
    printf("--------3.删除--------\n");
    printf("--------4.打印--------\n");
}

void select(struct tree *Tree)
{
    int select;
    printf("请输入你的选择:\n");
    scanf("%d",&select);
    struct dataType posData;
    switch (select)
    {
    case 0: exit(0);
        break;
    case 1:
        printf("请输入你要插入的人的姓名和学号\n");
        scanf("%s %d",posData.name,&posData.chinese);
        insertBychinese(Tree,posData);
        break;
    case 2:
        printf("请输入你要查找的人的学号\n");
        scanf("%d",&posData.chinese);
        searchBinaryTree(Tree->root,posData.chinese);
        break;
    case 3:
        printf("请输入你要删除的人的学号\n");
        scanf("%d",&posData.chinese);
        deleteTreeNodeByChinese(Tree,posData.chinese);
        break;
    case 4:
        printf("     姓名 学号\n");
        midOrder(Tree->root);
        break;
    default:
        break;
    }
}
int main()
{
    struct tree *Tree = createTree();
    while (1)
    {
        menu();
        select(Tree);
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}