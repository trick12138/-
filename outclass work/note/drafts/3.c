#include<stdio.h>
int main()
{
    int weight,high;
    printf("请输入身高 体重");
    scanf("%d %d",&high,&weight);
    if (high - 110 == weight)
        printf("标准体重");
    else if (((high - 110) - weight) > 5)
        printf("过胖");
    else if (weight - high + 110 > 5)
        printf("过瘦");
    return 0;
}