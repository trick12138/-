#include <stdio.h>
void exchange(int *a,int *b);
int a,b;
int main()
{
    int a=10000,b=30000;
    exchange(&a,&b);
    printf("a=%d,b=%d",a,b);
}

void exchange(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}