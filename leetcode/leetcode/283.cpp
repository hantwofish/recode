#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        
    }
public:
    void my_print(vector<int>&nums)
    {
        for(auto&i : nums){
            cout << i << " ";
        }
        cout << endl;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,2,0,7,4,0,0,7,0};
    s1.my_print(nums);
    s1.moveZeroes(nums);
    s1.my_print(nums);
    return 0;

}