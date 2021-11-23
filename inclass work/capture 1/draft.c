#include<stdio.h>
int main()
{
    //使用指针遍历一维数组
    int *pa;
    int b[10]={1,2,3,4,5,6,7,8,9,10};
    pa = b;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",*(pa + i));
    }
    printf("\n");
    //使用指针遍历二维数组
    int c[5][5]=
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {}
    }
    pa = c;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; i++)
        {
            printf("%d ",*((*pa + i)+j));
        }
        
    }
    
}