#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void myprint(vector<int>&resu);

vector<int> fun(vector<int>nums, int m , int k)
{
    vector<int>resu;
    resu.push_back(1);
    resu.push_back(2);
    return resu;
}
vector<int>fun_2(vector<int>nums, int m , int k)
{
    vector<int>resu;
    for(int i = 0 ; i < nums.size(); i++){
        if(nums[i] == k){
            resu.push_back(i);
        }
    }
    return resu;

}

int main()
{
    vector<int>nums = {1,2,3,2,1,0,-1,0,1};
    int m = 1;
    int k = 3;
    vector<int>resu = fun(nums, m ,k);
    myprint(resu);
    resu = fun_2(nums,m,k);
    myprint(resu);
    return 0;
    
}
void myprint(vector<int>&resu)
{
    for(auto &i : resu){
        cout << " " << i ; 
    }
    cout << endl;
   
}