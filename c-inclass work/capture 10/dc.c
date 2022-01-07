#include <stdio.h>
#include <stdlib.h>
void max(int *p,int n)
{   int i;int j;
    int tmp;
    for(i = 0;i < 10;i++)
    {
      	for(j = 0;j < (10 - i - 1);j++)
      	{
      		if(*(p+j) < *(p+j+1))
      		{
	  			tmp=*(p+j);
       			*(p+j)=*(p+j+1);
       			*(p+j+1)=tmp;
	  		}
	  	}
	}
}
int main()
{
	int *p;
	int a[10];
	int i;
	p=a;
	printf("please enter ten number: \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",(p+i));
	}
	max(a,10);
	printf("the end data: \n");
	for(i=0;i<10;i++)
	{
		printf("%d ",*(p+i));
	}
    system("pause");
	return 0;
}