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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> isvisited(nums.size(),0);
        sort(nums.begin(),nums.end());
        backtracing(nums,0,isvisited);
        return resu;

    }
    void backtracing(vector<int>&nums,int cur,vector<bool> &isvisited)
    {
        
        // 终止条件
        if(mid.size()== nums.size())
        {
            /*
            if(  find( resu.begin(),resu.end(),mid ) == resu.end()       )
            {
                 resu.push_back(mid);
            }
            */
           resu.push_back(mid);
            return;
        }
        for(int i =0 ; i < nums.size(); i++)
        {
 

            if( i > 0 && nums[i] == nums[i-1] && !isvisited[i-1] ) // 
                continue;
            else if( isvisited[i] )
                continue;
            else
            {
                mid.push_back(nums[i]);
            //    cout << "mid.size=  " << mid.size() <<" " << endl;
                isvisited[i] = true;
                backtracing(nums,cur+1,isvisited);
                mid.pop_back();
                isvisited[i] = false;
            }
        }

    }


private:
    vector<int> mid;
    vector<vector<int>> resu;
    
};


int main()
{
    vector<int> nums = {1,1,3};
    Solution s1;
    vector<vector<int>> res = s1.permuteUnique(nums); 
    myprint(res);
    return 0;
}