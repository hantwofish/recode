#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        resultLength = 0;
        int left = 0;
        int right = 0;
        int tempLength;
        for( left = 0; left < nums.size(); left++ ){
            int maxValue = nums[left];
            int minValue = nums[left];
            tempLength = 0;
            for( right = left; right < nums.size(); right++){
                    maxValue = maxValue > nums[right] ? maxValue : nums[right];
                    minValue = minValue < nums[right] ? minValue : nums[right];
                    if(maxValue - minValue > limit){
                        break;
                    }
                    tempLength = right - left + 1;
                    cout << "left= " << left << " right= " << right << " tempLength= " << tempLength << endl;
                    resultLength = resultLength > tempLength ?  resultLength :  tempLength ;
            }
            
        }
        
        return resultLength;

    }

public:
    int resultLength;    
};

int main()
{
    Solution s1;
    vector<int>nums = {4,2,2,2,4,4,2,2};
    int limit= 0;
    int result  = s1.longestSubarray(nums, limit);
    cout << "rsult= " << result << endl;
    return 0;
}