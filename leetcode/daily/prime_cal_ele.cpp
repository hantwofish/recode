// 计算因子
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector> 
#include<map>
#include<unordered_set>
#include<algorithm>

using namespace std;
vector<int> resu;
void cal_ele(int num)
{
    for(int i = 2; i < num ; i++){
        if(num % i == 0){
            cout << i << " ";
        }
    }
}

int main()
{
    cal_ele(822);
    return 0;
}