#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=3,y=4,z=4;
    printf("%d",!((x<y)&&!z||1));
    system("pause");
    return 0;
}