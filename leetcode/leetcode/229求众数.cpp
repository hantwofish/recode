#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size() / 3;
        unordered_map<int, int> m_map;
        for(int i = 0 ; i< nums.size(); i++){
            m_map[nums[i]]++;
        }
        vector<int> resu ;
        auto it = m_map.begin();
        while(it != m_map.end()) {
            if(it->second > N){
                resu.push_back(it->first);
            }
            it++;
        }
        return resu;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,1,1,3,3,2,2,2};
    vector<int>resu = s1.majorityElement(nums);
    for(int i = 0 ; i < resu.size(); i++){
        cout << resu[i] << " ";
    }
    cout << endl;
    return 0;

}