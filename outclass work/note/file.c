#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n");
    //fgets��ȡһ��
    char str[200];
    char *p = fgets(str,200,fp);
    printf("%s\n",str);
    printf("%s\n",p);
    //fread���ɶ�ȡ,���ض�ȡ��С
    char str1[200];
    while (fread(str1, 1 , 100, fp))
    {
        printf("%s", str1);
    }
    //��ղ���д���ַ�
    FILE* hp = fopen("test.txt","rw");
    if(hp == NULL)
    {
        printf("���ļ�ʧ��");
        return 0;
    }
    //д��һ���ַ�
    /* fputc('A',hp);
    fputc('B',hp);
    //д���ַ���fput
    char *str2 = (char*)"Hello world\r";
    fputs(str2,hp);
    fputs(str2,hp); */
    //�ļ�ָ�붨λ
    fseek(hp,0,SEEK_SET);
    //д������fwrite,ת��Ϊ2����,�ļ�ָ��д��ƫ����һ��
    int num = 456123;
    fwrite(&num, 1, sizeof(num), hp);
    int num1;
    fread(&num1, 1, sizeof(num), hp);
    printf("num1=%d",num1);
    //fseek�ƶ��ļ�ָ��
    int lenth;
    ch = 0;
    fseek(hp, -1, SEEK_END);//ָ���ƶ�����β
    while(fread(&ch,1,1,hp))
    {
        if(ch == '\n')
            break;
        fseek(hp, -2,SEEK_CUR);
        lenth++;
    }
    printf("�����%d��ô��",lenth);
    //�ر��ļ�
    fclose(fp);
    fclose(hp);
    return 0;
}