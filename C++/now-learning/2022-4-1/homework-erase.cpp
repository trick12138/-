#include "myVector.cpp"

int main()
{
    myVector<int> vecData = {1,2,3,4,5};
    for (int i = 0; i < vecData.size(); i++)
    {
        cout << vecData[i] << ' ';
    }
    cout << endl;
    vecData.erase(2);
    for (int i = 0; i < vecData.size(); i++)
    {
        cout << vecData[i] << ' ';
    }
    cout << endl;
    return 0;
}