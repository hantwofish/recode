#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT32_MIN);
        nums.push_back(INT32_MIN);
        for(int i =  1 ; i < nums.size()-1; i++){
            if( nums[i] > nums[i-1] && nums[i] > nums[i+1] ){
                return i - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int>nums = {1,2,1,3,5,6,4};
    Solution s1;
    int resu = s1.findPeakElement(nums);
    cout << " resu= " << resu << endl;
}