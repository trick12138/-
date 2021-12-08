#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    char diamond[6][5]={{'*','*','*','*','*'},{'*',' ',' ',' ','*'},{'*',' ',' ',' ','*'},{'*','*','*','*','*'}};
	int i,j;
	for (i=0;i<5;i++)
	{   
	    for(j=0;j<5;j++)
	       printf("%c",diamond[i][j]);
	    printf("\n");
	}
    getchar();
	return 0;
}