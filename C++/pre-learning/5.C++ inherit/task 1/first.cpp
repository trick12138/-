#include <iostream>
#include <string>
using namespace std;
/*
    No.1    �̳��еĻ�������
    ����    ����
    ����    ������(����������������)
    No.2    ���дһ���̳�
    class ����:�̳з�ʽ  ������
    {

    };
    �̳з�ʽ  public protected private
    No.2    �̳е�ʵ��: ��ʾ��������������൱�д���
    No.3    �̳е�Ȩ������
        �̳з�ʽ    public      protected       private
        ��������
        public:     public:    protected        private
        protected:  protected: protected        private 
        private:    ���ɷ���    ���ɷ���        ���ɷ���
    Ȩ���޶���ֻ����ǿȨ��(public:��----private:��)
    No.4 �̳��еĹ��캯����д��
    
*/
class Father
{
public:
    void print()
    {
        cout << "Ǯ" << endl;
    }
protected:
    int money;
private:
    string name;
};
//���м̳�
class Son1 :public Father
{
public:
    void printSon()
    {
        //print();
        cout << money << endl;
        //cout << name << endl; //������˽����������ʲô�̳з�ʽ,���඼�޷�����.
        cout << "Ǯ" << endl;
    }
    //void print()
protected:
    //int money
private:
    //string name
};

class Son2 :protected Father
{
public:

protected:
    //void print()
    //int money
};

class Son3 :private Father
{
public:
    void printF()
    {
        print();
    }
private:
    //void print();
    //int moeny;
};

int main()
{
    Son1 son;
    son.print();
    Son2 son2;
    //son2.print(); Ȩ�޲���
    Son3 son3;
    son3.printF();

    return 0;
}