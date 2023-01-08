#include"STLCOMMON.h"
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sumTotal = 0;
        for(auto i : nums){
            sumTotal += i;
        }
        int target = sumTotal - x;
        cout << "SumTotal= " << sumTotal << " target= " << target << endl;
        if(target <0 ){
            return -1;
        }
        int times = -1;
        int left = 0;
        int right = 0;
        int curSum = 0;
        while( right < nums.size()){
            // 增大窗口
            curSum += nums[right];
           
            // 是否需要缩小窗口
            while(curSum > target){
                curSum -= nums[left];
                left++;
            }
            if(curSum == target){
                times = max(times, right - left +1);
            }
            right++;


        }
        return times < 0 ? -1 : nums.size()- times;
    }
};

int main()
{
    Solution s1;
    vector<int>nums={1,1,4,2,3};
    int x = 5;
    int resu= s1.minOperations(nums, x);
    cout << "main:: resu= " << resu << endl;
    return 0;
}