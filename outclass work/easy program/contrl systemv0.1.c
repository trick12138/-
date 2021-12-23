#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataType
{
    int hash;
    char name[20];
    int chinese;
};

//����
struct skipTable
{
    struct dataType data;
    struct skipTable *next;
    struct skipTable *Rnext;
};

//��������
struct skipTable *createSkipNode(struct dataType data)
{
    struct skipTable *newSkipNode = (struct skipTable*)malloc(sizeof(struct skipTable));
    newSkipNode->data = data;
    newSkipNode->next = NULL;
    newSkipNode->Rnext = NULL;
    return newSkipNode;
}

//����ṹ����
struct skipList
{
    struct skipTable *headNode;
    int size;   //��С
    int divisor;    //ֵ
};

//��������ṹ
struct skipList *createSkipTable(int divisor)
{
    struct skipList *list = (struct skipList*)malloc(sizeof(struct skipList));
    list->divisor = divisor;
    list->headNode = NULL;
    list->size = 0;
    return list;
}

//��ӡ����
void printList(struct skipList *list)
{
    if (list->headNode == NULL)
    {
        printf("����Ϊ���޷���ӡ");
        return;
    }
    struct skipTable *pMove = list->headNode;
    struct skipTable *rMove = list->headNode;
    while(pMove != NULL)
    {
        while(rMove != NULL)
        {
            printf("%d %s %d|",rMove->data.hash,rMove->data.name,rMove->data.chinese);
            rMove = rMove->Rnext;
        }
        printf("\n");
        pMove = pMove->next;
        rMove = pMove;
    }
}

//ͨ��hashֵ����
void insertByHash(struct skipList *list,struct dataType data)
{
    //���hashֵ
    int dataHash = data.hash % list->divisor;
    struct skipTable *newSkipNode = createSkipNode(data);
    //���ݴ���
    if (list->headNode == NULL)     //������һ���ڵ�
    {
        list->headNode = newSkipNode;
        list->size++;
    }
    else    //���Ѿ����ڽڵ�
    {
        struct skipTable *pMove = list->headNode;
        if (dataHash < pMove->data.hash % list->divisor)    //�������Ԫ��hashֵ�ȵ�һ���ڵ㻹С
        {
            newSkipNode->next = list->headNode;
            list->headNode = newSkipNode;
            return;
        }
        while (pMove->next != NULL && dataHash >= pMove->next->data.hash % list->divisor )
        {
            if (dataHash == pMove->data.hash % list->divisor)   //���hash��ͻ
            {
                if (pMove->Rnext == NULL)
                {
                    pMove->Rnext = newSkipNode;
                    return;
                }
                else
                {
                    struct skipTable *pRMove = pMove->Rnext;
                    while(pRMove != NULL && newSkipNode->data.hash < pRMove->next->data.hash)
                    {
                        if (pRMove->Rnext->data.hash == newSkipNode->data.hash)     //���hashֵ��ͬ
                        {
                            strcpy(pRMove->Rnext->data.name,newSkipNode->data.name);
                            pRMove->Rnext->data.chinese = newSkipNode->data.chinese;
                            return;
                        }
                        pRMove = pRMove->Rnext;
                    }
                    newSkipNode->Rnext = pRMove->Rnext;
                    pRMove->Rnext = newSkipNode;
                }
            }
            pMove = pMove->next;
        }
        if (dataHash == pMove->data.hash % list->divisor)   //���ҵ��ڵ��鿴�Ƿ����hash��ͻ
        {
            if (pMove->data.hash == newSkipNode->data.hash)     //����һ���ڵ���г�ͻ
            {
                strcpy(pMove->data.name,newSkipNode->data.name);
                pMove->data.chinese = newSkipNode->data.chinese;
                return;
            }
            if (pMove->Rnext == NULL)
            {
                pMove->Rnext = newSkipNode;
                return;
            }
            else
            {
                struct skipTable *pRMove = pMove;
                while(pRMove->Rnext != NULL && newSkipNode->data.hash >= pRMove->Rnext->data.hash)
                {
                    if (pRMove->Rnext->data.hash == newSkipNode->data.hash)   //���ҵ��Ľڵ���ڳ�ͻ
                    {
                        strcpy(pRMove->Rnext->data.name,newSkipNode->data.name);
                        pRMove->Rnext->data.chinese = newSkipNode->data.chinese;
                        return;
                    }
                    pRMove = pRMove->Rnext;
                }
                newSkipNode->Rnext = pRMove->Rnext;
                pRMove->Rnext = newSkipNode;
                return;
            }
        }
        newSkipNode->next = pMove->next;
        pMove->next = newSkipNode;
        return;
    }
}

//ɾ����Ա
void deleteByHash(struct skipList *list,int hash)
{
    if (list->headNode == NULL)
    {
        printf("����Ϊ��,�޷�ɾ��");
        return;
    }

    //��ȡhashֵ
    int dataHash = hash % list->divisor;
    struct skipTable *pMove = list->headNode;
    struct skipTable *pRMove = list->headNode;
    struct skipTable *pFMove = NULL;

    //�Ȳ����Ƿ����
    if (pMove == NULL)
    {
        printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
        return;
    }
    else
    {
        if (pMove->next == NULL)    //ֻ��һ���ڵ�
        {
            if (dataHash == pMove->data.hash % list->divisor)
            {
                
            }
            else
            {
                printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
                return;
            }
        }
        else    //���������ڵ�
        {
            while(pMove->next != NULL && dataHash != pMove->data.hash % list->divisor)    //����
            {
                pMove = pMove->next;
                if (pMove == list->headNode->next)
                    pFMove = list->headNode;
                pFMove = pFMove->next;
            }
            if (pMove->next == NULL)
            {
                printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
                return;
            }
        }
    }

    //ɾ��
    if (pMove == pRMove)    //�ҵ����ڵ�һ���ڵ�
    {
        if (pMove->data.hash == hash)   //��Ҫɾ����Ԫ�ؾ���ͷ��
        {
            if (pMove->Rnext == NULL)   //���ұ�û��Ԫ��
            {
                list->headNode = pMove->next;
                free(pRMove);
                pRMove = NULL;
                return;
            }
            else    //���ұ���Ԫ��
            {
                pMove->Rnext->next = pMove->next;
                list->headNode = pMove->Rnext;
                free(pRMove);
                return;
            }
        }
    }
    else    //���������ڵ�
    {
        pRMove = pMove;
    }
}

//�����˵�
void screen()
{
    printf("------0.�˳�����------\n");
    printf("------1.�����Ա------\n");
    printf("------2.��ӡ����------\n");
    printf("------3.ɾ����Ա------\n");
    printf("------4.�ļ���д------\n");
    printf("------5.��������------\n");
}

//ѡ��
void select(struct skipList *list)
{
    int a;
    printf("���������ѡ��:\n");
    scanf("%d",&a);
    struct dataType data;
    switch(a)
    {
    case 0: 
        exit(0);
        break;
    case 1: 
        printf("������ѧ�� ���� ����\n");
        scanf("%d %s %d",&data.hash,data.name,&data.chinese);
        insertByHash(list,data);
        break;
    case 2:
        printList(list);
        break;
    case 3:
        printf("��������Ҫɾ���ĳ�Ա���:");
        scanf("%d",&data.hash);
        deleteByHash(list,data.hash);
        break;
    default:
        printf("���ѡ������");
        break;
    }
}

int main()
{
    struct skipList *list = createSkipTable(10);
    while(1)
    {
        screen();
        select(list);
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}