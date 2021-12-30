#include <stdio.h>
#include <stdlib.h>

typedef struct binary
{
    char data;
    struct binary *right;
    struct binary *left;
}_binary,*pBinary;

pBinary createBinaryTreeNode(char data)
{
    pBinary newBinaryTreeNode = (pBinary)malloc(sizeof(_binary));
    newBinaryTreeNode->data = data;
    newBinaryTreeNode->left = NULL;
    newBinaryTreeNode->right = NULL;
    return newBinaryTreeNode;
}
  
void connectBinaryTree(pBinary midTree,pBinary leftTree,pBinary rightTree)
{
    midTree->left = leftTree;
    midTree->right = rightTree;
}

void printPosNode(pBinary curData)
{
    printf("%c ",curData->data);
}

//先序遍历
void printFTree(pBinary root)
{
    if(root != NULL)
    {
        printPosNode(root);
        printFTree(root->left);
        printFTree(root->right);
    }
}

//非递归方式先序遍历
void printFTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    //准备栈和指针
    pBinary treeStack[20];
    int stackTop = -1;
    pBinary pMove = tree;
    //寻路
    while (stackTop != -1 || pMove)
    {
        //寻路:打印当前节点并入栈,向左移动
        while (pMove)
        {
            //打印节点
            printf("%c ",pMove->data);
            //入栈
            treeStack[++stackTop] = pMove;
            //向左移动
            pMove = pMove->left;
        }
        //打印右节点
        if (stackTop != -1)
        {
            //出栈
            pMove = treeStack[stackTop--];
            //向右
            pMove = pMove->right;
        }
    }
}

//中序遍历
void printMTree(pBinary root)
{
    if (root != NULL)
    {
        printMTree(root->left);
        printPosNode(root);
        printMTree(root->right);
    }
}

//以非递归的方式中序遍历
void printMTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    //准备栈和指针
    pBinary treeStack[20];
    int stackTop = -1;
    pBinary pMove = tree;
    //打印
    while (stackTop != -1 || pMove)
    {
        while (pMove)
        {
            //先走到最左边
            treeStack[++stackTop] = pMove;
            pMove = pMove->left;
        }
        if (stackTop != -1)
        {
            //出栈
            pMove = treeStack[stackTop--];
            //打印
            printf("%c ",pMove->data);
            //走到右边
            pMove = pMove->right;
        }
        
    }
    
}

//后续遍历
void printTTree(pBinary root)
{
    if (root != NULL)
    {
        printTTree(root->left);
        printTTree(root->right);
        printPosNode(root);
    }
}

//以非递归的方式后续遍历
void printTTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    pBinary stack[10];
    int stackTop = -1;
    //走
    pBinary pMove = tree;
    pBinary pLastVisist = NULL;
    //左 右 根
    while (pMove)
    {
        stack[++stackTop] = pMove;
        pMove = pMove->left;
    }
    while (stackTop != -1)
    {
        pMove = stack[stackTop--];
        //判断当前节点是否被访问
        if (pMove->left == NULL || pMove->right == pLastVisist)
        {
            printf("%c ",pMove->data);
            pLastVisist = pMove;    //保存节点做下次判断,改变标记的位置
        }
        else
        {
            stack[++stackTop] = pMove;
            pMove = pMove->right;
            while (pMove)
            {
                stack[++stackTop] = pMove;
                pMove = pMove->left;
            }
            
        }
    }
    
}

int main()
{
    pBinary A = createBinaryTreeNode('A');
    pBinary B = createBinaryTreeNode('B');
    pBinary C = createBinaryTreeNode('C');
    pBinary D = createBinaryTreeNode('D');
    pBinary E = createBinaryTreeNode('E');
    pBinary F = createBinaryTreeNode('F');
    pBinary G = createBinaryTreeNode('G');
    pBinary H = createBinaryTreeNode('H');
    pBinary I = createBinaryTreeNode('I');
    pBinary J = createBinaryTreeNode('J');
    pBinary K = createBinaryTreeNode('K');
    pBinary L = createBinaryTreeNode('L');
    pBinary M = createBinaryTreeNode('M');
    pBinary N = createBinaryTreeNode('N');
    pBinary O = createBinaryTreeNode('O');
    connectBinaryTree(A,B,C);
    connectBinaryTree(B,D,E);
    connectBinaryTree(C,F,G);
    connectBinaryTree(D,H,I);
    connectBinaryTree(E,J,K);
    connectBinaryTree(F,L,M);
    connectBinaryTree(G,N,O);
    printf("以递归的方式先序打印\n");
    printFTree(A);
    printf("\n");
    printf("以非递归的方式先序打印\n");
    printFTreeByStack(A);
    printf("\n");
    printf("以递归的方式中序遍历\n");
    printMTree(A);
    printf("\n");
    printf("以非递归的方式中序遍历\n");
    printMTreeByStack(A);
    printf("\n");
    printf("以递归的方式后序遍历\n");
    printTTree(A);
    printf("\n");
    printf("以非递归的方式后序遍历\n");
    printTTreeByStack(A);
    printf("\n");
    system("pause");
    return 0;
}