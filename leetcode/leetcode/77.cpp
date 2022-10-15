#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint( vector<vector<int>> &resu)
{
    for(int i=0; i < resu.size();i++)
    {
        for(int j= 0; j< resu[i].size(); j++)
        {
            cout << resu[i][j] << " ";
        }
        cout <<endl;
    }
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>nums;
        vector<int>mid;
        for(int i = 0 ; i< n ; i++)
        {
            nums.push_back(i+1);
        }
            
        backtracing(nums, k , 0, mid);
        return resu;

    }
    void backtracing( vector<int>&nums , int k ,  int index ,vector<int>&mid   ) // 从index开始
    {
        if( mid.size()== k )
        {
            resu.push_back(mid);
            return ;
        }
        
        for(int i = index ; i< nums.size() ; i++)
        {
            mid.push_back(nums[i]);
            backtracing(nums, k, i + 1 , mid);
            mid.pop_back();
        }
    }

private:
    vector<vector<int>> resu;
};


int main()
{
    Solution s1;
    int n = 4;
    int k = 2;
    vector<vector<int>> resu = s1.combine(n,k);
    myprint(resu);
    return 0;

}