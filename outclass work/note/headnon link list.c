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
    
}

int main()
{
    //��������
    struct Node *list = NULL;
    
    system("pause");
    return 0;
}