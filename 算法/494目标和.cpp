#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        int curSum = 0;
        backTraing(nums, 0, target, curSum);

        return resu;
    }
    void backTraing(vector<int>& nums, int curIndex, int target, int& curSum)
    {
        //cout << "backTrcing" << " index= " << curIndex << endl;

        if(curIndex == nums.size()){
            cout << "curSum= " << curSum << endl;
            if(curSum == target){
                resu++;             
            }
            return;
        }
        // 两种状态 做选择
        curSum = curSum + nums[curIndex];
        backTraing(nums, curIndex+1, target, curSum);
        curSum = curSum - nums[curIndex];

        // 
        curSum = curSum + (-nums[curIndex]);
        backTraing(nums, curIndex+1, target, curSum);
        curSum = curSum - (-nums[curIndex]);
    }
public:
    int resu = 0;
    //int curSum = 0;
};

int main()
{
    Solution s1;
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    int resu = s1.findTargetSumWays(nums,target);
    cout << "main:: resu = " << resu << endl;
    return 0;
}