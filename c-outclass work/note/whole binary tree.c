#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ݽṹ��ʾ
typedef struct data
{
    int first;
    char second[20];
}DATA,*LPDATA;

//�������Ľṹ
typedef struct treeNode
{
    struct data data;
    struct treeNode *Left;
    struct treeNode *Right;
}NODE,*LPNODE;

//��������װ
typedef struct binarySearchTree
{
    LPNODE root;   //��ʾ������
    int treeSize;   //���нڵ���
}BST,*LPBST;

//������
LPBST createTree()
{
    LPBST newTree = (LPBST)malloc(sizeof(BST));
    newTree->root = NULL;
    newTree->treeSize = 0;
    return newTree;
}

//�����ڵ�
LPNODE createTreeNode(DATA data)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

//����ͺ���
int size(LPBST tree)
{
    return tree->treeSize;
}
int empty(LPBST tree)
{
    //���Ϊ�շ���1,��֮����0
    return tree->treeSize == 0;
}

//����
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

//������
void insertNode(LPBST tree,DATA data)
{
    //�����ڵ�
    LPNODE newNode = createTreeNode(data);
    //�Һ��ʵ�λ�ò���
    LPNODE pMove = tree->root;
    LPNODE pMoveParent = NULL;  //��¼NULL����һ�����
    while (pMove != NULL)
    {
        pMoveParent = pMove;    //��¼�ƶ����ĸ��ڵ�
        if (data.first < pMove->data.first)
        {
            pMove = pMove->Left;    //��������������
        }
        else if (data.first > pMove->data.first)
        {
            pMove = pMove->Right;
        }
        else    //������ͬ������
        {
            strcpy(pMove->data.second,data.second);
            return;
        }
    }
    //�˳�ѭ��
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

//����
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
                strcpy(data->data.second,"û�ҵ�");
                return data;
            }
            
        }
        return pMove;
    }
}

//������������ɾ��
void deleteByFirst(LPBST tree,int first)
{
    //����ָ��
    LPNODE pMove = tree->root;
    LPNODE pParentMove = NULL;
    //����
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
    //û�ҵ�ָ��λ��
    if (pMove == NULL)
    {
        printf("δ�ҵ�ָ��λ��,�޷�ɾ��");
        system("pause");
        return;
    }
    //ɾ���ڵ�����ҽڵ㶼��Ϊ��
    if (pMove->Left != NULL && pMove->Right != NULL)
    {
        LPNODE moveNode = pMove->Left;
        LPNODE moveNodeParent = pMove;
        //�ҵ����ұ߷���ȥ
        while (moveNode->Right != NULL)
        {
            moveNodeParent = moveNode;
            moveNode = moveNode->Right;
        }
        LPNODE newNode = createTreeNode(moveNode->data);
        newNode = pMove->Left;
        newNode = pMove->Right;
        //��������ɾ���Ľڵ�
        if (pParentMove == NULL)
            tree->root = newNode;
        else if (pMove == pParentMove->Left)
            pParentMove->Left = newNode;
        else
            pParentMove->Right = newNode;
        //����������
        //����ɾ����ָ��
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
    //���ɾ���ڵ����Ҵ��ڽڵ�,��¼��ڵ����һ���ڵ�
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
    //����
    LPBST tree = createTree();
    DATA dataArr[8] = {25,"kfc",24,"wabibabu",84,"games",60,"qaq",79,"uzi",44,"fire",47,"jinx",100,"vain"};
    for (int i = 0; i < 8; i++)
    {
        insertNode(tree,dataArr[i]);
    }
    //��ӡ
    midOrder(tree->root);
    //����
    printf("����firstΪ79������:");
    printNode(searchBST(tree,1));
    //ɾ��
    deleteByFirst(tree,47);
    midOrder(tree->root);
    system("pause");
    return 0;
}