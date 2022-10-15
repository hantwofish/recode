
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
//对于一个类的设计
// 设计一个复数类
class Complex{
public:
    // 构造函数
    Complex(int a = 0 ,int b =0):re(a) , ml(b)
    {

    }
    int get_re(  ) const // 常量成员函数：不能在函数中 改变 num 的值，可被 常量或者非常量调用
    {
        return re;
    }
    int get_ml( ) const
    {
        return ml;
    }
    Complex operator += (Complex& nums_two)
    {
        this->re += nums_two.re;
        this->ml += nums_two.ml;
        return *this;
    }

    

private:
    int re; // 复数的实部
    int ml; // 复数的虚部


};

Complex operator + (Complex& num1 , Complex& num2)
{
    return Complex(num1.get_re()+ num2.get_re() , num1.get_ml() + num2.get_ml() );
}

int main()
{
    // 临时变量
    Complex(1,2);
    Complex();
    // 定义 num 对象
    Complex num(2,1);
    Complex num2(3,3);
    Complex nn = num + num2;
    cout << nn.get_re() << " " << nn.get_ml() << endl;

    return 0;
    num += num2;
    cout << num.get_re() << " " << num.get_ml() << endl;
    const Complex num3(3,3);
    cout << num3.get_re() << " " << num3.get_ml() << endl;

}

