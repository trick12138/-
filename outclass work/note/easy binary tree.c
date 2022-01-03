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

//�������
void printFTree(pBinary root)
{
    if(root != NULL)
    {
        printPosNode(root);
        printFTree(root->left);
        printFTree(root->right);
    }
}

//�ǵݹ鷽ʽ�������
void printFTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    //׼��ջ��ָ��
    pBinary treeStack[20];
    int stackTop = -1;
    pBinary pMove = tree;
    //Ѱ·
    while (stackTop != -1 || pMove)
    {
        //Ѱ·:��ӡ��ǰ�ڵ㲢��ջ,�����ƶ�
        while (pMove)
        {
            //��ӡ�ڵ�
            printf("%c ",pMove->data);
            //��ջ
            treeStack[++stackTop] = pMove;
            //�����ƶ�
            pMove = pMove->left;
        }
        //��ӡ�ҽڵ�
        if (stackTop != -1)
        {
            //��ջ
            pMove = treeStack[stackTop--];
            //����
            pMove = pMove->right;
        }
    }
}

//�������
void printMTree(pBinary root)
{
    if (root != NULL)
    {
        printMTree(root->left);
        printPosNode(root);
        printMTree(root->right);
    }
}

//�Էǵݹ�ķ�ʽ�������
void printMTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    //׼��ջ��ָ��
    pBinary treeStack[20];
    int stackTop = -1;
    pBinary pMove = tree;
    //��ӡ
    while (stackTop != -1 || pMove)
    {
        while (pMove)
        {
            //���ߵ������
            treeStack[++stackTop] = pMove;
            pMove = pMove->left;
        }
        if (stackTop != -1)
        {
            //��ջ
            pMove = treeStack[stackTop--];
            //��ӡ
            printf("%c ",pMove->data);
            //�ߵ��ұ�
            pMove = pMove->right;
        }
        
    }
    
}

//��������
void printTTree(pBinary root)
{
    if (root != NULL)
    {
        printTTree(root->left);
        printTTree(root->right);
        printPosNode(root);
    }
}

//�Էǵݹ�ķ�ʽ��������
void printTTreeByStack(pBinary tree)
{
    if (tree == NULL)
        return;
    pBinary stack[10];
    int stackTop = -1;
    //��
    pBinary pMove = tree;
    pBinary pLastVisist = NULL;
    //�� �� ��
    while (pMove)
    {
        stack[++stackTop] = pMove;
        pMove = pMove->left;
    }
    while (stackTop != -1)
    {
        pMove = stack[stackTop--];
        //�жϵ�ǰ�ڵ��Ƿ񱻷���
        if (pMove->left == NULL || pMove->right == pLastVisist)
        {
            printf("%c ",pMove->data);
            pLastVisist = pMove;    //����ڵ����´��ж�,�ı��ǵ�λ��
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
    printf("�Եݹ�ķ�ʽ�����ӡ\n");
    printFTree(A);
    printf("\n");
    printf("�Էǵݹ�ķ�ʽ�����ӡ\n");
    printFTreeByStack(A);
    printf("\n");
    printf("�Եݹ�ķ�ʽ�������\n");
    printMTree(A);
    printf("\n");
    printf("�Էǵݹ�ķ�ʽ�������\n");
    printMTreeByStack(A);
    printf("\n");
    printf("�Եݹ�ķ�ʽ�������\n");
    printTTree(A);
    printf("\n");
    printf("�Էǵݹ�ķ�ʽ�������\n");
    printTTreeByStack(A);
    printf("\n");
    system("pause");
    return 0;
}