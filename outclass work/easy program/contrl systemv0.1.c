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

/*
    文件的读取与写入
*/

//通过hash值插入,并且排序
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
        return;
    }
    else    //若已经存在节点
    {
        struct skipTable *pMove = list->headNode;
        struct skipTable *pFMove = NULL;
        if (dataHash < pMove->data.hash % list->divisor && pMove->Rnext == NULL)    //若插入的元素hash值比第一个节点还小
        {
            newSkipNode->next = list->headNode;
            list->headNode = newSkipNode;
            return;
        }
        if (dataHash < pMove->data.hash % list->divisor && pMove->Rnext != NULL)
        {
            newSkipNode->next = list->headNode;
            newSkipNode->Rnext = pMove->Rnext;
            list->headNode->next = newSkipNode;
            pMove->next = NULL;
            return;
        }
        
        while (pMove->next != NULL && dataHash >= pMove->next->data.hash % list->divisor )  //查找
        {
            if (dataHash == pMove->data.hash % list->divisor)   //如果hash冲突
            {
                if (pMove->Rnext == NULL)
                {
                    pMove->Rnext = newSkipNode;
                    return;
                }
                else if (newSkipNode->data.hash < pMove->data.hash)
                {
                    newSkipNode->Rnext = pMove;
                    newSkipNode->next = pMove->next;
                    pFMove->next = newSkipNode;
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
                    return;
                }
            }
            pMove = pMove->next;
            if (pFMove != NULL)
                pFMove = pFMove->next;
            if (pMove == list->headNode->next)
                pFMove = list->headNode;
        }

        if (dataHash == pMove->data.hash % list->divisor)   //在找到节点后查看是否存在hash冲突
        {
            if (pMove->data.hash == newSkipNode->data.hash)     //当第一个节点就有冲突hash值相同
            {
                strcpy(pMove->data.name,newSkipNode->data.name);
                pMove->data.chinese = newSkipNode->data.chinese;
                return;
            }
            if (pMove == list->headNode && newSkipNode->data.hash < pMove->data.hash)    //且在头节点
            {
                newSkipNode->Rnext = pMove;
                newSkipNode->next = pMove->next;
                list->headNode = newSkipNode;
                pMove->next = NULL;
                return;
            }
            if (pMove->Rnext == NULL)   //若pMove右节点为空
            {
                if (newSkipNode->data.hash > pMove->data.hash)      //若pMove的hash值小于插入节点的
                {
                    pMove->Rnext = newSkipNode;
                    return;
                }
                else        //若pMove的hash值大于插入节点的
                {
                    newSkipNode->next = pMove->next;    //不在头节点
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    return;
                }
            }
            else
            {
                struct skipTable *pRMove = pMove;
                if (newSkipNode->data.hash < pMove->data.hash)
                {
                    newSkipNode->next = pMove->next;
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    return;
                }
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
    while (rMove != NULL)
    {
        printf(" 学号|名字|分数|");
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
                "";
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
                if (pFMove != NULL)
                    pFMove = pFMove->next;
                if (pMove == list->headNode->next)
                    pFMove = list->headNode;
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
        if (dataHash != pMove->data.hash % list->divisor)       //没找到节点
        {
            printf("未找到指定元素,无法删除");
            return;
        }
        if (hash == pMove->data.hash)   //要删除的元素在纵列的头节点
        {
            if (pMove->Rnext == NULL)       //只有一个节点
            {
                pFMove->next = pMove->next;
                free(pMove);
                pMove = NULL;
                return;
            }
            else        //纵列还有其他节点
            {
                pMove->Rnext->next = pMove->next;
                pFMove->next = pMove->Rnext;
                free(pMove);
                pMove = NULL;
                return;
            }
        }
        else
        {
            pRMove = pRMove->Rnext;
            while (pRMove->next != NULL && pRMove->data.hash != hash)   //寻找
            {
                pMove = pMove->Rnext;
                pRMove = pRMove->Rnext;
            }
            if (pRMove->data.hash != hash)  //没找到
            {
                printf("未找到指定元素,无法删除");
                return;
            }
            else
            {
                pMove->Rnext = pRMove->Rnext;
                free(pRMove);
                pRMove = NULL;
                return;
            }
        }
    }
}

//文件读取
void fileRead(struct skipList *list)
{
    //暂存信息
    struct dataType temp;
    //打开文件
    FILE *fp = fopen("student's-grade.txt","r");
    //文档为空时的考虑
    if (fgetc(fp) == EOF)
    {
        printf("文档为空无法读取\n");
        return;
    }
    
    //开始读取
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

//文件写入
void fileWrite(struct skipList *list)
{
    //打开文件
    FILE *fp = fopen("student's-grade.txt","w");
    //若无数据
    if (list->headNode == NULL)
    {
        printf("没有数据无法写入");
        return;
    }
    //指针重置
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

//操作帮助
void help()
{
    printf("文件的读取和写入会在程序当前目录下生成一个叫student's-grade.txt的文件\n");
    printf("文件的读取会自动排序\n");
    printf("2021/12/24\n");
}

//操作菜单
void screen()
{
    printf("---成绩管理系统v0.1---\n");
    printf("------0.退出程序------\n");
    printf("------1.插入成员------\n");
    printf("------2.打印跳表------\n");
    printf("------3.删除成员------\n");
    printf("------4.文件读取------\n");
    printf("------5.文件写入------\n");
    printf("------6.操作帮助------\n");
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