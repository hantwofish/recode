#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//  公共基类
class N{
public:
    N(int data1, int data2, int data3):m_data1(data1),m_data2(data2),m_data3(data3)
    {
        cout << "cal common constrctor " << endl;
    }
    virtual ~N()
    {

    }
    void display()
    {
        cout << m_data1 << endl;
    }

public:
    int m_data1;
    int m_data2;
    int m_data3;
};

class A : public N
{
public: 
    A():N(11,12,13),m_a(1)
    {
        cout << "cal A constrctor " << endl;

    }
    ~A(){}
public: 
    int m_a;
};

class B : public N
{
public: 
    B():N(21,22,23),m_b(2)
    {
        cout << "cal B constrctor " << endl;

    }
    ~B(){}
public: 
    int m_b;
};

class C: public B ,public A // C 的构造顺序与 此行的继承顺序相同。
{
public:
    C():A(),B(),m_c(3)
    {
        cout << "cal C constrctor " << endl;

    }
    void show()
    {
        cout << "m_c= " << m_c << endl;
    }

public:
    int m_c;


};

int main()
{
    C c1;
    c1.show();
    cout << "**" << endl;
    return 0;
}