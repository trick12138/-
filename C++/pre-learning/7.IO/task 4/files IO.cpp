#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
/*
    No.1 流类
        ofstream:   用来打开文件进行写操作
        ifstream:   用来打开文件进行读操作
        fstream:    读写操作
    No.2 包含头文件
        #include <fstream>
    No.3 打开和关闭文件
    void open(const char* URL,ios::openmode mdoe);
    mode: 打开方式
    ios::in         读的方式打开文件
    ios::out        写的方式打开文件
    ios::app        追加模式写文件
    ios::ate        打开已有文件,文件指针指向文件末尾
    ios::trunc      文件不存在具有创建方式  ios::out|ios::trunc 创建且写入
    ios::binary     二进制形式打开文件  默认ASCII方式打开文件
    ios::nocreate   不创建的方式
    ios::noreplace  不替换源文件
    ios::in|ios::out可读可写的方式
    ios::out|binary 二进制写的方式
    判断文件是否打开成功: 
        1.is_open() 返回0表示打开失败 运算符重载
        2.!文件对象 也可以判断文件是否打开
    close成员函数关闭文件指针
*/
//readFileName 读文件名
//wirteFileName 写文件名
void asciiReadWriteFile(const char *readFileName,const char *writeFileName)
{
    fstream read(readFileName, ios::in);
    fstream write(writeFileName, ios::out);
    //1.流运算符读写    eof()   函数返回当前文件是否在文件末尾
    //注意: 采用流的方式会忽视空格和换行
/*     while(!read.eof())
    {
        char key;
        read >> key;
        write << key;
    } */
    //2.用成员函数的方式读写 get() 和put()函数读写
    //保留空格的方式
    while(!read.eof())
    {
        char key;
        read.get(key);
        write.put(key);
    }

    read.close();
    read.close();
}

//二进制的方式读写文件
//write函数和read函数
void binaryReadWrite(const char *readFileName,const char *writeFileName)
{
    fstream readObject(readFileName, ios::in | ios::binary);
    fstream writeObject(writeFileName, ios::out | ios::binary);
    char str[1024] = "";
    memset(str,'\0',1024);
    while(!readObject.eof())
    {
        readObject.read(str,1024);
        writeObject.write(str,1024);
    }
    readObject.close();
    writeObject.close();
}
//No.5 文件指针的移动
//重新定义文件指针
/*
    ifstream的位置指针
    istream& seekg(long int pos);
    istream& seekg(long int pos,ios_base::seekdir begin);
    ofstream的位置指针
    ofstream& seekp(long int pos);
    ofstream& seekp(long int pos,ios_base::seekdir begin);
    begin:参照点
    ios::beg:   开始的位置 默认
    ios::cur:   当前位置
    ios::end:   结束位置
*/
void testSeekReadFile(const char *fileName)
{
    fstream fileRead(fileName,ios::in);
    if(!fileRead)
    {
        cerr << "open error!" << endl;
    }
    fileRead.seekg(3);
    char key = fileRead.get();
    cout << key << endl;
    fileRead.seekg(0, ios::beg);
    cout << (char)fileRead.get() << endl;
}

int main()
{
    //打开文件测试
    fstream file("xxoo.txt",ios::in | ios::out | ios::trunc);
    if(!file || !file.is_open())
    {
        cerr << "文件打开失败!" << endl;
    }
    file.close();
    //No.4 读写文件操作
    //4.1 流运算符 << >>
    asciiReadWriteFile("a.txt","b.txt");
    //4.2 成员函数的方式进行读写
    binaryReadWrite("binaryA.txt","binaryB.txt");
    //4.3 文件指针移动
    testSeekReadFile("test.txt");

    //4.2 成员函数的方式读写


    return 0;
}