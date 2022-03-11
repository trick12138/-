#include <iostream>
#include <iomanip>
using namespace std;
/*
    No.1 输入输出流对象
    cin    标准输入     从键盘读取, 可以重定向文件
    cout   标准输出     输出到屏幕, 可以重定向位文件
    cerr   标准错误     必须输出到屏幕,不可重定向
    clog   标准错误     输出到屏幕, 可重定向
    No.2 流对象常用的函数(字符和字符串的操作上)
        put()输出字符函数   输入: get()
        write()输出字符串   输入: getline()
    No.3 流控制字符
        3.1 需要包含特定的头文件   #include <iomanip>
        3.2 关键字的形式, 一个是成员函数
    关键字形式
    setbase(n)    设置整数为n进制
    setfill(n)    填充字符
    setprecision    设置精度
    setw(n)         设置宽度
    setiosflags(ios::scientific)    设置科学技术法
    setiosflags(ios::left)          设置左对齐
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
    cout.write("ILOVEYOU",10);  //限制输出长度
    cout << endl;
    cout << setprecision(4) << 300.1415 << endl;    //简单的使用不是代表小数位的, 而是 有效位数 
    cout << fixed << setprecision(4) << 300.1415 << endl;//设置小数位一定要结合fixed使用
    cout << setbase(16) << 123 << endl;
    cout << 123 << endl;
    cout << setiosflags(ios::left);
    cout << setw(8) << "姓名" << setw(8) << "年龄" << "编号" << endl;
    //流控制字符采用成员的方式
    cout.width(8);
    cout.precision(3);

    return 0;
}