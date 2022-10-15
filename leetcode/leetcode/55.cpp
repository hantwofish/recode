#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) { //贪心
        int n = nums.size();
        int far_dis = 0 ; //可以到达的最远距离
        for(int i = 0 ; i < n-1 ; i++)
        {
            far_dis = max(far_dis , i + nums[i]);
            if(far_dis <= i) // 不可到达 i 位置
                return false;
            
        }
        if( far_dis >= n-1)
            return true;
        else
            return false;


    }

};

int main()
{
    vector<int>nums = {0,2,3};
    Solution s1;
    bool resu = s1.canJump(nums);
    cout << "main resu= " << resu << endl;

    return 0;
}