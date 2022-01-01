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

//创建跳表节点
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
        if (dataHash < pMove->data.hash % list->divisor)    //若插入的元素hash值比第一个节点还小
        {
            newSkipNode->next = list->headNode;
            list->headNode = newSkipNode;
            list->size++;
            return;
        }
        while (pMove->next != NULL && dataHash >= pMove->next->data.hash % list->divisor )  //查找元素
        {
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
            if (pMove == list->headNode && newSkipNode->data.hash < pMove->data.hash)    //且在头节点,hash值小于头节点
            {
                newSkipNode->Rnext = pMove;
                newSkipNode->next = pMove->next;
                list->headNode = newSkipNode;
                pMove->next = NULL;
                list->size++;
                return;
            }
            if (pMove->Rnext == NULL)   //若pMove右节点为空
            {
                if (newSkipNode->data.hash > pMove->data.hash)      //若pMove的hash值小于插入节点的
                {
                    pMove->Rnext = newSkipNode;
                    list->size++;
                    return;
                }
                else        //若pMove的hash值大于插入节点的
                {
                    newSkipNode->next = pMove->next;
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    list->size++;
                    return;
                }
            }
            else    //若pMove右节点不为空我们就去找
            {
                struct skipTable *pRMove = pMove;
                if (newSkipNode->data.hash < pMove->data.hash)  //新节点的hash值小于pMove的
                {
                    newSkipNode->next = pMove->next;
                    newSkipNode->Rnext = pMove;
                    pFMove->next = newSkipNode;
                    pMove->next = NULL;
                    list->size++;
                    return;
                }
                while(pRMove->Rnext != NULL && newSkipNode->data.hash >= pRMove->Rnext->data.hash)  //循环查找
                {
                    if (pRMove->Rnext->data.hash == newSkipNode->data.hash)   //当找到的节点存在冲突
                    {
                        strcpy(pRMove->Rnext->data.name,newSkipNode->data.name);
                        pRMove->Rnext->data.chinese = newSkipNode->data.chinese;
                        return;
                    }
                    pRMove = pRMove->Rnext;
                }
                newSkipNode->Rnext = pRMove->Rnext;     //若pRMove到最后则插入最后
                pRMove->Rnext = newSkipNode;
                list->size++;
                return;
            }
        }
        newSkipNode->next = pMove->next;    //若pMove到最后则插入最后
        pMove->next = newSkipNode;
        list->size++;
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

    //求取hash值,做准备
    int dataHash = hash % list->divisor;
    struct skipTable *pMove = list->headNode;
    struct skipTable *pRMove = list->headNode;
    struct skipTable *pFMove = NULL;

    //先纵向查找
    if (pMove == NULL)  //判断链表是否为空
    {
        printf("未找到指定元素,无法删除");
        return;
    }
    else
    {
        if (pMove->next == NULL)    //只有一个节点
        {
            if (dataHash != pMove->data.hash % list->divisor)   //这个节点不是就算了
            {
                printf("未找到指定元素,无法删除");
                return;
            }
        }
        else    //至少两个节点
        {
            while(pMove->next != NULL && dataHash != pMove->data.hash % list->divisor)    //纵向查找
            {
                pMove = pMove->next;
                if (pFMove != NULL)
                    pFMove = pFMove->next;
                if (pMove == list->headNode->next)
                    pFMove = list->headNode;
            }
        }
    }

    //找到节点后做删除
    if (dataHash != pMove->data.hash % list->divisor)   //如果没找到
    {
        printf("未找到指定元素,无法删除");
        return;
    }
    else    //找到了
    {
        if (pMove == list->headNode)    //找到的就在头节点
        {
            if (hash == pMove->data.hash && pMove->Rnext == NULL)   //找到的不仅在头节点且要删除的就是头节点的第一个元素且其右边没有元素
            {
                list->headNode = pMove->next;
                free(pMove);
                list->size--;
                return;
            }
            else if(hash == pMove->data.hash && pMove->Rnext != NULL)   //找到的不仅是头节点且其右边有元素
            {
                list->headNode = pMove->Rnext;
                pMove->Rnext->next = pMove->next;
                free(pMove);
                list->size--;
                return;
            }
            while (pRMove->Rnext != NULL && pRMove->data.hash != hash)   //找到的就在头节点且不是第一个节点我们就往后面找,以pMove为pRmove的前置节点
            {
                if (pMove != pRMove)
                    pMove = pMove->Rnext;
                pRMove = pRMove->Rnext;
            }
            if (hash != pRMove->data.hash || pMove == pRMove)  //没找到节点
            {
                printf("未找到指定元素,无法删除");
                return;
            }
            else    //找到了我们就做删除工作
            {
                pMove->Rnext = pRMove->Rnext;
                free(pRMove);
                list->size--;
                return;
            }
        }
        else    //找到的不在头节点
        {
            if (hash == pMove->data.hash)   //找到了且就是第一个节点
            {
                if (pMove->Rnext == NULL)   //找到了且其右边没有元素
                {
                    pFMove->next = pMove->next;
                    free(pMove);
                    list->size--;
                    return;
                }
                else    //找到了且其右边有元素
                {
                    pFMove->next = pMove->Rnext;
                    pMove->Rnext->next = pMove->next;
                    free(pMove);
                    list->size--;
                    return;
                }
            }
            else    //找到了且不在第一个节点
            {
                while(pRMove->Rnext != NULL && pRMove->data.hash != hash)
                {
                    if (pMove != pRMove)
                        pMove = pMove->Rnext;
                    pRMove = pRMove->Rnext;
                }
                if (hash != pRMove->data.hash || pMove == pRMove)  //没找到节点
                {
                    printf("未找到指定元素,无法删除");
                    return;
                }
                else    //找到了我们就做删除工作
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
    printf("2021/12/30\n");
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