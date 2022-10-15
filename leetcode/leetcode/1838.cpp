#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    typedef long long LL;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0, ans =1;
        LL sum = 0;
        for(int right =1 ; right < n ; right++){
            sum += (LL)(nums[right] - nums[right-1] )*(right-left);
            //sum += (LL)(nums[r] - nums[r - 1]) * (r - l);
            while(sum > k){
                sum -= nums[right] - nums[left++];
            }
            ans = max(ans,right-left+1);
        }
        return ans;

    }
};

int main()
{
    vector<int>nums = {1,4,8,13};
    int k = 5;
    Solution s1;
    int resu = s1.maxFrequency(nums,k);
    cout << "main resu= " << resu << endl;
    return 0;
}