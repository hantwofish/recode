#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int resu = 0;
        for(int i = 0; i < 32 ; i++){
            int num_zero = 0;
            int num_one  = 0;
            for(int j = 0 ; j < nums.size(); j++) {
                if( (nums[j] & 1) == 0){
                   // cout << "*0* " << (nums[j] & 1 )<< endl;
                    num_zero++;
                }else if((nums[j] & 1) == 1){
                   // cout << "*1* " << (nums[j] & 1 )<< endl;
                    num_one++;
                }
                nums[j] = nums[j] >> 1;
                cout << "nums[" << j<<"]= " << nums[j] << endl; 

            }
            cout << "i= " << i << " " << num_zero << " " << num_one << endl;
            resu += (num_zero * num_one);
        }
        return resu;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {4,14,2};
    int resu = s1.totalHammingDistance(nums);
    cout << "main resu= " << resu << endl;
  
    
    return 0;

}