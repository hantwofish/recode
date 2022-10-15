#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<string>
using namespace std;

int cal(vector<int>&nums)
{
    int N = nums.size();
    int resu  = INT32_MIN;
    for(int i = 0 ; i < N ; i++){
        for(int j = i+ 1 ; j < N ;j++){
            int base = nums[j] / nums[j];
            int front  = nums[i] ;
            int second = nums[j];
            int mid_resu  = 2;
            for(int k = j+1 ; k < N ; k++) {
                if(front * nums[k] == second* second){
                    mid_resu++;
                    front = second;
                    second = nums[k];
                }

            }
            resu = max(resu, mid_resu);
        }
    }
    return resu;

}

int main()
{
    /*
    int N ;
    cin >> N;

    vector<int>nums(N,0);
    for (int i = 0; i < N; i++)
    {
        int tem ;
        cin >> tem;
        nums[i] = tem;
    }
    
    unordered_set<int>mid (nums.begin(),nums.end());
    vector<int>nums2(mid.begin(),mid.end());
    sort(nums2.begin(),nums2.end());
    */
    vector<int>nums = {1,2,2,4,10};
    sort(nums.begin(),nums.end());

    //cout << nums.size() << " " << nums2.size() << endl;
    int resu = cal(nums);
    cout << "resu = " << resu <<endl;
}