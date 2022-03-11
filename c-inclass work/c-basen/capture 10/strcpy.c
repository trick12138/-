#include <stdio.h>
#include <stdlib.h>

void copy_string(char from[],char to[])
{
    int i = 0;
    while(from[i] != '\0')
    {
        to[i] = from[i];
    }
    to[i] = '\0';
}


int main()
{
    
    system("pause");
    return 0;
}