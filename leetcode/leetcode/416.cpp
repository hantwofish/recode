#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            sum += nums[i];
        if(sum %2 != 0) 
            return false;
       // sort(nums.begin(),nums.end());
        int beg_W = sum/2;
        int N = nums.size();
        
        vector<vector<bool>>dp(N+1,vector<bool>(beg_W+1,false));
        for(int i = 0 ; i <= N ; i++)
            dp[i][0] = true;

        for(int i = 1 ; i <= N ; i++) // 第 i 个物品
            for(int w = 1 ; w <= beg_W  ; w++) // 背包容量
            {
                // 当前物品的重量 为 nums[i-1]
                if(w < nums[i-1] ) // 不可放置
                    dp[i][w] = dp[i-1][w];
                else // 可以放置 ,选择 放 与 不放
                    dp[i][w] = dp[i-1][w] | dp[i-1][w - nums[i-1]];

                
            }
        return dp[N][beg_W];
    }
};


int main()
{
    Solution s1;
    vector<int> nums= {1,5,11};
    bool resu = s1.canPartition(nums);
    if(resu)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;

}