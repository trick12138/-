#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[7]={7,7,7,7,7,7,7};
    srand((unsigned)time(NULL));   //随机播种
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<=6;++j)
        {
            if(i == j)
                continue;
            if(a[i] == a[j])
            {
                a[i] = rand()%6;   //随机数
                j = -1;
            }
            else
            {
                continue;
            }
        }
    }
    printf("hsb=%d\n",a[0]);
    printf("yxw=%d\n",a[1]);
    printf("lw=%d\n",a[2]);
    printf("ssl=%d\n",a[3]);
    printf("hd=%d\n",a[4]);
    printf("zjr=%d\n",a[5]);
    return 0;
}
//职位  查找资料 0 1 2 演讲 3 ppt 4 5