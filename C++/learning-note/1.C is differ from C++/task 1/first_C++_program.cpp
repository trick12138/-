//C++��׼�����������ͷ�ļ�
#include <iostream>
//C++���ַ���ͷ�ļ�
#include <string>

//C++�������ռ�,Ҳ�����Լ�����
using namespace std;

//C���Ե�ͷ�ļ�
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
//�Լ�����������ռ�
namespace mm1
{
    char name[20];
    int age;
    void print()
    {
        cout<<name<<age<<endl;
    }
    void printHello_World()
    {
        cout<<"hellow world"<<endl;
    }
}

namespace boy
{
    namespace mm
    {
        int age;
        void print()
        {
            printf("boy::mm\n");
        }
    }
}
/*
    1.�����ռ��д��
    namespace �ռ���
    {
        //����
        //����
        //�Զ�������
    }
    2.����Լ�ʹ�������ռ�
        �ռ���::��Ա;
    3.���ʹ��ʡ�Եķ�ʽȥ���ÿռ��еĳ�Ա
        �������������using namespace ��������
        ͬʱҲҪע��ͬ������
    4.�����ռ��Ƕ��
        �����
    ����:
        NO.1 ��һ���̶������ӱ�ʶ����ʹ����
        NO.2 �ڴ�����Ŀ�б���������ͻ
*/

//C++����ں���
int main()
{
    strcpy(mm1::name,"С�ɰ�");
    mm1::age = 18;
    mm1::print();
    mm1::printHello_World();
    {
        using namespace mm1;
        printf("%s\n",name);
    }
    boy::mm::print();
    system("pause");
    return 0;
}