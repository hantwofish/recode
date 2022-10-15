
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



class Solution2 {
public:
    int maxCoins(vector<int>& nums) {
        vector<int>is_visited(nums.size(),false);

        if(nums.size() == 1)
            return nums[0];
        backtracing(nums, 0 , is_visited);

       // cout << " *** " << endl;
        return max_resu;
    }
    // 回溯
    void backtracing( vector<int>&nums , int start_loca  , vector<int>&is_visited) 
    {
        int left = 1,right = 1;
        int add_nums = 0;
    
        if(start_loca > nums.size()-1)
        {
           // cout << "mid_resu= " << mid_resu << endl;
            max_resu = max(max_resu , mid_resu);
           // cout << "max_resu= " << max_resu << endl;
            return;
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            left = 1;
            right = 1;
            if(is_visited[i])
                continue;
            // 计算 add_nums ,从 当前位置分别向左右找到第一个 未被访问的元素
            if( i - 1 < 0)
                left = 1;
            else if(i +1 > nums.size()-1)
                right = 1;

            for(int front_inde =  i-1  ; front_inde >= 0 ; front_inde--)
            {
                if(!is_visited[front_inde])
                {
                    left = nums[front_inde];
                    break;
                }
                    
            } 
            for(int bacK_ind = i +1 ; bacK_ind < nums.size(); bacK_ind++)
            {
           //     cout << "** bacK_ind= "<< bacK_ind << " is_visited= " << is_visited[bacK_ind] << endl;

                if(!is_visited[bacK_ind])
                {
                    right = nums[bacK_ind];
                    break;
                }
                    
             //   cout << "** right = " << right << endl;
            }

            add_nums = left * nums[i] * right;
         //   cout << "left= " << left << "  cur= " << nums[i] << "   right= " << right << endl;
            //
            is_visited[i] = true;
            mid_resu += add_nums;
          //  cout << "add_nums= " << add_nums << endl;
            backtracing(nums, i+1 , is_visited);
            is_visited[i] = false;
            mid_resu -= add_nums;

        }
            

    }
public:
    int max_resu = 0; //最后输出结果
    int mid_resu = 0 ; // 一种排列方式下的中间结果
};


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        backtracing(nums,0);
        return result;

    }
    void backtracing(vector<int>&nums , int start_loca)
    {
        // 
        if(nums.size()== 0)
        {
            result = max(result , mid_resu);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int left = i- 1 < 0 ? 1 : nums[i-1];
            int right = i + 1 > nums.size()-1 ? 1 : nums[i+1];
            int cur = nums[i];
            mid_resu += left * cur * right;
            nums.erase(nums.begin()+i);
            backtracing(nums, i +1);
            nums.insert(nums.begin()+i,cur);
            mid_resu -= left * cur * right;
        }
        

    }
public:
    int result = 0;
    int mid_resu = 0;
};



int main()
{
    vector<int>nums = {7,9,8,0,7,1,3,5,5,2,3};
   // sort(nums.begin(),nums.end());

    Solution s1;
    int resu = s1.maxCoins(nums);

    cout << "main resu= " << resu << endl;
    cout << "INT_MAX  = " << INT32_MAX << endl;
    return 0;
}