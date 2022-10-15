#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
返回其中出现频率前 k 高的元素。
*/
bool compare(pair<int,int>& s1, pair<int,int>&s2)
{
    if(s1.second == s2.second)
        return s1.first < s2.first;
    else
        return s1.second > s2.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int num_size = nums.size();
        unordered_map<int,int>m_map;
        for(auto& i : nums){
            m_map[i]++;
        }
        vector<pair<int, int>> ve_res (m_map.begin(),m_map.end());
        sort(ve_res.begin(),ve_res.end(),compare);

        vector<int> result;
        for(int i = 0; i < k ; i++){
            result.push_back(ve_res[i].first);
        }
        return result;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,2,2,2,3};
    int k = 2;
    vector<int>resu = s1.topKFrequent(nums,k);
    for(auto& i : resu){
        cout << " " << i;
    }

    return 0; 

}