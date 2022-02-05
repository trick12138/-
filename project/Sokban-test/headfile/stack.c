#include <stdio.h>
#include <stdlib.h>

typedef struct dataType
{
    int x;                              //人物的位置
    int y;
    int data;
}DATA,*LPDATA;

typedef struct stackSPOS
{
    struct dataType data[3];             //数据域
    struct stackSPOS *next;              //指向下一个结点 
}SPOS,*LPSPOS;

typedef struct stack
{
    struct stackSPOS *headSPOS;           //头结点指向栈
}STACK,*LPSTACK;

LPSTACK createStack()                   //创建栈
{
    LPSTACK newStack = (LPSTACK)malloc(sizeof(STACK));
    newStack->headSPOS = NULL;
    return newStack;
}

LPSPOS createStackSPOS(DATA SPOSData[3])      //创建栈的结点
{
    LPSPOS newStackSPOS = (LPSPOS)malloc(sizeof(SPOS));
    for (int i = 0; i < 3; i++)
    {
        newStackSPOS->data[i] = SPOSData[i];
    }
    newStackSPOS->next = NULL;
    return newStackSPOS;
}

void push(LPSTACK stack,DATA SPOSData[3])   //入栈
{
    LPSPOS newStackSPOS = createStackSPOS(SPOSData);
    newStackSPOS->next = stack->headSPOS;
    stack->headSPOS = newStackSPOS;
}

void pop(LPSTACK stack)                 //出栈
{
    //安全性考虑
    if (stack->headSPOS == NULL)
        return;
    LPSPOS SPOS = stack->headSPOS;
    stack->headSPOS = stack->headSPOS->next;
    free(SPOS);
    SPOS = NULL;
}