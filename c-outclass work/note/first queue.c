/*
    优先队列:更具优先权选择出队的元素
    队列容量
    优先权-->数字,代表任务量,权重
    按照特殊值去排序(选择排序)
        算法调度:
        短作业优先法
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
//数据由两部分组成
//数据本身+权值(关键字)
typedef struct data
{
    int priority;  //权值
    int element;    //数据本身
}DataType;

//队列
struct priQueue
{
    int sizeQueue;    //队列当前元素
    DataType queue[MAX];    //队列容量
};

//创建优先队列
struct priQueue *createQueue()
{
    struct priQueue *lpQueue = (struct priQueue*)malloc(sizeof(struct priQueue));
    lpQueue->sizeQueue = 0;
    //数组的初始化
    memset(lpQueue->queue,0,sizeof(DataType)*MAX);
    return lpQueue;
};

//万金油函数
int empty(struct priQueue *lpQueue)
{
    return lpQueue->sizeQueue != 0;
}
int size(struct priQueue *lpQueue)
{
    return lpQueue->sizeQueue;
}

//入队操作:从文件中读出来,入队
void push(struct priQueue *lpQueue,DataType curData)
{
    if (lpQueue->sizeQueue == MAX)
    {
        //安全性问题描述清楚点
        printf("队列满了!无法入队\n");
        return;
    }
    else
    {
        lpQueue->queue[lpQueue->sizeQueue++] = curData;
    }
}

//出队
void pop(struct priQueue *lpQueue,DataType *popData)
{
    if (lpQueue->sizeQueue == 0)
    {
        printf("没有元素,无法出队\n");
        return;
    }
    else
    {
        DataType minData;    //寻找最小权值的数据
        //假设第一个是最小的
        minData = lpQueue->queue[0];
        int minIndex = 0;    //记录下标
        for (int i = 1; i < lpQueue->sizeQueue; i++)
        {
            if (lpQueue->queue[i].priority < minData.priority)
            {
                minData = lpQueue->queue[i];
                minIndex = i;
            }
            
        }
        //popData:指针  lpQueue->queue[minIndex]:结构体
        *popData = lpQueue->queue[minIndex];
        //调整队列,做一个伪删除
        for (int i = minIndex; i < lpQueue->sizeQueue; i++)
        {
            lpQueue->queue[i] = lpQueue->queue[i + 1];
        }
        lpQueue->sizeQueue--;
    }
}

int main()
{
    struct priQueue *lpQueue = createQueue();
    DataType readData;
    FILE *fp = fopen("task.txt","r");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return 0;
    }
    while (fscanf(fp,"%d,%d\n",&readData.priority,&readData.element) != EOF);
    {
        push(lpQueue,readData);
    }
    fclose(fp);
    int workIndex = 1;
    printf("\t序号\t编号\t工作量\n");
    while (empty(lpQueue))
    {
        pop(lpQueue,&readData);
        printf("\t%d\t%d\n",workIndex,readData.element,readData.priority);
        workIndex++;
    }
    system("pause");
    return 0;
}