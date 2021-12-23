#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataType
{
    int hash;
    char name[20];
    int chinese;
};

//跳表
struct skipTable
{
    struct dataType data;
    struct skipTable *next;
    struct skipTable *Rnext;
};

//创建跳表
struct skipTable *createSkipNode(struct dataType data)
{
    struct skipTable *newSkipNode = (struct skipTable*)malloc(sizeof(struct skipTable));
    newSkipNode->data = data;
    newSkipNode->next = NULL;
    newSkipNode->Rnext = NULL;
    return newSkipNode;
}

//跳表结构描述
struct skipList
{
    struct skipTable *headNode;
    int size;   //大小
    int divisor;    //值
};

//创建跳表结构
struct skipList *createSkipTable(int divisor)
{
    struct skipList *list = (struct skipList*)malloc(sizeof(struct skipList));
    list->divisor = divisor;
    list->headNode = NULL;
    list->size = 0;
    return list;
}

//打印跳表
void printList(struct skipList *list)
{
    if (list->headNode == NULL)
    {
        printf("跳表为空无法打印");
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

//通过hash值插入
void insertByHash(struct skipList *list,struct dataType data)
{
    //求出hash值
    int dataHash = data.hash % list->divisor;
    struct skipTable *newSkipNode = createSkipNode(data);
    //数据处理
    if (list->headNode == NULL)     //创建第一个节点
    {
        list->headNode = newSkipNode;
        list->size++;
    }
    else    //若已经存在节点
    {
        struct skipTable *pMove = list->headNode;
        if (dataHash < pMove->data.hash % list->divisor)    //若插入的元素hash值比第一个节点还小
        {
            newSkipNode->next = list->headNode;
            list->headNode = newSkipNode;
            return;
        }
        while (pMove->next != NULL && dataHash >= pMove->next->data.hash % list->divisor )
        {
            if (dataHash == pMove->data.hash % list->divisor)   //如果hash冲突
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
                        if (pRMove->Rnext->data.hash == newSkipNode->data.hash)     //如果hash值相同
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
        if (dataHash == pMove->data.hash % list->divisor)   //在找到节点后查看是否存在hash冲突
        {
            if (pMove->data.hash == newSkipNode->data.hash)     //当第一个节点就有冲突
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
                    if (pRMove->Rnext->data.hash == newSkipNode->data.hash)   //当找到的节点存在冲突
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

//删除成员
void deleteByHash(struct skipList *list,int hash)
{
    if (list->headNode == NULL)
    {
        printf("跳表为空,无法删除");
        return;
    }

    //求取hash值
    int dataHash = hash % list->divisor;
    struct skipTable *pMove = list->headNode;
    struct skipTable *pRMove = list->headNode;
    struct skipTable *pFMove = NULL;

    //先查找是否存在
    if (pMove == NULL)
    {
        printf("未找到指定元素,无法删除");
        return;
    }
    else
    {
        if (pMove->next == NULL)    //只有一个节点
        {
            if (dataHash == pMove->data.hash % list->divisor)
            {
                
            }
            else
            {
                printf("未找到指定元素,无法删除");
                return;
            }
        }
        else    //至少两个节点
        {
            while(pMove->next != NULL && dataHash != pMove->data.hash % list->divisor)    //查找
            {
                pMove = pMove->next;
                if (pMove == list->headNode->next)
                    pFMove = list->headNode;
                pFMove = pFMove->next;
            }
            if (pMove->next == NULL)
            {
                printf("未找到指定元素,无法删除");
                return;
            }
        }
    }

    //删除
    if (pMove == pRMove)    //找到的在第一个节点
    {
        if (pMove->data.hash == hash)   //且要删除的元素就是头部
        {
            if (pMove->Rnext == NULL)   //且右边没有元素
            {
                list->headNode = pMove->next;
                free(pRMove);
                pRMove = NULL;
                return;
            }
            else    //且右边有元素
            {
                pMove->Rnext->next = pMove->next;
                list->headNode = pMove->Rnext;
                free(pRMove);
                return;
            }
        }
    }
    else    //至少两个节点
    {
        pRMove = pMove;
    }
}

//操作菜单
void screen()
{
    printf("------0.退出程序------\n");
    printf("------1.插入成员------\n");
    printf("------2.打印跳表------\n");
    printf("------3.删除成员------\n");
    printf("------4.文件读写------\n");
    printf("------5.操作帮助------\n");
}

//选项
void select(struct skipList *list)
{
    int a;
    printf("请输入你的选择:\n");
    scanf("%d",&a);
    struct dataType data;
    switch(a)
    {
    case 0: 
        exit(0);
        break;
    case 1: 
        printf("请输入学号 姓名 分数\n");
        scanf("%d %s %d",&data.hash,data.name,&data.chinese);
        insertByHash(list,data);
        break;
    case 2:
        printList(list);
        break;
    case 3:
        printf("请输入你要删除的成员序号:");
        scanf("%d",&data.hash);
        deleteByHash(list,data.hash);
        break;
    default:
        printf("你的选择有误");
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