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

//�޸ĳ�Ա��Ϣ
void modefyInformationByname(struct Node *headNode,char name[20])
{
    struct Node *frountNode = headNode;
    struct Node *pMove = headNode->next;
    struct Node temp;
    printf("��������Ҫ�޸ĵ���Ϣ\n1.����\n2.�Ա�\n3.����\n4.�ȼ�\n");
    int a;
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("�����������\n");
        scanf("%s",temp.name);
        strcpy(pMove->name,temp.name);
        break;
    case 2:
        printf("�������Ա�\n");
        scanf("%s",temp.sex);
        strcpy(pMove->sex,temp.sex);
        break;
    case 3:
        printf("����������\n");
        scanf("%d",temp.age);
        pMove->age = temp.age;
        break;
    case 4:
        printf("������ȼ�\n");
        scanf("%s",temp.level);
        strcpy(pMove->level,temp.level);
        break;
    default:
        printf("���������Ϣ����\n");
        break;
    }
}

//ɾ��ȫ��
void deleteAll(struct Node *List)
{
    struct Node *pMove = List->next;
    while(pMove != NULL)
    {
        List->next = pMove->next;
        free(pMove);
        pMove = List->next;
    }
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
    printf("-------------4.�޸ĳ�Ա----------------\n");
    printf("-------------5.�ļ���д----------------\n");
    printf("-------------6.ɾ��ȫ��----------------\n");
    printf("-------------7.��������----------------\n");
}

//�ļ���ȡ
void fileRead(struct Node *List)
{
    //�ݴ�
    struct Node temp;
    //���ļ�
    FILE *fp = fopen("girls'information.txt","a+");
    //��ȡ����
        int ch = fgetc(fp);
        fseek(fp,0,SEEK_SET);
        while(1)
        {
            fscanf(fp,"%s ",temp.name);
            fscanf(fp,"%s ",temp.sex);
            fscanf(fp,"%d ",&temp.age);
            fscanf(fp,"%s\n",temp.level);
            insertByHead(List,temp.name,temp.sex,temp.age,temp.level);
            if (feof(fp))
            {
                break;
            }
        }
    //�ر��ļ�
    fclose(fp);
}

//�ļ�д��
void fileWrite(struct Node *List)
{
    //���ļ�
    FILE *fp = fopen("girls'information.txt","a+");
    //ָ������
    struct Node *pMove = List->next;
        while (pMove != NULL)
        {
            fputs(pMove->name,fp);
            fputc(' ',fp);
            fputs(pMove->sex,fp);
            fputc(' ',fp);
            fprintf(fp,"%d",pMove->age);
            fputc(' ',fp);
            fputs(pMove->level,fp);
            fputc('\n',fp);
            pMove = pMove->next;
        }
    //�ر��ļ�
    fclose(fp);
}

//�ļ���д
void filePreservation(struct Node *List)
{
    //ѡ��
    int a;
    printf("������Ҫ��ȡ����д����1.��ȡ,2.д��\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        fileRead(List);
        break;
    case 2:
        fileWrite(List);
        break;
    default:
        break;
    }
}

//��������
void helpMenu()
{
    printf("�����ļ���д���ļ����ݼ������ڴ�,�ٽ��в���\n");
    printf("�������ļ���������Ա���ȶ�ȡ��,��ɾ��ȫ��,��������Ա\n");
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
    case 4:
        printf("��������Ҫ�޸ĵ��˵�����\n");
        scanf("%s",girls.name);
        modefyInformationByname(List,girls.name);
        break;
    case 5:
        filePreservation(List);
        break;
    case 6:
        deleteAll(List);
        break;
    case 7:
        helpMenu();
        break;
    default:
        printf("���������Ϣ����\n");
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