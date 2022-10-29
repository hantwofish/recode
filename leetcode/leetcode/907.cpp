#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        return 0;
    }
    vector<vector<int>> subSets(vector<int>& nums)
    {
        // 记录走过的路径；
        vector<int>track;
        backtrack(nums,0,track);
        return resultArray;
    }
    void backtrack(vector<int>&nums, int start, vector<int>&track)
    {
        resultArray.push_back(track);
        // 从start 开始，防止产生重复的子集
        for(int i = start; i< nums.size(); i++){
            // 做选择
            track.push_back(nums[i]);
            // 递归回溯
            backtrack(nums, i+1, track);
            // 撤销选择
            track.pop_back();
        }
    }
public:
    vector<vector<int>>resultArray;
};


int main()
{
    Solution s1;
    vector<int> arr = {3,1,2,4};
    int resu = s1.sumSubarrayMins(arr);
    cout << "resu= " << resu << endl;
    return 0;
}


/*
1.  找出所有得子序列
2.  找出子序列得最小值
3.  最小值相加

*/

/* 题解
https://leetcode.cn/problems/sum-of-subarray-minimums/solution/-by-muse-77-367z/

*/