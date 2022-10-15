#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int kInversePairs(int n, int k) {

    }
    int cal_num(vector<vector<int>>nums, int k)
    {
        int resu = 0;
        for(auto cur : nums){
            resu += cal_one(cur,k);
        }
        return resu;
    }
    int cal_one(vector<int>nums, int k) // 数字的逆序数是否为 k
    {
        int times = 0;
        for(int i =0 ; i < nums.size(); i++){
            for(int j  = i+1 ; j < nums.size(); j++){
                if(nums[i] > nums[j]){
                    times++;
                    if(times > k){
                        return 0;
                    }
                }
            }
        }
        if(times == k){
            return 1;
        }
        return 0;

    }
    // 1-N 的全排列
    void tracing(int N , vector<int>& temp, vector<bool>& visited)
    {
        if(temp.size() == N){
            data.push_back(temp);
            return;
        }
        for(int i = 1 ; i <= N; i++){
            if(visited[i] == true){
                continue;
            }
            temp.push_back(i)
        }

    }
private:
    vector<vector<int>>data;


};

int main()
{

}