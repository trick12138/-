#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
 int a[6] = { 0 };
 int i, j;
    srand((unsigned)time(NULL));   //随机播种
    for (i = 0; i <= 5;i++)
    {
        for (; a[i] == 0;)
        {
            a[i] = rand() % 7;
        }
        for (j = 0; j < i;)
            if (i == 0)
            {
                break;
            }
            else
            {
                if (a[i] == a[j])
                {
                    a[i] = rand() % 7;
                }
                else
                {
                    j++;
                }
                j++;
            }
    }
    printf("hsb=%d\n", a[0]);
    printf("yxw=%d\n", a[1]);
    printf("lw=%d\n", a[2]);
    printf("ssl=%d\n", a[3]);
    printf("hd=%d\n", a[4]);
    printf("zjr=%d\n", a[5]);
    return 0;
}
//职位  查找资料 1 2 3 演讲 4 ppt 5 6