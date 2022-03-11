#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    //1.申请一个变量的内存
    int* pCNum = (int*)malloc(sizeof(int));
    free(pCNum);
    int *pCppNum = new int;
    delete pCppNum;
    //2.申请一段内存
    int *pcArray = (int*)malloc(sizeof(int) * 3);
    free(pcArray);
    int *pcppArray = new int[3];
    delete[] pcppArray;
    //申请并且初始化
    int *pAlloc = (int*)calloc(sizeof(int),3);
    if(pAlloc == nullptr)
        return 0;
    for (int i = 0; i < 3; i++)
        cout << pAlloc[i];
    cout << endl;
    free(pAlloc);
    //3.1 C++单个数据初始化
    int *pNum = new int(100);
    cout << *pNum << endl;
    pNum = nullptr;
    //3.2 C++多个数据初始化()
    int *pArray = new int[3]{1,2,3};
    for (int i = 0; i < 3; i++)
        cout << pArray[i];
    cout << endl;
    pArray = nullptr;
    //4.内存池：允许我们在申请的内存上再做申请操作
    char *Memory = new char[1024];
    int *pInt = new(Memory + 0) int[3]; //前十二个字节存放整数
    char *pChar = new(Memory + 12) char[20];
    strcpy(pChar,"我很帅,你也不错");
    cout << pInt[0] << pInt[1] << pInt[2] << endl;
    cout << ((int*)Memory)[0] << ((int*)Memory)[1] << ((int*)Memory)[2] << endl;
    cout << pChar << endl;
    cout << Memory + 12 << endl;
    delete[] Memory;
    Memory = nullptr;
    return 0;
}