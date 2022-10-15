#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int max_num = nums[0];
        int min_num = nums[0];
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] < min_num){
                min_num = nums[i];
            }else if(nums[i] > max_num){
                max_num = nums[i];
            }
        }

        int result = 0;
        result = (max_num - k - (min_num + k));
        return result;

    }
};

int main()
{
    cout << " hello" << endl;
    return 0;
}