#include <iostream>
#include <fstream>
using namespace std;
int main() {
	// 打开文件temp.txt，按照in(输入)，binary(二进制)读取文件流
    ifstream in_file("a.pcap", ios::in | ios::binary);

    unsigned int val;// unsigned int 类型变量占两个字节
    in_file.read((char *) &val, 1);//获取文件第一个字节的内容
    cout << val << endl;// 输出变量val的值

    in_file.seekg(2);//把文件读取位置转到距离文件头2个字节偏移的位置
    in_file.read((char *) &val, 1);//再次读取文件，从文件的第0+2个字节开始读取，读取1个字节，赋值到变量var
    cout << val << endl;//输出变量值

    in_file.seekg(0);//把文件读取位置转到距离文件头0个字节偏移的位置（就是文件开始位置）
    in_file.read((char *) &val, 2);//再次读取文件，从文件的第0个字节开始读取，读取2个字节，赋值到变量var
    cout << val << endl;//输出变量值
    uint8_t data = 0;
    for(int i = 0; i < 500 ; i++){
        in_file.seekg(i);//把文件读取位置转到距离文件头0个字节偏移的位置（就是文件开始位置）
        in_file.read((char *) &data, 1);//再次读取文件，从文件的第0个字节开始读取，读取2个字节，赋值到变量var
        printf("%x ",data);
    }


    in_file.close();//关闭文件
    return 0;
}
