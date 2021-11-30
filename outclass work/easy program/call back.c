#include <stdio.h>
#include "four fundamental rules.h"

int main()
{
    char str1[100] = "123456789";
    char str2[100] = "9999999";
    char *pa = str1;
    char *pb = str2;
    char *pc = sum(pa,pb);
    printf("%s",pc);
}