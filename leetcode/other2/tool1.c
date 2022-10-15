#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
    dp[i] : 从索引 i 跳到最后，所需要的步数


*/


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        vector<int>dp(nums.size(), 0);
        int cur_peach = 0;
        for(int i = nums.size()- 1 ; i >= 0 ; i--)
        {
            if(i == nums.size()-1) 
            {
                dp[i]= 0;
                continue;
            }
            // 在 当前 i 位置，可以跳得到的范围内 ，找去最小值
            int in_min = dp[i+1];
            for(int k = i +  1 ; k <= i + nums[i] && k < nums.size() ; k++)
            {
                in_min = min(in_min , dp[k] );
            }
                
            dp[i] =  in_min +1;
            
        }
        cout << "------" << endl;
        my_print(dp);
        cout << "------" << endl;
        return dp[0];
    }
    void my_print(vector<int>&nums)
    {
        for(int i = 0 ;  i < nums.size();i++)
        {
            cout << " " << nums[i] << " ";
        }
        cout << endl;
    }
};

/*
int main()
{
    Solution s1;
    vector<int>nums = {2,1,3};
    int result = s1.jump(nums);
    
    cout << "main resu = " << result << endl;
    return 0;
}
*/