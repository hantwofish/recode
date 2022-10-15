#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int>resu(2,0);
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                resu[0] = left + 1;
                resu[1] = right + 1;
                break;
            }else if(numbers[left] + numbers[right] > target){
                right--;
            }else if(numbers[left] + numbers[right] < target){
                left++;
            }
        }
        
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<int>nums = {2,7,11,15};
    int target = 18;
    nums = s1.twoSum(nums,target);
    for(auto& i : nums){
        cout << i << " ";

    }
    cout << endl;
    return 0;

}