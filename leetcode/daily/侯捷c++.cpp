#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Fraction
{
private:
    /* data */
    int m_numerator;
    int m_denominator; 
public:
    Fraction(int num , int den =1):m_numerator(num),m_denominator(den)
    {

    }
    operator double() const
    {
        return (double)((double)m_numerator / (double)m_denominator);

    }

};

int main()
{
    Fraction f(6,5);
    double d = 4.0 + f;
    cout << "d= " << d << endl;
    return 0;
}
