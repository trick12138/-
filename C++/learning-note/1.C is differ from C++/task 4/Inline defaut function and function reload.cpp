#include <iostream>
using namespace std;

//No.1 �����������Զ����Ƶ���ʽ����
//1.1 �����������ص㣺��С����
//1.2 inline
//1.3 ����ڽṹ���л���������ʵ�ֵĺ���Ĭ��Ϊ��������
inline int Max(int a, int b)
{
    return a>b? a : b;
}

//No.2 ��������: ����ͬ����ͬ�εĺ�������
//���ӱ�ʶ����ʹ����
void print(int a, int b)
{
    cout << a + b << endl;
}

//2.1 �����ĸ�����ͬ
void print(int a)
{
    cout << a << endl;
}

//2.2 ���������Ͳ�ͬ
void print(int a, char b)
{
    cout << a + b <<endl;
}

//2.3 ������˳��ͬ: һ�����ڲ�ͬ���͵Ļ�����
void print(char b, int a)
{
    cout << a + b <<endl;
}

//No.3 ����ȱʡ�����Ǹ�����������ʼ��
//ע�⣺ȱʡ��˳��ֻ�ܴ������������Ե�ȱʡ
//          ���ļ���,ֻ����������ȱʡ����
int sum(int a = 0, int b = 0, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main()
{
    //��������
    print(1,2);
    print(1);
    print('A',1);
    print(2,'A');
    //������ȱʡ
    cout << sum (11,22,33,44) << endl;
    cout << sum() << endl;
    cout << sum(1) << endl;
    cout << sum(1,2) << endl;
    cout << sum(1,2,3) << endl;
    return 0;
}