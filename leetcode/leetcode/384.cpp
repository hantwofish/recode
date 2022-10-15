
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        data = nums;
    }
    
    vector<int> reset() {
        return data;

    }
    
    vector<int> shuffle() {
        vector<int> d_data; // 生成随机数
        int N = data.size();
        for (size_t i = 0; ; i++)
        {
            int num = (rand() % N);
            if(find(d_data.begin(),d_data.end(), num) == d_data.end()) {
                d_data.push_back(num);
            }
            if(d_data.size()== N){
                break;
            }
        }

        vector<int>re_data;
        for(int i = 0 ; i< N; i++){
            re_data.push_back(data[d_data[i]]);
        }
        return re_data;
        
    }
private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */