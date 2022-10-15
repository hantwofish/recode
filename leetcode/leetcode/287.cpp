#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++)
            sum += nums[i];
        return sum - N_sum(nums.size()-1);
    }
    int N_sum(int n)
    {
        return n*(n+1)/2;
    }
};

int main()
{
    vector<int>nums = {3,1,3,4,2};
    Solution s1;
    int resu = s1.findDuplicate(nums);
    cout << "resu= " << resu << endl;
    return 0;
}

