#include <iostream>     //��׼ͷ�ļ�
#include <cstdio>
#include <cstdlib>
using namespace std;    //��׼�����ռ�

/*
    1.c++ֻ֧��int���͵ķ���ֵ
    2.c++�Բ���û��Ҫ��,����д����,Ҳ���Բ�д
*/
namespace helloworld
{
    void print()
    {
        printf("hellow world\n");
    }
}



int main()              //��ں���
{
    helloworld::print();
    cout<<"������˧��,��Ҳ����\n";
    system("pause");
    return 0;
}