#include <iostream>
#include <iomanip>
using namespace std;
/*
    No.1 �������������
    cin    ��׼����     �Ӽ��̶�ȡ, �����ض����ļ�
    cout   ��׼���     �������Ļ, �����ض���λ�ļ�
    cerr   ��׼����     �����������Ļ,�����ض���
    clog   ��׼����     �������Ļ, ���ض���
    No.2 �������õĺ���(�ַ����ַ����Ĳ�����)
        put()����ַ�����   ����: get()
        write()����ַ���   ����: getline()
    No.3 �������ַ�
        3.1 ��Ҫ�����ض���ͷ�ļ�   #include <iomanip>
        3.2 �ؼ��ֵ���ʽ, һ���ǳ�Ա����
    �ؼ�����ʽ
    setbase(n)    ��������Ϊn����
    setfill(n)    ����ַ�
    setprecision    ���þ���
    setw(n)         ���ÿ��
    setiosflags(ios::scientific)    ���ÿ�ѧ������
    setiosflags(ios::left)          ���������
*/
int main()
{
    cout << "cout" << endl;
    cerr << "cerr" << endl;
    clog << "clog" << endl;
    char str[20] = "";
    //cin >> str;
    //cout << str << endl;
    cin.getline(str,20);
    cout << str << endl;
    //get()
    int userKey = cin.get();
    cout << userKey << endl;
    cout.put('A');
    cout.write("ILOVEYOU",10);  //�����������
    cout << endl;
    cout << setprecision(4) << 300.1415 << endl;    //�򵥵�ʹ�ò��Ǵ���С��λ��, ���� ��Чλ�� 
    cout << fixed << setprecision(4) << 300.1415 << endl;//����С��λһ��Ҫ���fixedʹ��
    cout << setbase(16) << 123 << endl;
    cout << 123 << endl;
    cout << setiosflags(ios::left);
    cout << setw(8) << "����" << setw(8) << "����" << "���" << endl;
    //�������ַ����ó�Ա�ķ�ʽ
    cout.width(8);
    cout.precision(3);

    return 0;
}