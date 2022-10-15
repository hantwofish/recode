#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class A{
public:
    A():m_data(1),m_a(1)
    {

    }
    ~A(){}

public:
    int m_data;
    int m_a;
};

class B{
public:
    B():m_data(1),m_b(1){

    }   
    ~B(){} 

public: 
    int m_data;
    int m_b;
};

class C :public A, public B{

};

int main()
{
    C Data;
   // Data.m_data = 10; // 错误，指向不明确
   // 通过 域成员运算符才可以访问使用不方面。
    Data.A::m_data = 10;
    Data.B::m_data = 2;
    std::cout << Data.A::m_data << " " << Data.B::m_data << endl;
    return 0;

}