#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m_map;
        for(int i : nums){
            m_map[i]++;
        }
        int resu = INT32_MIN;
        int cur_lenth = 0;
        for(int i = 0;  i < nums.size(); i++){
            int cur_num = nums[i];
            cur_lenth = 0;
            if(m_map.find(cur_num-1) != m_map.end()){ // 前一个存在
                //resu = 1;
                continue;
            }
            while(m_map.find(cur_num) != m_map.end()){
                cout << "cur_num= " << cur_num << endl;
                cur_lenth++;
                cur_num++;
            }
           // cout << "cur_lenth= " << cur_lenth << "cur_num= " << cur_num << endl;
            resu = max(resu, cur_lenth);

        }
        return resu;
        

    }
};

int main()
{
    Solution s1;
    vector<int> nums = {100,4,200,1,3,2};
    cout << "main resu= " << s1.longestConsecutive(nums) << endl;
    return 0;

}