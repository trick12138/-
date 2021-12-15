#include <stdio.h>
#include <stdlib.h>
//节点,用链表的尾插法创建队列
struct Node
{
    int data;
    struct Node *next;
};

//创建节点
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//队列属性:对头和队尾   万金油参数size
struct queue
{
    int sizeQueue;
    //链式结构实现：结构体指针
    //数组实现,下标
    struct Node *frountNode;   //对头指针指向头节点
    struct Node *tailNode;    //队尾指针指向尾节点
};

//使用一个东西表示整个队列
//描述最初状态
struct queue *createQueue()
{
    struct queue *lpQueue = (struct queue*)malloc(sizeof(struct queue*));
    lpQueue->sizeQueue = 0;
    lpQueue->frountNode = lpQueue->tailNode = NULL;
    return lpQueue;
};

//万金油参数
int size(struct queue *lpQueue)
{
    return lpQueue->sizeQueue;
}

//返回1表示不为空,返回0表示为空
int empty(struct queue *lpQueue)
{
    return lpQueue->sizeQueue != 0;
}

//入队操作
void push(struct queue *lpQueue,int data)
{
    struct Node *newNode = createNode(data);
    if (lpQueue->sizeQueue == 0)   //队列为空
        lpQueue->frountNode = newNode;
    else  //队列不为空
        //排队的方式
        //新的数据要放在队尾
        lpQueue->tailNode->next = newNode;
        //队尾要发生改变,队尾要变成新的节点
    lpQueue->tailNode = newNode;
    lpQueue->sizeQueue++;
}

//出队操作:表头法删除:无头链表
void pop(struct queue *lpQueue)
{
    //删除要判断是否为空
    if (lpQueue == 0)
    {
        printf("无法出队!");
        return;
    }
    //先保存下一个节点
    struct Node *nextNode = lpQueue->frountNode->next;
    //然后删除头节点
    free(lpQueue->frountNode);
    //把头节点的指针指向新的头节点
    lpQueue->frountNode = nextNode;
    lpQueue->sizeQueue--;
}

//获取对头元素
int frount(struct queue *lpQueue)
{
    if (lpQueue->sizeQueue == 0)
    {
        printf("队列为空,无法出队\n");
        system("pause");
        exit(0);
    }
    return lpQueue->frountNode->data;
}


int main()
{
    struct queue *lpQueue = createQueue();
    for (int i = 0; i < 10; i++)
    {
        push(lpQueue,i);
    }
    while (empty(lpQueue))
    {
        printf("%d\t",frount(lpQueue));
        pop(lpQueue);
    }

    printf("\n");
    system("pause");
    return 0;
}