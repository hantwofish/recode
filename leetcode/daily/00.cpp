#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void test();

int main()
{
    test();
  // cout << pow(10,3);
    return 0;
}

 // hoof

 void test()
{
    for(int i = 0; i < 27 ; i++)
    {
        if( i %3 ==0 )
        {
            cout <<"["<< 3  << "* " << i/3 << "]" << " ";
        }
    }


}

//