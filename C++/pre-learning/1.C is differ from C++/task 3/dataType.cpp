#include <iostream>
using namespace std;

bool size(int listCurSize)
{
    return listCurSize == 0;
}

//���ó䵱��������
void modifyNum(int& iNum)   //int &iNum == mm;
{
    iNum = 10007;
}

//���ó䵱��������:������ֵʹ��
int& returnValue(int& iNum)
{
    return iNum;
}

//�䵱������ֵʹ��
void print(const int& iNum)
{
    //iNum++ �����õľ����� �����޸�
    cout << iNum << endl;
}

//�䵱��ֵ�ĳ�����
void printValue(int&& iNum)
{
    iNum++;
    cout << iNum << endl;
}

int Max(int a,int b)
{
    return a>b ? a : b;
}

struct MM
{
    int age;
};

int main()
{
    //No.1 �µĿ�ָ��
    int *p = NULL;      //����д���ǽ�0����ǿ������ת��(*void)0
    int *cpp = nullptr; //�����͵Ŀ�ָ��
    //No.2 �µ���������֮bool
    //2.1 bool���������ͼ�
    //2.2 bool��ӡ��ֻ������0����1
    //2.3 ������з�0ֵ����ʾ����
    //2.4 boolռ��һ���ֽڵ��ڴ�
    //2.5 ͨ�������bool�����䵱�����жϵķ���ֵ,���߳䵱���ر��ʹ��
    bool bNum = -1;
    cout << bNum << endl;
    cout << sizeof(bool) << endl;
    //No.3 ��������
    //3.1 �����÷��������
    int mm = 1;
    int &cute = mm;
    cute = 10001;
    cout << mm << endl;
    //3.2 ��������ֵ���߲���
    modifyNum(mm);
    cout << mm <<endl;
    //3.3 ���ں�������ֵ������ֵʹ��
    //һ������·���ֵΪ�������޷��޸�
    returnValue(mm) = 122;  //���ܷ��ؾֲ�������
    //int& x = returnValue(mm) = iNum
    cout << mm << endl;
    //3.3 ��ֵ����
    //3.3.1 �����ÿ��Ա����ֵ
    const int& cNum = 1234;
    print(12);
    printValue(1234);
    //������
    printValue(move(mm));        //��ֵ������δ���ֵ���� move���Խ���ֵת��Ϊ��ֵ
    //No.4 auto ���ͣ��Զ��ƶ�����
    //���ｫMAX�ķ���ֵ��ַ��ֵ����pMax(int, int)
    int (*pMax)(int, int) = Max;
    cout << pMax(4,5) << endl;
    auto pFunc = Max;
    //�Զ��ƶ����Ϳ����Զ��ƶϳ�ת��������
    cout << pFunc(1,2) << endl;
    //Ҳ�����ƶϽṹ��
    struct MM object = {1};
    //ֱ���ƶϳ�&objectΪstruct MM*
    auto pObject = &object;
    return 0;
}