#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N  = nums.size();
        vector<int>data(N+1,0);
        for(int i = 0 ; i < N ; i++){
            data[nums[i]] = 1;
        }
        for(int i = 0 ; i <= N ; i++){
            if(data[i] == 0){
                return i;
            }
        }
        return 0;

    }
};
int main()
{
    Solution s1;
    vector<int>nums = {3,0,1};
    cout << s1.missingNumber(nums) << endl;
    return 0;
}