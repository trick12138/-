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
    printFTree(A);
    printf("\n");
    printMTree(A);
    printf("\n");
    printTTree(A);
    printf("\n");
    system("pause");
    return 0;
}