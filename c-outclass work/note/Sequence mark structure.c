/*
线性结构:顺序表
    数据结构
    顺序表:
        顺序表的内存
        顺序表的索引-->数组下标
*/

#include <stdlib.h>
#include <stdio.h>
struct linerList
{
    char *element;       //以储存char类型的数据
    char arrayLength;    //顺序表的最大长度
    int listSize;        //顺序表当前的元素个数
};

struct linerList *createList(int capacity)
{
    //安全考虑
    if (capacity < 1)
    {
        printf("创建顺序表失败\n");
        return 0;
    }
    struct linerList *list = (struct linerList*)malloc(sizeof(struct linerList));
    list->arrayLength = capacity;
    list->element = (char *)malloc(sizeof(list->arrayLength));
    list->listSize = 0;
    return list;
}

//插入元素
void insertElement(struct linerList *list,int theIndex,int theElement)
{
    //1.索引无效
    if (theIndex < 0 || theIndex > list->listSize)
    {
        printf("索引无效!\n");
        return;
    }
    //2.插入的索引正好等于数组下标
    if (list->listSize == list->arrayLength)
    {
        //扩充数组  再去储存
        
    }
    //3.
}

int main()
{
    
    return 0;
}