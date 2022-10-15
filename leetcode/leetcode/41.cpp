#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
        // 去重
        unordered_set<int> m_set;
        for(int i = 0 ; i < nums.size() ; i++){
            m_set.insert(nums[i]);
        }
        vector<int> nu (m_set.begin(),m_set.end());
        nums = nu;
        sort(nums.begin(),nums.end());
        int n_size = nums.size();
        cout << "nums.size()= " << nums.size() << endl;




        int min_p = -1; // 最小的正整数
        int min_p_index;
        for(int k = 0 ; k < n_size ; k++){
            if(nums[k] > 0){
                min_p = nums[k];
                min_p_index = k;
                break;
            }
        }


        if(min_p <= 0)
            return 1;
        cout << "min_p= " << min_p << endl;
        cout << "min_index= " << min_p_index << endl;
        cout << nums[n_size-1] << endl;
        int i ;
        for( i =1 ; i <= nums[n_size-1] ; i++)
        {
            
            if( i < nums[min_p_index]){
                cout << "i= " << i << endl;
                return i;
            }
            min_p_index ++;

        }
        //if(min_p_index > n_size)
        return nums[n_size-1]+1;
        

    }
};

int main()
{
    vector<int>nums = {1,1,1,3,4,4,4,4};
    Solution s1;
    int resu = s1.firstMissingPositive(nums);
    cout << "resu= " << resu << endl;
    return 0;
}