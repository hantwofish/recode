#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void printVector(vector<vector<int>>&nums)
{
    for(int i = 0 ; i< nums.size(); i++){
        for(int j = 0; j <nums[i].size();j++){
            cout<<nums[i][j] << " ";
        }
        cout<< endl;
    }

}

// 子集 907
class Solution1 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        subSets(arr);
        printVector(resultArray);
        cout << "sumSubarrayMins:: resultArray.size()= " << resultArray.size() << endl;
        return 0;
    }
    void subSets(vector<int>& nums)
    {
        // 记录走过的路径；
        vector<int>track;
        backtrack(nums,0,track);
    }
    void backtrack(vector<int>&nums, int start, vector<int>&track)
    {
        resultArray.push_back(track);
        cout << "start= " << start << " track.size()= "<< track.size() <<  " resultArray.size()= " << resultArray.size() << endl;
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

// 组合
class Solution2 {
public:
    int solutionMain(vector<int>& arr) 
    {
        vector<int>track;
        bacakTrack(arr,0,track);
        printVector(resultArray);
        return 0;
    }
    void bacakTrack(vector<int>&nums, int start, vector<int>&track)
    {
        if(track.size() == K){
            resultArray.push_back(track);
        }
        for(int i = start ; i < nums.size(); i++ ){
            track.push_back(nums[i]);
            bacakTrack(nums, i+1, track);
            track.pop_back();
        }
    }
public:
    vector<vector<int>>resultArray;
    int K =2;
};

// 排列
class Solution {
public:
    int solutionMain(vector<int>& arr) 
    {
        vector<int>track;
        bacakTrack(arr,0,track);
        printVector(resultArray);
        return 0;
    }
    void bacakTrack(vector<int>&nums, int start, vector<int>&track)
    {
        cout << "bacakTrack::track.size()= " << track.size() << endl;
        if(track.size() == nums.size()){
            resultArray.push_back(track);
            return;
        }
        for(int i = 0 ; i < nums.size(); i++ ){
            if(find(track.begin(),track.end(),nums[i])!= track.end()){
                continue;
            }
            track.push_back(nums[i]);
            bacakTrack(nums, i+1, track);
            track.pop_back();
        }
    }
public:
    vector<vector<int>>resultArray;
};

int main()
{
    Solution s1;
    vector<int> arr = {1,2,3,4};
    int resu = s1.solutionMain(arr);
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