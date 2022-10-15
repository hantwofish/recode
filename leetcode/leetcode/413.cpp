#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>


using namespace std;
// 暴力解法
class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int resu = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+2 ; j < nums.size(); j++){
                if(isArithmeArry(nums, i ,j)){
                    resu ++;
                }
            }

        }
        return resu;

    }
private:
    bool isArithmeArry(vector<int>&nums, int start ,int end)
    {
        if(end - start < 2)
            return false;
        for(int i = start ; i < end -1 ; i++){
            if(nums[i+1] * 2 != nums[i] + nums[i+2])
                return false;
        }
        return true;
    }
};

// 对于连续的子数组-> 滑动窗口(双指针)
class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0;
        int n_lenth = nums.size();
        cout << "nums.size()= " << nums.size() << endl;
        cout << "nums.size()-2 = " << nums.size()-2 << endl;
        cout << n_lenth -2 << endl;
        // for(int i = 0 ; i < nums.size() - 2;i++){
        for(int i = 0 ; i < n_lenth - 2;i++){
          //  cout << "**" << endl;
            int distance = nums[i+1] - nums[i];
            for(int j = i+ 2 ; j < nums.size(); j++){
                if(nums[j] - nums[j-1] == distance){
                    result++;
                }
                else
                {
                    break;
                }
                
            }
        }
        return result;
    }
};


class Solution3{
public:
    int numberOfArithmeticSlices(vector<int>&nums){
        int n_lenth = nums.size();
        if(n_lenth < 3){
            return 0;
        }
        resu = 0;
        silices(nums,n_lenth - 1);
        cout << "result= " << resu << endl;
        return resu;
    }
    // 定义 nums[0,end]中，以end 作为终点(等差数列的最后一个元素)，等差数列的个数
    int silices(vector<int>&nums, int end)
    {
        cout << "end= "<< end << endl;
        if(end < 2){
            return 0;
        }
        int cur = 0; // 以 end 结束的等差数列的个数
        if(nums[end] - nums[end -1] == nums[end -1 ] -nums[end-2]){
            cur =  silices(nums,end-1) +1;
            resu += cur;
            return cur;
            
        }
        else
        {
            silices(nums,end-1);
            return 0;
        }
       

        
    }
public:
    int resu;

};

int main()
{
    Solution3 s1;
    vector<int>nums = {1,2,3,4,5,6};
    int result_s1 = s1.numberOfArithmeticSlices(nums);

   // cout << "main_resu= " << result_s1 << endl;
   return 0;
    
}

/*

https://leetcode-cn.com/problems/arithmetic-slices/solution/fu-xue-ming-zhu-bao-li-shuang-zhi-zhen-d-fc1l/
*/