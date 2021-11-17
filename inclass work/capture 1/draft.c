#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a;
	scanf("%c",&a);
	if (a>='A'&&a<='Z')
	printf("为大写字母");
	else if(a>='0'&&a<='9')
	printf("为数字字符");
	else if(a>='a'&&a<='z')
	printf("为小写字母");
	else if(a==' ')
	printf("为空格字符");
	else
	printf("为其他字符"); 
	return 0;
}