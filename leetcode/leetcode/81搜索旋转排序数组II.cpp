#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid = 0;
        for(mid = 0; mid < nums.size(); mid++){
            if(mid == 0){
                continue;
            }
            if(nums[mid] < nums[mid-1]){
                break;
            }
        }
        if(mid == nums.size()){
            int resu = binnary_find(nums, 0, nums.size()-1, target);
            return resu == -1 ? false : true;
        }
        int resu = binnary_find(nums, 0, mid-1 , target);
        if(resu != -1){
            return true;
        }
        resu = binnary_find(nums, mid, nums.size()-1 , target);
        if(resu != -1){
            return true;
        }

        return false;

    }
    // 找到返回索引，找不到返回 -1
    int binnary_find(vector<int>&nums, int left, int right, int target)
    {
        int front  = left; 
        int end = right;
        while(front <= end ){
            int mid_num = nums[(front+end)/2];
            if(target == mid_num){
                return (front+end)/2;
            }else if(target > mid_num){
                front = (front + end)/2 + 1;
            }else if( target < mid_num ){
                end = (front + end)/2 - 1;;
            }
        }
        return -1;
    }

};

int main()
{
    Solution s1;
    vector<int>nums = {0,0,1,2};
    int target = 0;
    cout << (s1.search(nums,target) ? "true" : "false" );
    return 0;
}