#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //No.1 C++�������������
    //1.1�������ݵ�ʱ��
    printf("������˧��,��Ҳ����\n");
    cout << "������˧��,��Ҳ����!" << endl;
    printf("%d\n",1);
    cout << 1 << endl;
    //1.2 ����������
    printf("%d%s%f\n",1,"���˧",1.1);
    cout << 1 << "���˧" << 1.1 << endl;
    //1.3 ���ڸ�ʽ����
    //C++ ����֧��C���Եĸ�ʽ�����ַ�,����Ҫ����C++�ĸ�ʽ����
    //cin��coutҲ��C++�е���Ͷ���
    //����
    cout << endl;
    //1.4 ����������
    int iNum = 1;
    char str[] = "�Һ�˧,��Ҳ����";
    double dNum = 1.1;
    cout << iNum << "\t" << str << "\t" << dNum << endl;
    //No.2 C++��������
    cin >> iNum;
    cout << "iNUm=" << iNum <<endl;
    //2.����������
    cin >> iNum >> str >> dNum;
    cout << "iNum=" << iNum << "str=" << str << "dNum=" << dNum << endl;
    //No.3ע�⼸������
    //1.�����ռ�
    //C++���������޶����������÷�Χ
    //2.����д��
    ::cout << "I love you" << ::endl;
    //��ȫ�ֱ����;ֲ�������ͻʱ�ͽ�ԭ��
    //C++�п�����������ֱ��������::Ϊȫ�ֱ���
    return 0;
}