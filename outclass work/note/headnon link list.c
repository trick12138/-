#include <stdio.h>
#include <stdlib.h>
//ʹ�ö���ָ�����ͷ����
//��һ���ڵ���������
struct Node
{
    int data;
    struct Node *next;
};

//�����ڵ�
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

//��ͷ������
void insertByHead(struct Node **list,int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = (*list);
    (*list) = newNode;
}

//��ӡ
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

//ָ��λ�ò���
void insertByAppoin(struct Node **list,int cmpdata,int data)
{
    struct Node *frountNode = (*list);
    struct Node *posNode = (*list)->next;
    while (posNode != NULL && posNode->data != cmpdata)
    {
        frountNode = frountNode->next;
        posNode = posNode->next;
    }
    //�ж��Ƿ��ҵ�
    if (posNode == NULL)
    {
        printf("δ�ҵ�ָ������,������Ѱ�ҵ������ڱ�ͷ,���ñ�ͷ������");
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
    //��������
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