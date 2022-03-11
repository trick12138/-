#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

void printData(array<array<int,3>,3> myData)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << myData[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    //No.1 定义数组实现二维数组
    array<array<int,3>,3> myData;   //等效于int myData[3][3]
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            myData[i][j] = i * j;
    printData(myData);
    //myData[0] 代表 一个array<int ,3> 类型的数据
    //No.2 动态数组实现二维数组
    vector<vector<int>> vectorData(3);
    //vectorData[0] 代表一个vector<int>类型的数据
    for (int i = 0; i < 3; i++)
    {
        vectorData[i].resize(3);
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            vectorData[i][j] = i * j;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << vectorData[i][j] << "\t";
        cout << endl;
    }
    vector<vector<string>> strData;
    vector<string> temp;
    for (int i = 0; i < 3; i++)
    {
        temp.push_back("name");
    }
    strData.push_back(temp);
    cout << strData.at(0).at(0) << endl;
    //No.3 vector与array之间的嵌套
    array<vector<int> , 3> vecArray;
    for (int i = 0; i < 3; i++)
    {
        vecArray[i].resize(3);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vecArray[i][j] = i * j;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << vecArray[i][j] << "\t";
        }
        cout << endl;
    }

    vector<array<int,3>> arrayVector(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arrayVector[i][j] = i * j;
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arrayVector[i][j] << "\t";
        }
        cout << endl;
    }


    return 0;
}