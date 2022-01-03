#include <stdio.h>
#include <stdlib.h>
struct position    //坐标
{
    int row;    //行
    int cols;   //列
};


struct position step[100];  //步骤记录
int stackTop = -1;  //栈顶标记
int **maze = NULL;  //创建迷宫
int size = 0;  //迷宫大小

int **makeArray(int row,int cols)   //用二级指针创建二维数组
{
    int **Array = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < cols; i++)
    {
        Array[i] = (int *)malloc(sizeof(int) * cols);
    }
    return Array;
}

//用户输入一个迷宫
void createMaze()
{
    printf("输入迷宫大小:");
    scanf("%d",&size);
    //创建迷宫
    maze = makeArray(size + 2,size + 2);
    printf("输入迷宫\n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    for (int i = 0; i < (size + 1); i++)  //加边框
    {
        maze[0][i] = maze[size + 1][i] = 1;
        maze[i][0] = maze[i][size + 1] = 1;
    }
    
}

//寻路
int findPath()
{
    struct position offset[4];  //四种方向
    //向右边走
    offset[0].row = 0;
    offset[0].cols = 1;
    //向下走
    offset[1].row = 1;
    offset[1].cols = 0;
    //向左走
    offset[2].row = 0;
    offset[2].cols = -1;
    //向上走
    offset[3].row = -1;
    offset[3].cols = 0; 
    
    //选定入口
    struct position here = {1,1};
    //走迷宫记录所走的路径
    maze[1][1] = 1;
    int option = 0;     //下一个移动方向
    int endOption = 3;  //终止方向

    while(here.row != size || here.cols != size)
    {
        //相邻的方向做移动
        int rowNum , colsNum; //记录下标变化
        while(option <= endOption)
        {
            rowNum = here.row + offset[option].row;
            colsNum = here.cols + offset[option].cols;
            //一旦确定方向可走,就跳出循环
            if (maze[rowNum][colsNum] == 0)
                break;
            option++;  //不能走换方向测试
        }
        if (option <= endOption)  //能走就走
        {
            //走到下一步
            step[++stackTop] = here;
            //改变当前位置
            here.row = rowNum;
            here.cols = colsNum;
            //走过的路标记
            maze[rowNum][colsNum] = 1;
            option = 0;  //起始方向为0
        }
        else  //option = 4
        {
            if (stackTop = -1)
            {
                return 0;
            }
            //出栈的方式回到上一步
            struct position next = step[stackTop];
            stackTop--;
            if (next.row == here.row)  //行没变左右走的
            {
                option = 2 + next.cols - here.cols;  // 
            }
            else
            {
                option = 3 + next.row - here.row;    //
            }
            here = next;  //退回上一步
        }
    }
    return 1;
}

//打印路径
void printPath()
{
    printf("路径方式:\n");
    struct position curPos;
    while(stackTop != -1)
    {
        curPos = step[stackTop];
        stackTop--;
        printf("<--(%d,%d)",curPos.row,curPos.cols);
    }
    printf("\n");
}

int main()
{
    createMaze();
    if (findPath())
    {
        printPath();
    }
    else
    {
        printf("没有路径\n");
    }
    system("pause");
    return 0;
}