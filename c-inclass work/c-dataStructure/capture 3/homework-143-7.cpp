#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

string same(const char *&s1,const char *&s2)
{
    const int len1 = strlen(s1);
    const int len2 = strlen(s2);
    set<char> s3;
    string S3;
    for (int i = 0; i < len1; i++)
    {
        if (find(s2,s2 + len2,s1[i]) != s2 + len2 + 1);
            s3.insert(s1[i]);
    }
    S3.assign(s3.begin(),s3.end());
    return S3;
}

int main()
{
    const char *s1 = "abcaabbabcabaacbacba";
    const char *s2 = "abcabaa";
    cout << same(s1,s2) << endl;
    system("pause");
    return 0;
}

/*
输出结果
abc
Press any key to continue . . .
*/