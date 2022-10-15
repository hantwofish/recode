#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j  = 0 ; j < i ; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }else{
                    dp[i] = dp[i];
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

int main()
{
    vector<int>nums ={0,1,0,3,2,3};
    Solution s1;
    int resu = s1.lengthOfLIS(nums);
    cout << "resu= " << resu << endl;
    return 0;
}