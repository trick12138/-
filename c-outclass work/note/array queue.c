#include <stdlib.h>
#include <stdio.h>
#define MAX 10
/*
    FIFO:first in first out

*/
struct queue
{
    int *queueMemory;        //队列容量-->数组
    int frountPos;      //队头元素下标
    int tailPos;       //队尾元素下标
};

struct queue *createQueue()
{
    struct queue *lpQueue = (struct queue*)malloc(sizeof(struct queue));
    //描述最初的状态
    //数组当队列,指针变成一维数组
    lpQueue->queueMemory = (int *)malloc(sizeof(int) * MAX);
    lpQueue->frountPos = lpQueue->tailPos = -1;
    return lpQueue;
}

//入队操作:队尾往后挪就可以了
void push(struct queue *lpQueue,int data)
{
    //用数组一定判断是否满了
    if (lpQueue->tailPos == MAX-1)
    {
        printf("队满,无法入队\n");
        return;
    }
    lpQueue->tailPos += 1;
    lpQueue->queueMemory[lpQueue->tailPos] = data;
}

//出队操作,获取对头元素
int pop(struct queue *lpQueue)
{
    if (lpQueue->frountPos == lpQueue->tailPos)
    {
        printf("队尾为空,无法出队");
        return -1;
    }
    return lpQueue->queueMemory[++lpQueue->frountPos];
}

int empty(struct queue *lpQueue)
{
    return lpQueue->frountPos != lpQueue->tailPos;
}

int main()
{
    struct queue *lpQueue = createQueue();
    for (int i = 0; i < 10; i++)
    {
        push(lpQueue,i);
    }
    while(empty(lpQueue))
    {
        printf("%d\t",pop(lpQueue));
    }
    printf("\n");
    //数组队列不用结构体封装,而是直接使用数组封装
    //逆序整数
    int arrayQueue[10];
    int frount = 0;
    int tail = -1;
    int intnum = 12345678;
    while(intnum)
    {
        //入队操作
        arrayQueue[++tail] = intnum % 10;
        intnum /= 10;
    }
    printf("该数的逆序结果为");
    while(frount != tail + 1)
    {
        printf("%d",arrayQueue[frount++]);
    }
    system("pause");
    return 0;
}