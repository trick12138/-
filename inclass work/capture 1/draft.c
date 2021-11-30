#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *pa = (char*)"hello";
    char *pb = (char*)"hello";
    if (strcmp(pa,pb))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    
}