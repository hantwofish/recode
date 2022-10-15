#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int resu = 0;
        int mid_size = (nums.size() % 2 ==1) ? (nums.size()+1) / 2 : nums.size()/2;
        for(int i = 0 ; i < mid_size ; i++){
            resu += ( nums[nums.size()-1-i] - nums[i]  );
        }

        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,2,3};
    int action_times = s1.minMoves2(nums);
    cout << "resu= " << action_times << endl;
    return 0;
}