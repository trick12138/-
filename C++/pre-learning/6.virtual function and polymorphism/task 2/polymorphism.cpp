#include <iostream>
using namespace std;
//No.1 �̳��г�Ա�ķ�������
//1.1 ���ֻ��һ������, ������ͬ�������, �����Ǹ�����, ���������Ϳ���
//1.2 ͬ�����
//  1.2.1 �������: ���þͽ�ԭ��
class MM
{
public:
    virtual ~MM()
    {
        cout << "~MM" << endl;
    }
    void print()
    {
        cout << "MM::print" << endl;
    }
    virtual void printVirtual()
    {
        cout << "MM::printVirtual" << endl;
    }
protected:

};

class Boy :public MM
{
public:
    ~Boy()
    {
        cout << "~Boy" << endl;
    }
    void print()
    {
        cout << "Boy::print" << endl;
    }
    virtual void printVirtual()
    {
        cout << "Boy::printVirtual" << endl;
    }
protected:

};

class Girl :public Boy
{
public:
    void printVirtual()
    {
        cout << "Girl::printVirtual" << endl;
    }
    //virtual void printVirtual()
protected:

};

int main()
{
    //No.2 ��̬����
    //��������µĶ���: �ͽ�ԭ��, ���ĸ���Ķ���͵����ĸ���ĳ�Ա
    MM mm;
    Boy boy;
    mm.print();
    boy.print();
    MM *pM = new MM;
    Boy *pB = new Boy;
    pM->print();
    pB->print();
    //������Ҫ���ʼ̳�������ͬ������, ����ǿ��ָ��: ����::
    boy.MM::print();
    pB->MM::print();
    //���������: ����ָ�뱻��������ʼ��, ����������ܱ���������ʼ��
    //������virtual�������: ��ָ�������
    MM *pMM = new Boy;
    pMM->print();
    //Boy *pB = new MM; Σ��,����
    //�����д���virtual�����
    pMM->printVirtual();    //�����е�ͬ������
    pMM = &mm;
    pMM->printVirtual();    //�����еĺ���
    //C++ ��̬, ��Ϊ��ֵ�Ĳ�ͬ�����µ���ͬ��Ϊ�Ĳ�ͬ���, ����һ�����֮Ϊ��̬(��д)
    //��̬�ı�Ҫ����: 1.���븸�����virtual 2.����������ͬ������ 3.�������������������ָ���ʹ��
    //����ָ�뱻��������ʼ��
    pMM = &boy;
    pMM->printVirtual();
    Boy *pBG = new Girl;
    pBG->printVirtual();    //Girl
    //�麯�����̳����۶��ٴ�, �����麯��
    {
        //ʹ����������ʼ�������ʱ���������������, ֻ���ø����е���������
        //�����ڸ�����ʹ��virtual������������, ����Ҳ���Ե��������е�
        MM *pObject = new Boy;
        pObject->printVirtual();
        delete pObject;
    }

    cout << "......!!!!!!!!!" << endl;

    return 0;
}