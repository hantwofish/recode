#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n_lenth = nums.size();
        k = k % n_lenth;
        vector<int> data(nums.end()-k, nums.end()); // 后 k 个数
        //reverse(data.begin(),data.end());
        int count = 1;
        for(int j = n_lenth -1  ; j >= n_lenth -1 -k  ; j--){
            nums[j] = nums[j - k];
        }
        for(int j = 0; j < k ; j++){
            nums[j] = data[j];
        }
    }
    // 赋值
};

int main()
{
    Solution s1;
    vector<int>nums = {-1,-100,3,99};
    int k = 2;
    s1.rotate(nums,k);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}