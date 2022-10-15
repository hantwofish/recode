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
class solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>mid;
        mid.clear();
        resu.push_back(mid);
        backtracing( nums, 0 ,mid );
        return resu;
    }
    void backtracing( vector<int>&nums ,int dep, vector<int>&mid )
    {
        if(!mid.empty())
        {
            resu.push_back(mid);
            
        }
        if( dep == nums.size()   )
            return;
        for(int i = dep ; i < nums.size() ; i++ )
        {
            mid.push_back(nums[i]);
            backtracing(nums, i +1 , mid);
            mid.pop_back();
        }
    } 

private:
    vector<vector<int>> resu;

};

int main()
{
    vector<int>nums= {1,2,3};
    solution s1;
    vector<vector<int>> resu = s1.subsets(nums);
    myprint(resu);
    return 0;

}