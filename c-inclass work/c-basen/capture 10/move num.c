#include <stdlib.h>
#include <stdio.h>

void move(int array[],int n,int m)
{
    int change;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            change = array[j];
            array[j] = array[j + 1];
            array[j + 1] = change;
        }
        
    }
    
}

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    move(array,10,2);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
    
    system("pause");
    return 0;
}