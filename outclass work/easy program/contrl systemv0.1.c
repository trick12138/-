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

//��������ڵ�
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

//ͨ��hashֵ����,��������
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
        return;
    }
    else    //���Ѿ����ڽڵ�
    {
        struct skipTable *pMove = list->headNode;
        struct skipTable *pFMove = NULL;
        if (dataHash < pMove->data.hash % list->divisor)    //�������Ԫ��hashֵ�ȵ�һ���ڵ㻹С
        {
            newSkipNode->next = list->headNode;
            list->headNode = newSkipNode;
            list->size++;
            return;
        }
        while (pMove->next != NULL && dataHash >= pMove->next->data.hash % list->divisor )  //����Ԫ��
        {
            pMove = pMove->next;
            if (pFMove != NULL)
                pFMove = pFMove->next;
            if (pMove == list->headNode->next)
                pFMove = list->headNode;
        }

        if (dataHash == pMove->data.hash % list->divisor)   //���ҵ��ڵ��鿴�Ƿ����hash��ͻ
        {
            if (pMove->data.hash == newSkipNode->data.hash)     //����һ���ڵ���г�ͻhashֵ��ͬ
            {
                strcpy(pMove->data.name,newSkipNode->data.name);
                pMove->data.chinese = newSkipNode->data.chinese;
                return;
            }
            if (pMove == list->headNode && newSkipNode->data.hash < pMove->data.hash)    //����ͷ�ڵ�,hashֵС��ͷ�ڵ�
            {
                newSkipNode->Rnext = pMove;
                newSkipNode->next = pMove->next;
                list->headNode = newSkipNode;
                pMove->next = NULL;
                list->size++;
                return;
            }
            if (pMove->Rnext == NULL)   //��pMove�ҽڵ�Ϊ��
            {
                if (newSkipNode->data.hash > pMove->data.hash)      //��pMove��hashֵС�ڲ���ڵ��
                {
                    pMove->Rnext = newSkipNode;
                    list->size++;
                    return;
                }
                else        //��pMove��hashֵ���ڲ���ڵ��
                {
                    newSkipNode->next = pMove->next;
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    list->size++;
                    return;
                }
            }
            else    //��pMove�ҽڵ㲻Ϊ�����Ǿ�ȥ��
            {
                struct skipTable *pRMove = pMove;
                if (newSkipNode->data.hash < pMove->data.hash)  //�½ڵ��hashֵС��pMove��
                {
                    newSkipNode->next = pMove->next;
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    list->size++;
                    return;
                }
                while(pRMove->Rnext != NULL && newSkipNode->data.hash >= pRMove->Rnext->data.hash)  //ѭ������
                {
                    if (pRMove->Rnext->data.hash == newSkipNode->data.hash)   //���ҵ��Ľڵ���ڳ�ͻ
                    {
                        strcpy(pRMove->Rnext->data.name,newSkipNode->data.name);
                        pRMove->Rnext->data.chinese = newSkipNode->data.chinese;
                        return;
                    }
                    pRMove = pRMove->Rnext;
                }
                newSkipNode->Rnext = pRMove->Rnext;     //��pRMove�������������
                pRMove->Rnext = newSkipNode;
                list->size++;
                return;
            }
        }
        newSkipNode->next = pMove->next;    //��pMove�������������
        pMove->next = newSkipNode;
        list->size++;
        return;
    }
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
    while (rMove != NULL)
    {
        printf(" ѧ��|����|����|");
        rMove = rMove->Rnext;
    }
    putchar('\n');
    rMove = pMove;
    while(pMove != NULL)
    {
        while(rMove != NULL)
        {
            printf("%2d %8s %3d|",rMove->data.hash,rMove->data.name,rMove->data.chinese);
            rMove = rMove->Rnext;
        }
        printf("\n");
        pMove = pMove->next;
        rMove = pMove;
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

    //��ȡhashֵ,��׼��
    int dataHash = hash % list->divisor;
    struct skipTable *pMove = list->headNode;
    struct skipTable *pRMove = list->headNode;
    struct skipTable *pFMove = NULL;

    //���������
    if (pMove == NULL)  //�ж������Ƿ�Ϊ��
    {
        printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
        return;
    }
    else
    {
        if (pMove->next == NULL)    //ֻ��һ���ڵ�
        {
            if (dataHash != pMove->data.hash % list->divisor)   //����ڵ㲻�Ǿ�����
            {
                printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
                return;
            }
        }
        else    //���������ڵ�
        {
            while(pMove->next != NULL && dataHash != pMove->data.hash % list->divisor)    //�������
            {
                pMove = pMove->next;
                if (pFMove != NULL)
                    pFMove = pFMove->next;
                if (pMove == list->headNode->next)
                    pFMove = list->headNode;
            }
        }
    }

    //�ҵ��ڵ����ɾ��
    if (dataHash != pMove->data.hash % list->divisor)   //���û�ҵ�
    {
        printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
        return;
    }
    else    //�ҵ���
    {
        if (pMove == list->headNode)    //�ҵ��ľ���ͷ�ڵ�
        {
            if (hash == pMove->data.hash && pMove->Rnext == NULL)   //�ҵ��Ĳ�����ͷ�ڵ���Ҫɾ���ľ���ͷ�ڵ�ĵ�һ��Ԫ�������ұ�û��Ԫ��
            {
                list->headNode = pMove->next;
                free(pMove);
                list->size--;
                return;
            }
            else if(hash == pMove->data.hash && pMove->Rnext != NULL)   //�ҵ��Ĳ�����ͷ�ڵ������ұ���Ԫ��
            {
                list->headNode = pMove->Rnext;
                pMove->Rnext->next = pMove->next;
                free(pMove);
                list->size--;
                return;
            }
            while (pRMove->Rnext != NULL && pRMove->data.hash != hash)   //�ҵ��ľ���ͷ�ڵ��Ҳ��ǵ�һ���ڵ����Ǿ���������,��pMoveΪpRmove��ǰ�ýڵ�
            {
                if (pMove != pRMove)
                    pMove = pMove->Rnext;
                pRMove = pRMove->Rnext;
            }
            if (hash != pRMove->data.hash || pMove == pRMove)  //û�ҵ��ڵ�
            {
                printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
                return;
            }
            else    //�ҵ������Ǿ���ɾ������
            {
                pMove->Rnext = pRMove->Rnext;
                free(pRMove);
                list->size--;
                return;
            }
        }
        else    //�ҵ��Ĳ���ͷ�ڵ�
        {
            if (hash == pMove->data.hash)   //�ҵ����Ҿ��ǵ�һ���ڵ�
            {
                if (pMove->Rnext == NULL)   //�ҵ��������ұ�û��Ԫ��
                {
                    pFMove->next = pMove->next;
                    free(pMove);
                    list->size--;
                    return;
                }
                else    //�ҵ��������ұ���Ԫ��
                {
                    pFMove->next = pMove->Rnext;
                    pMove->Rnext->next = pMove->next;
                    free(pMove);
                    list->size--;
                    return;
                }
            }
            else    //�ҵ����Ҳ��ڵ�һ���ڵ�
            {
                while(pRMove->Rnext != NULL && pRMove->data.hash != hash)
                {
                    if (pMove != pRMove)
                        pMove = pMove->Rnext;
                    pRMove = pRMove->Rnext;
                }
                if (hash != pRMove->data.hash || pMove == pRMove)  //û�ҵ��ڵ�
                {
                    printf("δ�ҵ�ָ��Ԫ��,�޷�ɾ��");
                    return;
                }
                else    //�ҵ������Ǿ���ɾ������
                {
                    pMove->Rnext = pRMove->Rnext;
                    free(pRMove);
                    list->size--;
                    return;
                }
            }
        }
    }
}

//�ļ���ȡ
void fileRead(struct skipList *list)
{
    //�ݴ���Ϣ
    struct dataType temp;
    //���ļ�
    FILE *fp = fopen("student's-grade.txt","r");
    //�ĵ�Ϊ��ʱ�Ŀ���
    if (fgetc(fp) == EOF)
    {
        printf("�ĵ�Ϊ���޷���ȡ\n");
        return;
    }
    
    //��ʼ��ȡ
    fseek(fp,0,SEEK_SET);
    while(1)
    {
        fscanf(fp,"%d ",&temp.hash);
        fscanf(fp,"%s ",temp.name);
        fscanf(fp,"%d|",&temp.chinese);
        insertByHash(list,temp);
        if (feof(fp))
            break;
    }
    fclose(fp);
}

//�ļ�д��
void fileWrite(struct skipList *list)
{
    //���ļ�
    FILE *fp = fopen("student's-grade.txt","w");
    //��������
    if (list->headNode == NULL)
    {
        printf("û�������޷�д��");
        return;
    }
    //ָ������
    struct skipTable *pMove = list->headNode;
    struct skipTable *pRMove = list->headNode;
    while (pMove != NULL)
    {
        while (pRMove != NULL)
        {
            fprintf(fp,"%d ",pRMove->data.hash);
            fputs(pRMove->data.name,fp);
            fputc(' ',fp);
            fprintf(fp,"%d|",pRMove->data.chinese);
            pRMove = pRMove->Rnext;
        }
        fputc('\n',fp);
        pMove = pMove->next;
        pRMove = pMove;
    }
    
}

//��������
void help()
{
    printf("�ļ��Ķ�ȡ��д����ڳ���ǰĿ¼������һ����student's-grade.txt���ļ�\n");
    printf("�ļ��Ķ�ȡ���Զ�����\n");
    printf("2021/12/30\n");
}

//�����˵�
void screen()
{
    printf("---�ɼ�����ϵͳv0.1---\n");
    printf("------0.�˳�����------\n");
    printf("------1.�����Ա------\n");
    printf("------2.��ӡ����------\n");
    printf("------3.ɾ����Ա------\n");
    printf("------4.�ļ���ȡ------\n");
    printf("------5.�ļ�д��------\n");
    printf("------6.��������------\n");
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
    case 4:
        fileRead(list);
        break;
    case 5:
        fileWrite(list);
        break;
    case 6:
        help();
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