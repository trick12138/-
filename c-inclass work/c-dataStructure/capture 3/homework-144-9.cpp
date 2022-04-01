#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const char *find_last_of(const char *&str,char &s)
{
    const int len = strlen(str);
    for (int i = len - 1; i > -1; i--)
        if (str[i] == s)
            return str + i;
    return str + len;
}

int main()
{
    const char* str = "abaabsdhjagfjagl";
    char s = 'f';
    cout << find_last_of(str,s) << endl;
    return 0;
}

/*
运行结果
fjagl
*/