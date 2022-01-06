#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����
struct dataType
{
    char name[20];
    int chinese;
};

//�������������
struct treeNode
{
    struct dataType data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

//�������ķ�װ
struct tree
{
    struct treeNode *root;
    int size;
};

//�������Ĵ���
struct tree *createTree()
{
    struct tree *binaryTree = (struct tree*)malloc(sizeof(struct tree));
    binaryTree->size = 0;
    binaryTree->root = NULL;
    return binaryTree;
}

//���������Ĵ���
struct treeNode *createTreeNode(struct dataType data)
{
    struct treeNode *newTreeNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newTreeNode->data = data;
    newTreeNode->leftChild = NULL;
    newTreeNode->rightChild = NULL;
    return newTreeNode;
}

//����
void insertBychinese(struct tree *Tree,struct dataType data)
{
    struct treeNode *newNode = createTreeNode(data);
    if (Tree->root == NULL)     //��û�н��ʹ��������
    {
        Tree->root = newNode;
    }
    else    //���н��Ͱ����ݴ�СѰ�Ҳ���λ��
    {
        struct treeNode *pMove = Tree->root;
        struct treeNode *pFMove = NULL;
        //ѭ������
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
            else    //������ͬ��ֵ
            {
                strcpy(pMove->data.name,newNode->data.name);
                pMove->data.chinese = newNode->data.chinese;
                Tree->size++;
                return;
            }
        }
        //����
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


//��ӡ���
void printNode(struct treeNode *Node)
{
    printf("%8s %3d\n",Node->data.name,Node->data.chinese);
}

//��ӡ�������
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

//�������Ĳ���
void searchBinaryTree(struct treeNode *root,int chinese)
{
    //����һ���ƶ���ָ��
    struct treeNode *pMove = root;
    //����
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
        printf("δ�ҵ�ָ������,�޷���ӡ");
        return;
    }
    else
    {
        printNode(pMove);
    }
}

//��������ɾ��
void deleteTreeNodeByChinese(struct tree *Tree,int chinese)
{
    //׼��
    struct treeNode *pMove = Tree->root;
    struct treeNode *pFMove = NULL;
    //����
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
    if (pMove == NULL)      //û�ҵ����
    {
        printf("δ�ҵ�ָ��λ��,�޷�ɾ��");
        system("pause");
        return;
    }
    else    //�ҵ���
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
            //�ҵ�������ȥ
            struct treeNode *newNode = createTreeNode(nodeMove->data);
            //������
            if (pMove == pFMove->leftChild)
                pFMove->leftChild = newNode;
            else if (pMove == pFMove->rightChild)
                pFMove->rightChild = newNode;
            else
                Tree->root = newNode;
            newNode->leftChild = pMove->leftChild;
            newNode->rightChild = pMove->rightChild;
            //ɾ��
            free(pMove);
            //�ı�ָ��λ��,����ͬ������
            pMove = nodeMove;
        }
        //��¼���
        struct treeNode *sNode = pMove;
        //���ɾ�����������н��ͼ�¼����
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
    printf("--------������--------\n");
    printf("--------0.�˳�--------\n");
    printf("--------1.����--------\n");
    printf("--------2.����--------\n");
    printf("--------3.ɾ��--------\n");
    printf("--------4.��ӡ--------\n");
}

void select(struct tree *Tree)
{
    int select;
    printf("���������ѡ��:\n");
    scanf("%d",&select);
    struct dataType posData;
    switch (select)
    {
    case 0: exit(0);
        break;
    case 1:
        printf("��������Ҫ������˵�������ѧ��\n");
        scanf("%s %d",posData.name,&posData.chinese);
        insertBychinese(Tree,posData);
        break;
    case 2:
        printf("��������Ҫ���ҵ��˵�ѧ��\n");
        scanf("%d",&posData.chinese);
        searchBinaryTree(Tree->root,posData.chinese);
        break;
    case 3:
        printf("��������Ҫɾ�����˵�ѧ��\n");
        scanf("%d",&posData.chinese);
        deleteTreeNodeByChinese(Tree,posData.chinese);
        break;
    case 4:
        printf("     ���� ѧ��\n");
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