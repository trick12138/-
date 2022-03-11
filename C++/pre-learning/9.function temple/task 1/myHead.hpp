#pragma once
#include <iostream>
using namespace std;
template <class A,class B>
void printValue(A first,B second)
{
    cout << first << endl;
    cout << second << endl;
}
template <>
void printValue(int first,int second)
{
    cout << first << endl;
    cout << second << endl;
}
void printValue(int first,int second)
{
    cout << first << endl;
    cout << second << endl;
}
template <class T>
void printValue(T first,T second)
{
    cout << "优先调用" << endl;
    cout << first << endl;
    cout << second << endl;
}