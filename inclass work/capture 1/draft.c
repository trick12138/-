#include<stdio.h> 
int main()
{
 int sth;
 scanf("%c",&sth);
 if(sth>='0'&&sth<='9')
  {
  	printf("sth是一个数字");
  }
 if(sth>='A'&&sth<='Z')
 {
 	printf("sth是一个大写字母");
 }
 if(sth>='a'&&sth<='z')
 {
 	printf("sth是一个小写字母");
 }
 return 0;
}