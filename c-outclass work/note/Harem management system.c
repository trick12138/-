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

//修改成员信息
void modefyInformationByname(struct Node *headNode,char name[20])
{
    struct Node *frountNode = headNode;
    struct Node *pMove = headNode->next;
    struct Node temp;
    printf("请输入你要修改的信息\n1.名字\n2.性别\n3.年龄\n4.等级\n");
    int a;
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        printf("请输入的名字\n");
        scanf("%s",temp.name);
        strcpy(pMove->name,temp.name);
        break;
    case 2:
        printf("请输入性别\n");
        scanf("%s",temp.sex);
        strcpy(pMove->sex,temp.sex);
        break;
    case 3:
        printf("请输入年龄\n");
        scanf("%d",temp.age);
        pMove->age = temp.age;
        break;
    case 4:
        printf("请输入等级\n");
        scanf("%s",temp.level);
        strcpy(pMove->level,temp.level);
        break;
    default:
        printf("你输入的信息有误\n");
        break;
    }
}

//删除全部
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
    printf("-------------4.修改成员----------------\n");
    printf("-------------5.文件读写----------------\n");
    printf("-------------6.删除全部----------------\n");
    printf("-------------7.操作帮助----------------\n");
}

//文件读取
void fileRead(struct Node *List)
{
    //暂存
    struct Node temp;
    //打开文件
    FILE *fp = fopen("girls'information.txt","a+");
    //读取功能
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
    //关闭文件
    fclose(fp);
}

//文件写入
void fileWrite(struct Node *List)
{
    //打开文件
    FILE *fp = fopen("girls'information.txt","a+");
    //指针重置
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
    //关闭文件
    fclose(fp);
}

//文件读写
void filePreservation(struct Node *List)
{
    //选择
    int a;
    printf("请问是要读取还是写入呢1.读取,2.写入\n");
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

//操作帮助
void helpMenu()
{
    printf("先用文件读写将文件内容加载至内存,再进行操作\n");
    printf("若想在文件中新增成员请先读取后,再删除全部,再新增成员\n");
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
    case 4:
        printf("请输入你要修改的人的名字\n");
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
        printf("你输入的信息有误\n");
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