#include <stdio.h>

int main()
{
    //���ļ�
    FILE* fp = fopen("C:\\Users\\����\\Desktop\\�ʼ�.txt","r");
    if(fp == NULL)
    {
        printf("���ļ�ʧ��");
        return 0;
    }
    //����
    //fgetc��ȡһ���ַ�
    char ch;
    while(EOF != (ch = fgetc(fp)))
    {
        printf("%c",ch);
    }
    //fgets��ȡһ��
    char str[200];
    fgets(str,200,fp);
    printf("%s",str);
    //�ر��ļ�
    fclose(fp);
    return 0;
}