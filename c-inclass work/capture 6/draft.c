#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    char s1[80],s2[40];
    int i=0,j=0;
    printf("字符串1：");
    scanf("%s",s1);
    printf("字符串2：");
    scanf("%s",s2);
    while (s1[i]!='\0')
       i++;
    while (s2[j]!='\0')
    {
        s1[i++]=s2[j];
    }
    s1[i]='\0';
    printf("\n新的字符串:%s\n",s1);
	return 0;
}