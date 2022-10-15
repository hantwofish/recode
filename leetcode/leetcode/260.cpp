#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> u_map;
        vector<int>resu ;
        for(int i = 0 ; i < nums.size(); i++){
            u_map[nums[i]]++;
        }
        auto it = u_map.begin();
        while(it != u_map.end()){
            if(it->second == 1){
                resu.push_back(it->first);
            }
        }
        return resu;

    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for(int num : nums){
            xorsum ^= num;
        }

        // 找到用去区分 1 的为
        int lsb = 1;
        while((lsb & xorsum) == 0){
            lsb <<= 1;
        }
        
        int type1 = 0;
        int type2 = 0;
        for(int num : nums){
            if(num & lsb){
                type1 ^= num;

            }else{
                type2 ^= num;
            }
        }
        cout << " " << type1 << " " << type2 << endl;
        return {type1, type2};

    }
public:
    void print_bin(int n)
    {
        int i;
        for(i=sizeof(n)*4-1; i>=0; i --)
        {
            if(n&(1<<i))printf("1");
            else printf("0");
        }
        cout << endl;
    }
};

int main()
{
    Solution s1;
     vector<int>nums= {1,2,1,3,2,5};
     vector<int>resu = s1.singleNumber(nums);
    // s1.print_bin(-4);

    return 0;

}