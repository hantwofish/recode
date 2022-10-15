#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<map>
#include<algorithm>

using namespace std;

int  m_i = 900;
vector<int> unit;
vector<int> unit_2 ;
vector<int> unit_3 ;

int gcd(int x,int y)
{
    int t;
    while (y) t=x, x=y, y=t%y;
    return x;
}

void print_vec(vector<int>& unit)
{
    for(auto i : unit){
        cout << i <<  " ";
    }
    cout << endl;
}

void cal_2_3_unit(vector<int>& unit )
{
    for(int i = 0 ; i < unit.size() ; i++){
        unit_2.push_back( (2 * unit[i] )% m_i);
        unit_3.push_back( (3 * unit[i] )% m_i);
    }
}


int mod_n(int N , int M)
{
    return N % M;
}
int main()
{ 
    for(int i = 1; i <= m_i ; i++){
        if(gcd(i,m_i) == 1){
            unit.push_back(i);
        }

    }

    cal_2_3_unit(unit);
    print_vec(unit);
    print_vec(unit_2);
    print_vec(unit_3);

    cout << " " << mod_n(41,m_i) << endl;
    cout << " " << mod_n(237*29,m_i) << endl;
    cout << " " << mod_n(57*29,m_i) << endl;
    return 0;

}