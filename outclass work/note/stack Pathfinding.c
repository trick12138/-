#include <stdio.h>
#include <stdlib.h>

//位置
struct position
{
    int row;
    int cols;
};

struct position pathStack[100];    //路径记录
int stackTop = -1;    //栈顶标记
int **maze = NULL;    //迷宫地图描述
int size = 0;    //迷宫大小

int **makeArray(int row, int cols)
{
    int **array = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < cols; i++)
    {
        array[i] = (int *)malloc(sizeof(int)*cols);
    }
    return array;
}

//用户输入一个迷宫
void createMaze()
{
    printf("输入迷宫大小:");
    scanf("%d",&size);
    maze = makeArray(size + 2,size + 2);    //加2表示边框
    printf("输入地图:\n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            scanf("%d",&maze[i][j]);
        }
        
    }
    //加边框:1表示不可走
    for (int i = 0; i < size + 1; i++)
    {
        maze[0][i] = maze[size + 1][i] = 1;    //上下两行
        maze[i][0] = maze[i][size + 1] = 1;    //左右两列
    }
}

//找路径
int findPath()
{
    //四个数字表示四个值,表示偏移量
    struct position offset[4];    //0-3表示四个方向
    //往右边走
    offset[0].row = 0;
    offset[0].cols = 1;
    //往下面走
    offset[1].row = 1;
    offset[1].cols = 0;
    //往左边走
    offset[2].row = 0;
    offset[2].cols = -1;
    //往上面走
    offset[3].row = -1;
    offset[3].cols = 0;
    
    //选定入口
    struct position here = {1,1};
    //走迷宫:记录走过的路径
    maze[1][1] = 1;
    int option = 0;       //下一个移动方向
    int endOption = 3;    //终止方向

    while (here.row != size || here.cols != size)
    {
        //相邻的方式做移动
        int rowNum,colsNum;    //记录下标变化
        while (option <= endOption)
        {
            //行列的变化=原位置+偏移值,偏移值由方向决定
            rowNum = here.row + offset[option].row;
            colsNum = here.cols + offset[option].cols;
            //一旦确定方向可以走,就需要去下一步 
            if (maze[rowNum][colsNum] == 0)
                break;
            //不能走换方向测试
            option++;
        }
        //可以移动
        if (option <= endOption)
        {
            //走到下一格
            pathStack[++stackTop] = here;
            //改变当前位置
            here.row = rowNum;
            here.cols = colsNum;
            //走过的路径标记
            maze[rowNum][colsNum] = 1;
            option = 0;    //起始方向置为0
        }
        else   //option = 4
        {
            //回到上一步去
            if (stackTop == -1)
                return 0;
            //出栈方式回退到上一步
            struct position next = pathStack[stackTop];
            stackTop--;
            //方向的处理
            if (next.row == here.row)    //行没变,左右走的
            {
                option = 2 + next.cols - here.cols;
            }
            else    //列没变,上下走的
            {
                option = 3 + next.row - here.row;
            }
            here = next;    //回退到上一步
        }

    }
    return 1;
}

//打印路径
void printPath()
{
    printf("路径方式:\n");
    struct position curPos;
    while (stackTop != -1)
    {
        curPos = pathStack[stackTop];
        stackTop--;
        printf("(%d,%d)-->",curPos.row,curPos.cols);
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
        printf("没有路径!\n");
    }
    system("pause");
    return 0;
}