#include <stdio.h>
int main()
{
    int a,c,d;
    float b;
    scanf("%d",&a);
    while (a != 0)
    {
        b = (float)a/10;
        a = a/10;
        b = b - a;
        c = (int)(b * 10);
        d = ++d;
        printf("%d\n",a);
        printf("%f\n",b);
        printf("%d\n",c);
    }
    printf("位数=%d",d);
    
}
/*
98745
9874
0.500000
5
987
0.400024
4
98
0.699997
6
9
0.800000
8
0
0.900000
9
位数=5
*/