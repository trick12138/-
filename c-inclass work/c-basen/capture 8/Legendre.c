#include <stdio.h>
#include <stdlib.h>

double legendre(int n,int x)
{
	double result; 
	if(n == 0)  
		result = 1;  
	if(n == 1)
		result = x; 
	if(n>1)
		result = ((2*n-1)*x*legendre(n-1,x)-(n-1)*legendre(n-2,x))/n;    
	return result;
}

int main()
{ 
	int x,n; 
	scanf("%d %d", &n, &x); 
	printf("%.2f\n", legendre(n,x));
    system("pause");
	return 0;
}
