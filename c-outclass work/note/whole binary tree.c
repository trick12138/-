#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数据结构表示
typedef struct data
{
    int first;
    char second[20];
}DATA,*LPDATA;

//二叉树的结构
typedef struct treeNode
{
    struct data data;
    struct treeNode *Left;
    struct treeNode *Right;
}NODE,*LPNODE;

//二叉树封装
typedef struct binarySearchTree
{
    LPNODE root;   //表示整个树
    int treeSize;   //树中节点数
}BST,*LPBST;

//创建树
LPBST createTree()
{
    LPBST newTree = (LPBST)malloc(sizeof(BST));
    newTree->root = NULL;
    newTree->treeSize = 0;
    return newTree;
}

//创建节点
LPNODE createTreeNode(DATA data)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

//万金油函数
int size(LPBST tree)
{
    return tree->treeSize;
}
int empty(LPBST tree)
{
    //如果为空返回1,反之返回0
    return tree->treeSize == 0;
}

//遍历
void printNode(LPNODE curNode)
{
    printf("%d\t%s\n",curNode->data.first,curNode->data.second);
}
void midOrder(LPNODE tree)
{
    if (tree != NULL)
    {
        midOrder(tree->Left);
        printNode(tree);
        midOrder(tree->Right);
    }
}

//插入结点
void insertNode(LPBST tree,DATA data)
{
    //创建节点
    LPNODE newNode = createTreeNode(data);
    //找合适的位置插入
    LPNODE pMove = tree->root;
    LPNODE pMoveParent = NULL;  //记录NULL的上一个结点
    while (pMove != NULL)
    {
        pMoveParent = pMove;    //记录移动结点的父节点
        if (data.first < pMove->data.first)
        {
            pMove = pMove->Left;    //大的往左走在左边
        }
        else if (data.first > pMove->data.first)
        {
            pMove = pMove->Right;
        }
        else    //处理相同的数据
        {
            strcpy(pMove->data.second,data.second);
            return;
        }
    }
    //退出循环
    if (tree->root == NULL)
    {
        tree->root = newNode;
    }
    else
    {
        if (data.first < pMoveParent->data.first)
        {
            pMoveParent->Left = newNode;
        }
        else
        {
            pMoveParent->Right = newNode;
        }
    }
    tree->treeSize++;
}

//查找
LPNODE searchBST(LPBST tree,int first)
{
    LPNODE pMove = tree->root;
    if (pMove == NULL)
        return pMove;
    else
    {
        while (pMove->data.first != first)
        {
            if (first < pMove->data.first)
            {
                pMove = pMove->Left;
            }
            else
            {
                pMove = pMove->Right;
            }
            if (pMove == NULL)
            {
                LPNODE data = (LPNODE)malloc(sizeof(NODE));
                data->data.first = -1;
                strcpy(data->data.second,"没找到");
                return data;
            }
            
        }
        return pMove;
    }
}

//二叉搜索树的删除
void deleteByFirst(LPBST tree,int first)
{
    //定义指针
    LPNODE pMove = tree->root;
    LPNODE pParentMove = NULL;
    //查找
    while (pMove != NULL && pMove->data.first != first)
    {
        pParentMove = pMove;
        if (first < pMove->data.first)
        {
            pMove = pMove->Left;
        }
        else if (first > pMove->data.first)
        {
            pMove = pMove->Right;
        }
        else
        {
            break;
        }
    }
    //没找到指定位置
    if (pMove == NULL)
    {
        printf("未找到指定位置,无法删除");
        system("pause");
        return;
    }
    //删除节点的左右节点都不为空
    if (pMove->Left != NULL && pMove->Right != NULL)
    {
        LPNODE moveNode = pMove->Left;
        LPNODE moveNodeParent = pMove;
        //找到最右边放上去
        while (moveNode->Right != NULL)
        {
            moveNodeParent = moveNode;
            moveNode = moveNode->Right;
        }
        LPNODE newNode = createTreeNode(moveNode->data);
        newNode = pMove->Left;
        newNode = pMove->Right;
        //分类讨论删除的节点
        if (pParentMove == NULL)
            tree->root = newNode;
        else if (pMove == pParentMove->Left)
            pParentMove->Left = newNode;
        else
            pParentMove->Right = newNode;
        //调整二叉树
        //调整删除的指针
        if (moveNodeParent == pMove)
        {
            pParentMove = newNode;
        }
        else
        {
            pParentMove = moveNodeParent;
        }
        free(pMove);
        pMove = moveNode;
    }
    LPNODE sNode = NULL;
    //如果删除节点左右存在节点,记录其节点的下一个节点
    if (pMove->Left != NULL)
        sNode = pMove->Left;
    else
        sNode = pMove->Right;
    if (tree->root == pMove)
    {
        tree->root = sNode;
    }
    else
    {
        if (pMove == pParentMove->Left)
        {
            pParentMove->Left = sNode;
        }
        else
        {
            pParentMove->Right = sNode;
        }
    }
    free(pMove);
    tree->treeSize--;
}

int main()
{
    //测试
    LPBST tree = createTree();
    DATA dataArr[8] = {25,"kfc",24,"wabibabu",84,"games",60,"qaq",79,"uzi",44,"fire",47,"jinx",100,"vain"};
    for (int i = 0; i < 8; i++)
    {
        insertNode(tree,dataArr[i]);
    }
    //打印
    midOrder(tree->root);
    //查找
    printf("查找first为79的数据:");
    printNode(searchBST(tree,1));
    //删除
    deleteByFirst(tree,47);
    midOrder(tree->root);
    system("pause");
    return 0;
}