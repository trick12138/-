/*
    主要使用C语言实现dequeue
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX 10

using namespace std;

class nuQueue
{
public:
    nuQueue() :frount(-1) ,rear(-1) ,Size(0){}
    int size()
    {
        return Size;
    }
    void push(char cha)
    {
        if (Size == MAX)
        {
            cout << "队满,无法入队" << endl;
            return;
        }
        queue[++rear % 10] = cha;
        ++Size;
    }
    void pop()
    {
        if (Size == 0)
        {
            cout << "队空,无法出队" << endl;
        }
        queue[++frount % 10] = '\0';
        --Size;
    }
    void upsetDown()
    {
        char *newQueue = new char[10];
        for (int i = rear % 10 ,j = 0; i != frount % 10 ;i--)
        {
            newQueue[j++] = queue[i];
        }
        memcpy(queue,newQueue,sizeof(queue));
        delete[] newQueue;
        frount = -1;
        rear = Size;
    }
    char *begin()
    {
        return queue + frount % 10;
    }
    char *end()
    {
        return queue + rear % 10 + 1;
    }
private:
    char queue[MAX];
    int frount;
    int rear;
    int Size;
};

int main()
{
    nuQueue Queue;
    for (int i = 0; i < 6; i++)
    {
        Queue.push(i + 'a');
    }
    for (auto v : Queue)
    {
        cout << v << '\t';
    }
    cout << endl;
    Queue.pop();
    Queue.upsetDown();
    for (auto v : Queue)
    {
        cout << v << '\t';
    }
    system("pause");
    return 0;
}