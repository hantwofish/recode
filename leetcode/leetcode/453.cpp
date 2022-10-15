#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int min_num = nums[0];
        int times = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            times += (nums[i] - min_num);
        }
        return times;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,2,3};
    int action_times = s1.minMoves(nums);
    cout << "resu= " << action_times << endl;
    return 0;
}