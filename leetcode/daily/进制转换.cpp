#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<int> change(int num, int N)
{
    stack<int>stk;
    vector<int>resu;
    while(num != 0){
        stk.push(num%N);
        num = num / N;

    }
    while(!stk.empty()){
        resu.push_back(stk.top());
        stk.pop();

    }
    for(int i : resu){
        cout << i << " ";
    }
    cout << endl;
    return resu;
} 

int main()
{
    int num = 159;
    int N =8 ;
    change(num,N);
    return 0;
}