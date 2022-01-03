#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    map<int,string> myMap;
    myMap.insert(pair<int,string>(0,"Kevin"));
    myMap.insert(pair<int,string>(1,"黑夜"));
    myMap.insert(pair<int,string>(2,"莫帅"));
    myMap.insert(pair<int,string>(1,"大水杯"));
    for (int i = 0; i < 3; i++)
    {
        cout << myMap[i] << endl;
    }
    


    system("pause");
    return 0;
}