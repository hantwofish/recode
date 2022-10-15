#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()== 1){
            return 0;
        }
        int resu = INT32_MIN;
        int N = nums.size();
        for(int i = 0 ; i < N ; i++){
            for(int j = i+1 ; j < N ; j++){
                int a = nums[i] ^ nums[j];
                resu = max(resu , a);
            }
        }
        return resu;
    }
};

int main()
{
    vector<int>nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    Solution s1;
    int resu = s1.findMaximumXOR(nums);
    cout << "main resu= " << resu << endl;
    return 0;
}