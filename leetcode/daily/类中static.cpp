#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class A{
public:
    A(){}
    ~A(){}
    void eat(){}
    void drink(){}
    void play(){}
    void happy(){}
public:
    char data[32];
    static int number ; // 声明静态成员变量但没有定义 
};

int A::number = 0 ; // 定义 并 初始化
int main()
{
    A a;
    int len  = sizeof(a);
    len = sizeof(A);
    cout << A::number << endl;
    A::number = 2;
    cout << A::number << endl;
    cout << "len= " << len << endl;

    return 0;
    
}