#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char* name;
};

using namespace std;

int main()
{
    node N;
    scanf("%s",N.name);
    printf("%s",N.name);
    cout << endl;
    return 0;
}