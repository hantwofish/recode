#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint( vector<vector<int>> &resu)
{
    for(int i=0; i < resu.size();i++)
    {
        for(int j= 0; j< resu[i].size(); j++)
        {
            cout << resu[i][j] << " ";
        }
        cout <<endl;
    }


}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backtracing(nums,0);
        return resu;

    }
    void backtracing( vector<int>& nums ,int cur   )
    {
        if( mid.size() == nums.size())
        {
            resu.push_back(mid);
            return;
        }
        for(int i= 0 ; i< nums.size();i++)
        {
            if( find(mid.begin(),mid.end(),nums[i]) != mid.end()  )
                continue;
            else
            {
                mid.push_back(nums[i]);
                backtracing(nums,cur+1);
                mid.pop_back();
            }
        }

    }
private:
    vector<vector<int>> resu;
    vector<int>mid;
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s1;
    vector<vector<int>> res = s1.permute(nums); 
    myprint(res);
    return 0;
}