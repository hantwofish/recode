#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int test01();
int test02();
int test03();
int main()
{
   // test01();
   // test02();
    test03();

    return 0;

}

int test01()
{
    stringstream ss;
    int foo, bar;
    /* 单个输入时候，应加上 clear 将数据流清空
    ss << 100  ;
    ss >> foo ;
    ss.clear();
    ss << 1;
    ss >> bar;
    */
    ss << 100 << ' ' << 200; // stringstream 以空格作为间隔，所以数据应当 以 空格进行分开
    ss >> foo >> bar;
    cout << "foo= " << foo << '\n';
    cout << "bar= " << bar << '\n';

    return 0;

}

int test02()
{ // 从 string 对象中读取字符串，遇到空格结束
  string str = "hello world";
  cout << str << endl;
  stringstream ss(str); //   stringstream ss;  ss << str ;
  string abc;
  while(ss >> abc){
      cout << abc << endl;
  }
  // 清空 sstream
  ss.str("");
  
   return 0;
}

int test03()
{
    // 支持C 风格的串流的输入输出操作
    int num = 100999990;
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    ss.clear();  // 使用 stringstream 做转换时候，使用完需要进行 ss.clear()操作
    cout << str << endl;
    cout << str.c_str() << endl; // string -> char
    cout << "sizeof(str.c_str())=  " <<  sizeof(str.c_str()) << endl;
    cout << "int to string= " << to_string(num) << endl;
    return 0;
 }
