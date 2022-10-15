#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            
            path.push_back(nums[i]);
            //used[i] = true;
            backtracking(nums, i + 1, used);
           // used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
};

int main()
{
    Solution s1;
    //vector<int>nums = {2,2,3};
    
    int N ;
    cin >> N;
    vector<int>nums(N,0);
    for(int i = 0 ; i <N; i++){
        int a;
        cin >> a;
        nums[i] = a;
    }
    
    vector<vector<int>> resu  = s1.subsetsWithDup(nums);
    
    for(int i = 0; i< resu.size(); i++){
        for(int j  = 0 ; j < resu[i].size() ; j++){
            //cout << resu[i][j] << " ";
        }
       // cout << endl;
    }
    // 计算结果；
    int output = 0;
    for(int i = 0 ; i < resu.size() ; i++ ){
        if( output > 1000000007){
            output = output % 1000000007;
        }
        if(resu[i].size()==0){
            output += 0;
        }else if(resu[i].size() == 1){
            output += resu[i][0] * 2;
        }else {
            sort(resu[i].begin(),resu[i].end());
            output = output + (resu[i][0] + resu[i][resu[i].size()-1]) ;
        }
    }
    //cout << "output = " << output << endl;
    if( output > 1000000007){
            output = output % 1000000007;
        }
    cout << output << endl;

    return 0;
}

