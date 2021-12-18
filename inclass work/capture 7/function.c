#include <stdio.h>
int judgeLeapYear(int year)
{
    if (year%4==0&&year%100!=0||year%400==0)
        return 1;
    else
        return 0;
}

int caculateDays(int month,int day,int judge)
{
    int sum;
    int days[2][12] = 
    {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    for (int i = 0; i < (month-1); i++)
    {
        sum += days[judge][i];
    }
    sum += day;
    return sum;
}

int main()
{
    int year,month,day,judge;
    printf("请输入年月日");
    scanf("%d %d %d",&year,&month,&day);
    if (judgeLeapYear(year))
    {
        printf("该年是闰年\n");
        judge = 1;
    }
    else
    {
        printf("该年不是闰年\n");
        judge = 0;
    }
    printf("是该年的第%d天",caculateDays(month,day,judge));
    return 0;
}