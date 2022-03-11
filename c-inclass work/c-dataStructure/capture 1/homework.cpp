#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

#define N 10     //page 72-2   
#define N2 20       //page 73-12

using namespace std;

/*
    page 27 t7
    该函数修改y,使y等于y乘以x的n次方
*/
void fun(double &y,double x,int n)
{
    y = x;
    while(n > 1)
    {
        y = y * x;
        n--;
    }
}

/*
    page 27-8 (1)
    求一个n阶二维数组的所有元素之和
    返回和
    时间复杂度为O(n的平方)
*/
int sum(int **array,int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum = sum + array[i][j];
    return sum;
}

/*
    page 27-10 t8 (2)
    对于输入的任意三个整数,讲它们按照小到大的顺序输出
    时间复杂度为O(1)
*/
void sortPrint()
{
    int array[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&array[i]);
    }
    sort(array, array + 3, less<int>());
    for (int i = 0; i < 3; i++)
    {
        printf("%d",array[i]);
    }
}

/*
    page 27-10 (3)
    对于输入的任意n个整数,输出其中最大和最小的元素
    时间复杂度为O(n)
*/
void printMaxAndMin()
{
    int n;
    printf("请输入你要输入的元素个数:\n");
    scanf("%d",&n);
    int array[n];
    printf("请输入元素:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    int max = array[0],min = array[0];
    for (int i = 0; i < n; i++)
    {
        if (max < array[i])
            max = array[i];
        if (min > array[i])
            min = array[i];
    }
    printf("max=%d,min=%d",max,min);
}

/*
    page 72-8
    假设一个顺序表L中的所有元素为整数,设计一个算法调整该顺序表,使其中所有小于零的元素放在所有大于零的元素的前面
*/
struct LinkNode
{
    int data[N];
    int lenth;
};
void sortWith0(LinkNode *&L)
{
    //找到0并且记录下标
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (L->data[i] == 0)
        {
            index = i;
        }
    }
    
    //排序
    for (int i = 0,j = N - 1; i != j;)
    {
        if (L->data[i] > 0)
        {
            L->data[index] = L->data[i];
            index = i;
        }
        else if(L->data[i] < 0)
        {
            i++;
            continue;
        }
        if (L->data[j] < 0)
        {
            L->data[index] = L->data[j];
            index = j;
        }
        else if (L->data[j] > 0)
        {
            j--;
            continue;
        }
        i++;
        j--;
    }
    L->data[index] = 0;
}

void initTestList(LinkNode *&L)
{
    LinkNode *newNode = (LinkNode *)malloc(sizeof(struct LinkNode));
    if (L == NULL)
    {
        L = newNode;
        for (int i = 0; i < N;)
        {
            L->data[i] = rand() % 100 - 50;
            if (L->data[i] == 0)
                continue;
            i++;
        }
    }
    L->data[rand() % 10] = 0;
}

void printTestList(LinkNode *&L)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ",L->data[i]);
    }
    
}

/*
    page 72-12
    设计一个算法,将一个带头结点得数据域依次为a1,a2,...an(n>=3)的单链表
    的所有结点逆置,即第一个结点的数据域变为an,第二个结点的数据域变为an-1
    尾结点的数据变为a1
*/
struct Node
{
    int data;
    struct Node *next;
};
//队列
int stack[N2];
int stackTop = -1;

struct Node* createList()
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    return newNode;
}

struct Node* createNode()
{
    static int n = 0;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ++n;
    newNode->next = NULL;
    return newNode;
}

void initListNode(struct Node *headNode)
{
    for (int i = 0; i < N2; i++)
    {
        struct Node *newNode = createNode();
        newNode->next = headNode->next;
        headNode->next = newNode;
    }
}

void initListNodeRandom(struct Node *headNode)
{
    for (int i = 0; i < N2; i++)
    {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = rand() % 100;
        newNode->next = headNode->next;
        headNode->next = newNode;
    }
}

void push(struct Node *pushNode)
{
    stack[++stackTop] = pushNode->data;
}

//用队列去进行倒转
void upsetdownTheList(struct Node *&headNode)
{
    if (headNode == NULL)
        return;
    //入队
    struct Node *pMove = headNode->next;
    while(pMove)
    {
       push(pMove);
       pMove = pMove->next;
    }
    //先删除原来的链表
/*     struct Node *pFMove = pMove;
    pMove = headNode->next;
    while (pMove != NULL)
    {
        pFMove = pMove;
        pMove = pMove->next;
        free(pFMove);
    } */
    //然后出栈
    pMove = headNode->next;
    while (stackTop != -1)
    {
        pMove->data = stack[stackTop--];
        pMove = pMove->next;
    }
}

/*
    page 73-15 设一个带头结点的单链表L,结点的结构为(data,next),其中data为整数元素,next为后记结点
    的指针,设计一个算法,首先按递减次序输出该单链表中各节点的数据元素,然后释放所有结点的储存空间,
    并要求算法的空间复杂度为O(1)
*/

void printAndDelete(struct Node *&headNode)
{
    struct Node *pMove = headNode->next;
    //入栈
    stackTop = -1;
    while(pMove)
    {
        stack[++stackTop] = pMove->data;
        pMove = pMove->next;
    }
    //给栈排序
    for (int i = 0; i < N2; i++)
        for (int j = 0; j < N2 - i; j++)
        {
            if (stack[j] > stack[j + 1])
            {
                stack[j] = stack[j + 1] + stack[j];
                stack[j + 1] = stack[j] - stack[j + 1];
                stack[j] = stack[j] - stack[j + 1];
            }
        }
    //打印栈
    for (int i = N2 - 1; i > 0; i--)
    {
        printf("%d ",stack[i]);
    }
    //销毁原来的单链表
    pMove = headNode->next;
    struct Node *pFMove = headNode;
    while (pMove)
    {
        free(pFMove);
        pFMove = pMove;
        pMove = pMove->next;
    }
    headNode->next = NULL;
}

void printList(struct Node *headNode)
{
    if (headNode == NULL)
        return;
    struct Node *pMove = headNode->next;
    while(pMove)
    {
        printf("%d ",pMove->data);
        pMove = pMove->next;
    }
}

int main()
{
    //用于测试page 72-8
    /* srand(time(NULL));
    LinkNode *L = NULL;
    initTestList(L);
    printTestList(L);
    putchar('\n');
    sortWith0(L);
    printTestList(L); */
    //用于测试page 72-12
/*     struct Node *headNode = createList();
    initListNode(headNode);
    printList(headNode);
    putchar('\n');
    upsetdownTheList(headNode);
    printList(headNode); */
    //用于测试page 72-15
/*     struct Node *headNode = createList();
    initListNodeRandom(headNode);
    printAndDelete(headNode); */
    return 0;
}