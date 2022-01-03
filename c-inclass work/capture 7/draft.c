#include <stdio.h>
#include <stdlib.h>
    
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a,int b){
	int gcd,t;
	while(b!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	gcd=a;
	return gcd;
}
int gmd(int a,int b)
{
	int m = a * b,c;
	c=m/gcd(a,b);
	return c;
}
int main(int argc, char *argv[])
{
    int z,n,d,e;
    scanf("%d,%d",&d,&e);
    z=gcd(d,e);
    n=gmd(d,e);
    printf("最大公约数:%d\n",z);
    printf("最小公倍数:%d\n",n);
    return 0;
}