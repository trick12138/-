#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];//����
    char sex[4];//�Ա�
    int age;//����
    char level[20];//�ȼ�
    struct Node *next;
};

//������ͷ
struct Node *createNodeHead()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

//�����ڵ�
struct Node *createPosNode(char name[20],char sex[4],int age,char level[20])
{
    struct Node *posNode  = (struct Node*)malloc(sizeof(struct Node));
    posNode->next = NULL;
    strcpy(posNode->name,name);
    strcpy(posNode->sex,sex);
    posNode->age = age;
    strcpy(posNode->level,level);
    return posNode;
}

//����ڵ�
void insertByHead(struct Node *headNode,char name[20],char sex[4],int age,char level[20])
{
    struct Node *newNode = createPosNode(name,sex,age,level);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//ɾ����Ա
void deleteByName(struct Node *headNode,char name[20])
{
    struct Node *frountNode = headNode;
    struct Node *pMove = headNode->next;
    while(pMove != NULL && strcmp(pMove->name,name))
    {
        frountNode = pMove;
        pMove = pMove->next;
    }
    if (frountNode != NULL)
    {
        frountNode->next = pMove->next;
        free(pMove);
    }
    else
    {
        printf("δ�ҵ�ָ��λ��,�޷�ɾ��");
    }
    pMove = NULL;
}

//��ӡ
void printList(struct Node *headNode)
{
    struct Node *pMove = headNode->next;
    printf("����  �Ա�  ����  �ȼ�\n");
    while(pMove != NULL)
    {
        printf("%s  %s  %d  %s\n",pMove->name,pMove->sex,pMove->age,pMove->level);
        pMove = pMove->next;
    }
}

//�˵�
void screen()
{
    printf("-----------�󹬹���ϵͳv0.0.1----------\n");
    printf("-------------0.�˳�����----------------\n");
    printf("-------------1.�����Ա----------------\n");
    printf("-------------2.��ӡ�б�----------------\n");
    printf("-------------3.ɾ����Ա----------------\n");
}

//ѡ��
void select(struct Node *List)
{
    int a;
    //�ݴ���Ϣ
    struct Node girls;
    scanf("%d",&a);
    switch (a)
    {
    case 0:
        system("pause");
        exit(0);
        break;
    case 1:
        printf("���������֣��Ա����䣬�ȼ�\n");
        scanf("%s %s %d %s",girls.name,girls.sex,&girls.age,girls.level);
        insertByHead(List,girls.name,girls.sex,girls.age,girls.level);
        break;
    case 2:
        printList(List);
        break;
    case 3:
        printf("��������Ҫɾ�����˵�����\n");
        scanf("%s",girls.name);
        deleteByName(List,girls.name);
        break;
    default:
        break;
    }
}

int main()
{
    //������ͷ
    struct Node *List = createNodeHead();
    while(1)
    {
        screen();
        select(List);
        system("pause");
        system("cls");
    }
    return 0;
}