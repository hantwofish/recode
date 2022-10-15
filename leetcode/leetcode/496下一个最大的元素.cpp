#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>u_map;
        int j= 0;
        for(int i =0 ; i < nums2.size();i++){
            if(i == nums2.size()-1){
                u_map[nums2[i]] = -1;
                continue;
            }
            for( j = i+1; j < nums2.size(); j++){
                if(nums2[j] > nums2[i]){
                    u_map[nums2[i]] = nums2[j];
                    break;
                }
            }
            if(j == nums2.size()){
                u_map[nums2[i]] = -1;
            }
            
            
        }
        vector<int>resu;
        for(int i = 0 ; i< nums1.size(); i++){
            resu.push_back(u_map[nums1[i]]);
        }
        return resu;

    }
};

int main()
{
    Solution s1;
    vector<int>nums1= {4,1,2,3};
    vector<int>nums2 = {1,3,4,2};
    vector<int>resu = s1.nextGreaterElement(nums1,nums2);
    for(auto& i : resu){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}