#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//数据结点
typedef struct Data
{
    int no;
    char name[20];
    int depno;
    int salary;
}DATA,*LPDATA;

//结点
typedef struct Node
{
    DATA data;
    struct Node *next;
}NODE,*LPNODE;

void writeFile(LPNODE* L);

//创建一个链表结点
LPNODE createNode(LPNODE node)
{
    LPNODE newNode = (LPNODE)malloc(sizeof(NODE));
    newNode->next = NULL;
    memcpy(&newNode->data,&node->data,sizeof(DATA));
    return newNode;
}

//无头链表的头插法
void insertByHead(LPNODE *list,LPNODE node)
{
    LPNODE newNode = createNode(node);
    newNode->next = (*list);
    (*list) = newNode;
}

//1.添加成员
void add_new_node(LPNODE *list)
{
    printf("请输入你要添加的成员的信息");
    printf("职工号 名字 部门编号 薪水");
    NODE temp;
    scanf("%d %s %d %d",&temp.data.no,temp.data.name,&temp.data.depno,&temp.data.salary);
    insertByHead(list,&temp);
}

//2.显示成员
void printData(LPNODE *list)
{
    LPNODE pMove = *list;
    while (pMove)
    {
        printf("%d %s %d %d\n",pMove->data.no,pMove->data.name,pMove->data.depno,pMove->data.salary);
        pMove = pMove->next;
    }
    system("pause");
}

//按职工号从小到大排序
int sortByNo(const LPNODE p1,const LPNODE p2){ if (p1->data.no > p2->data.no) return 1; return 0; }

//按部门号
int sortByDepno(const LPNODE p1,const LPNODE p2){ if (p1->data.depno > p2->data.depno) return 1; return 0; }

//按工资号
int sortBySalary(const LPNODE p1,const LPNODE p2){ if (p1->data.salary > p2->data.salary) return 1; return 0; }

//3.排序
void sort(LPNODE *list,int (*sortAL)(const LPNODE p1,const LPNODE p2))
{
    DATA temp;

    if (*(list) == NULL && (*list)->next == NULL)
    {
        printf("只有一个或者没有结点,无法排序");
        system("pause");
        return;
    }
    
    LPNODE pFMove = (*list);
    LPNODE pMove = (*list)->next;
    int nodeCount = 0;
    while(pMove)
    {
        pMove = pMove->next;
        ++nodeCount;
    }

    pMove = (*list)->next;          //重置指针

    for (int i = 0; i < nodeCount; i++)
    {
        for (int j = i; j < nodeCount; j++)
        {
            if (sortAL(pFMove,pMove))
            {
                memcpy(&temp,&pFMove->data,sizeof(DATA));
                memcpy(&pFMove->data,&pMove->data,sizeof(DATA));
                memcpy(&pMove->data,&temp,sizeof(DATA));
            }
            pFMove = pMove;
            pMove = pMove->next;
        }
        pMove = (*list)->next;
        pFMove = (*list);
    }
}

//6.删除
void deleteByNo(LPNODE *L)
{
    int no;
    printf("请输入你要删除的学号: \n");
    scanf("%d",&no);
    LPNODE pFMove = NULL;
    LPNODE pMove = *L;
    while (pMove)
    {
        if (pMove->data.no == no)
            break;
        pFMove = pMove;
        pMove = pMove->next;
    }

    //找到了且在第一个结点
    if (pFMove == NULL && pMove->data.no == no)
    {
        free(pMove);
        pMove = NULL;
        return;
    }
    
    //其他情况 找到了
    if (pFMove != NULL && pMove != NULL)
    {
        pFMove->next = pMove->next;
        free(pMove);
        pMove = NULL;
        return;
    }

    //没找到
    printf("没找到\n");
    system("pause");
    return;
}

//7.全删
void deleteAll(LPNODE* L)
{
    LPNODE pos = NULL;
    LPNODE pMove = *L;

    int count = 0;
    while (pMove)
    {
        pos = pMove;
        pMove = pMove->next;
        free(pos);
        ++count;
    }
    *L = NULL;
    printf("一共打印了%d个数据",count);
}

//菜单显示
void menu()
{
    printf("-----------1.添加成员----------\n");
    printf("-----------2.显示成员----------\n");
    printf("---------3.按职工号排序--------\n");
    printf("---------4.按部门号排序--------\n");
    printf("---------5.按工资号排序--------\n");
    printf("-----------6.删除-------------\n");
    printf("-----------7.全删-------------\n");
    printf("-----------0.退出-------------\n");
}

//选项
void select(LPNODE* list)
{
    int a;
    printf("请输入你的选择: ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        add_new_node(list);
        break;
    case 2:
        printData(list);
        break;
    case 3: sort(list,sortByNo);
        break;
    case 4: sort(list,sortByDepno);
        break;
    case 5: sort(list,sortBySalary);
        break;
    case 0: writeFile(list);                               //把数据写入文件
        exit(0);
        break;
    case 6: deleteByNo(list);
        break;
    case 7: deleteAll(list);
        break;
    default:
        break;
    }
}

//读取文件
void readfile(LPNODE* L)
{
    int count = 0;                          //统计读取文件的个数
    NODE temp;                              //暂存数据的结点
    FILE *fp = fopen("./data.txt","rb+");   //打开文件
    char c;

    //打开文件失败
    if (fp == NULL)
    {
        printf("无法打开文件");
        system("pause");
        return;
    }
    //读取数据
    while (!feof(fp))
    {
        if (fgetc(fp) == EOF)
        {
            break;
        }
        fseek(fp,-1,SEEK_CUR);
        fread(&temp ,sizeof(NODE) ,1 ,fp);
        insertByHead(L,&temp);
        ++count;
    }

    printf("一共读取了%d组数据\n",count);
    system("pause");
    fclose(fp);
}

//写入文件
void writeFile(LPNODE* L)
{
    int count = 0;                              //统计写入文件的个数
    FILE *fp = fopen("./data.txt","wb");       //打开文件

    //打开文件失败
    if (fp == NULL)
    {
        printf("无法打开文件");
        return;
    }
    
    LPNODE pMove = *L;
    //读取数据
    while (pMove)
    {
        fwrite(pMove ,sizeof(NODE) ,1 ,fp);
        pMove = pMove->next;
        ++count;
    }

    printf("一共写入了%d组数据\n",count);
    system("pause");
}


int main()
{
    system("chcp 65001");
    LPNODE list = NULL;                             //创建无头链表
    readfile(&list);                                //从文件中读取
    while(1)
    {
        system("cls");                              //清屏
        menu();                                     //菜单打印
        select(&list);                              //选项
    }
    return 0;
}