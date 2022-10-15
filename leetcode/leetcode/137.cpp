#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for(auto& i : nums){
            u_map[i]++;
        }
        auto it = u_map.begin();
        while(it != u_map.end()){
            if(it->second ==1) {
                return it->first;
            }
        }
        return 0;
    }
};