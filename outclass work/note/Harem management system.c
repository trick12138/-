#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[20];//姓名
    char sex[4];//性别
    int age;//年龄
    char level[20];//等级
    struct Node *next;
};

//创建表头
struct Node *createNodeHead()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

//创建节点
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

//插入节点
void insertByHead(struct Node *headNode,char name[20],char sex[4],int age,char level[20])
{
    struct Node *newNode = createPosNode(name,sex,age,level);
    newNode->next = headNode->next;
    headNode->next = newNode;
}

//删除成员
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
        printf("未找到指定位置,无法删除");
    }
    pMove = NULL;
}

//打印
void printList(struct Node *headNode)
{
    struct Node *pMove = headNode->next;
    printf("名字  性别  年龄  等级\n");
    while(pMove != NULL)
    {
        printf("%s  %s  %d  %s\n",pMove->name,pMove->sex,pMove->age,pMove->level);
        pMove = pMove->next;
    }
}

//菜单
void screen()
{
    printf("-----------后宫管理系统v0.0.1----------\n");
    printf("-------------0.退出程序----------------\n");
    printf("-------------1.插入成员----------------\n");
    printf("-------------2.打印列表----------------\n");
    printf("-------------3.删除成员----------------\n");
}

//选择
void select(struct Node *List)
{
    int a;
    //暂存信息
    struct Node girls;
    scanf("%d",&a);
    switch (a)
    {
    case 0:
        system("pause");
        exit(0);
        break;
    case 1:
        printf("请输入名字，性别，年龄，等级\n");
        scanf("%s %s %d %s",girls.name,girls.sex,&girls.age,girls.level);
        insertByHead(List,girls.name,girls.sex,girls.age,girls.level);
        break;
    case 2:
        printList(List);
        break;
    case 3:
        printf("请输入你要删除的人的名字\n");
        scanf("%s",girls.name);
        deleteByName(List,girls.name);
        break;
    default:
        break;
    }
}

int main()
{
    //创建表头
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