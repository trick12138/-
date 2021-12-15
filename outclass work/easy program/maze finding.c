#include <stdio.h>
#include <stdlib.h>
int **mackMazeSize(int row,int cols);


struct mazeNode
{
    int row;    //行
    int cols;    //列
};

int cols = 0,row = 0;    //全局变量列行
int **ArrayMaze = NULL;  //创建迷宫
struct mazeNode step[100];    //记录步骤
int stackTop = -1;    //栈顶标记

//从文件中读入迷宫
void loadMaze()
{
    FILE *fp = fopen("maze.txt","r");
    int c;
    char ch;
    while(fscanf(fp,"%c",&ch) != EOF)
    {
        if (ch == '\n')
            break;
        cols++;
    }
    cols /= 2;
    cols++;
    printf("列宽=%d",cols);
    fseek(fp,0,SEEK_SET);
    while((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
            row++;
    }
    row++;
    printf("行数=%d\n",row);
    //从文件中读入
    fseek(fp,0,SEEK_SET);
    ArrayMaze = mackMazeSize(row,cols);  //创建迷宫
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(fp,"%d",&ArrayMaze[i][j]);
        }
        
    }
    //遍历检测
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d",ArrayMaze[i][j]);
        }
        printf("\n");
    }
}

void findingPath()    //找路
{
    struct mazeNode offset[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    struct mazeNode here = {1,1};    //选定入口
    ArrayMaze[1][1] = 1;
    int option = 0;     //选定方向
    int endOption = 3;      //最终方向
    while (here.cols != (cols - 1) && here.row != (row - 1))
    {
        //相邻方向做移动
        int rowNum,colsNum;     //记录行列变化
        while (option <= endOption)
        {
            rowNum = here.row + offset[option].row;
            colsNum = here.cols + offset[option].cols;
            if (ArrayMaze[rowNum][colsNum] == 0)
                break;
            option++;       //不能走换方向测试
        }
        //走
        if (option <= endOption)    //找到就走
        {
            step[++stackTop] = here;
            here.row = rowNum;
            here.cols = colsNum;
            ArrayMaze[rowNum][colsNum] = 1;
            option = 0;
        }
        else   //没找到就不走
        {
            if(stackTop == -1)
                return;
            struct mazeNode next = step[stackTop--];
            //方向的处理
            option = 0;
            here = next;    //不走
        }
        
    }
     
}

//出栈的方式打印出每一步
void printStep()
{
    printf("路径方式:\n");
    struct mazeNode curPos;
    while (stackTop != -1)
    {
        curPos = step[stackTop--];
        printf("(%d,%d)-->",curPos.row,curPos.cols);
    }
}

int **mackMazeSize(int row,int cols)    //创建数组为迷宫载入做准备
{
    int **Array = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < cols; i++)
    {
        Array[i] = (int *)malloc(sizeof(int) * cols);
    }
    return Array;
}

int main()
{
    loadMaze();
    findingPath();
    printStep();
    system("pause");
    return 0;
}