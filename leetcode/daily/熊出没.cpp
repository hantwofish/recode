/* 
参考;
https://mp.weixin.qq.com/s/V-P10tZFoTGX-O_0d7WNIA
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
//
int picker(int i , int j,vector<int>nums);
bool CanFistBearWin(vector<int> nums);



//


bool CanFistBearWin(vector<int> nums)
{
    return picker(0,nums.size()-1,nums) >= 0;
}

int picker(int i , int j,vector<int>nums)
{
    if(i==j)
        return nums[i];
    int head = nums[i] - picker(i+1,j,nums);
    int end = nums[j] - picker(i,j-1,nums);
    return max(head,end);
}

int main()
{
    vector<int>nums ={0,0,0,0};
    bool result = CanFistBearWin(nums);
    cout << "result= " <<result <<endl;
    return 0;
}