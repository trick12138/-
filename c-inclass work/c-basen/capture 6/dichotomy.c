#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={57,50,46,40,36,32,27,24/*7*/,21,16,13,11,7,4,2};
    int b;
    //输入数字
    scanf("%d",&b);
    int left = 0,right = 14;
    int flag = -1;
    //二分法搜索
    while(left<right)
    {
        if (b == a[(left + right)/2])
        {
            flag = (left + right)/2;
            break;
        }
        if (b > a[(left + right)/2])
        {
            right = ((left + right)/2 + 1);
        }
        else
        {
            left = ((left + right)/2 + 1);
        }
        
    }
    printf("这个数字是%d",flag);
    system("pause");
    return 0;
}