#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand((unsigned)time(NULL));
    int a[4] = {0,0,0,0};
    for (int i = 0; i < 4;)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                j++;
                continue;
            }
            else
            {
                if(a[i] == a[j] || a[i] == 0 || a[i] == 42 || a[i] == 43 || a[i] == 40 || a[i] == 39 || a[i] == 45 || a[i] == 35)
                {
                    a[i] = rand()%45;
                }
                else
                {
                    i++;
                    continue;
                }
            }
        }
    }
    printf("ÃèÊöÕßÊÇ%d\n",a[0]);
    printf("ÈÃ%d,%d,%dÀ´²Â",a[1],a[2],a[3]);
    getchar();
    return 0;
}