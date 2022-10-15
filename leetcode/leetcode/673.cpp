#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()== 0){
            return 0;
        }
        int N = nums.size(); 
        int maxLen = 0;
        int ans = 0;
        vector<int>dp(N,0); // 以 nums[i] 结尾的最长子序列的长度
        vector<int>cnt(N,0); // 以 nums[i] 结尾的最长子序列的个数；
        // dp(N,0)
  
        for(int i = 0; i < N ; i++){
            dp[i] = 1;
            cnt[i] = 1;
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j]){
                   if( dp[j]+1 >  dp[i]){
                       dp[i] = dp[j]+1;
                       cnt[i] = cnt[j];
                   }else if(dp[j]+1 == dp[i]){
                       cnt[i] += cnt[j];
                   }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i]; // 重置计数
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }




        }


        return ans;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,3,5,4,7};
    int resu = s1.findNumberOfLIS(nums);
    cout << "resu main= " << resu << endl;
    return 0;
}