#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int n  = nums.size();
        vector<int>dp(n, 0);// 以第 i 个数字结尾的最长上升子序列的长度（包含nums[i]）;
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            dp[i] = 1;
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }
        /*
        for(auto i : dp){
            cout << " " <<  i ;
        }
        cout << endl;
        */
        
        sort(dp.begin(),dp.end());
        return dp[n-1];
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {0,1,0,3,2,3};
    int resu = s1.lengthOfLIS(nums);
    cout << "main resu= " << resu << endl;
    return 0;
}