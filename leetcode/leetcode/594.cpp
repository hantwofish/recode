#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m_data;
        for(int i = 0 ; i < nums.size(); i++){
            m_data[nums[i]]++;
        }

        for(auto it = m_data.begin(); it != m_data.end() ; it++){
            cout << " " << it->first << " " << it->second << endl;
        }

        cout << "m_data.sie()= "<< m_data.size() << endl;
        int resu = INT32_MIN;
        for(auto it = m_data.begin(); it != m_data.end() ; it++){
            int num = it->first;
            if(m_data.count(num+1)){
                resu = max(resu, m_data[num] + m_data[num+1]);
            }
            
        }
        return resu;

    }
};

int main()
{
    Solution s1;
    vector<int>nums = {1,3,2,2,5,2,3,7};
    int resu = s1.findLHS(nums);
    cout << "resu= " << resu << endl;
    return 0;
}