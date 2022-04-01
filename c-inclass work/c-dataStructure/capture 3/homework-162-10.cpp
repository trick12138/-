#include <iostream>
#include <string>

using namespace std;

string::iterator position(string& t,string& s)
{
    static int n = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if ((t[i] == '*' || t[i] == s[n + i]) && i == t.length() - 1)
            return s.begin() + n;
        if (t[i] != '*' && t[i] != s[n + i])
        {
            ++n;
            return position(t,s);
        }
    }
    return s.end();
}

int main()
{
    string t = "a*b*d";
    string s = "bbbbbbbbaabbbd";
    printf("%s",position(t,s));
    return 0;
}
/*
运行结果
abbbd
*/