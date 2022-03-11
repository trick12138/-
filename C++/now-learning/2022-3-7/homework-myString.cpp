#include <iostream>
#include <string.h>

using namespace std;

class myString
{
public:
    myString()
    {
        String = nullptr;
    }
    myString(char *str)
    {
        this->String = str;
    }
    char *operator=(char *string)
    {
        String = string;
        return String;
    }
    friend ostream& operator<<(ostream& out,myString& object)
    {
        out << object.String;
        return out;
    }
    char* operator+(myString& object)
    {
        return strcat(this->String,object.String);
    }
    bool operator!=(myString& object)
    {
        return !strcmp(this->String,object.String);
    }
    bool operator==(myString& object)
    {
        return strcmp(this->String,object.String);
    }
    bool operator<(myString& object)
    {
        return strcmp(this->String,object.String) < 0;
    }
    bool operator<=(myString& object)
    {
        return strcmp(this->String,object.String) <= 0;
    }
    bool operator>(myString& object)
    {
        return strcmp(this->String,object.String) > 0;
    }
    bool operator>=(myString& object)
    {
        return strcmp(this->String,object.String) >= 0;
    }
    friend istream& operator>>(istream& in,myString& object)
    {
        in >> object.String;
        return in;
    }
private:
    char *String;
};

int main()
{
    myString name;
    name = (char *)"你好";
    cout << name << endl;
    cin >> name;
    return 0;
}