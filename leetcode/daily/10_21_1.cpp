#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int find_lost_num(vector<int>&nums)
{
    int resu = 1;
    int exists = 0;
    int i =1;
    for(resu = 1 ; resu <= INT32_MAX ;resu++){
        for( i = 0 ; i < nums.size();i++){
            if(resu == nums[i]){
                exists = 1;
                break;
            }
            
        }
        if(i == nums.size()){
            exists = 0;
        }
        if(exists == 0){
            return resu;
        }
    }

    return 0;
}
int main()
{
    /*
    int N; 
    cin >> N;
    vector<int>nums(N,0);
    for(int i = 0; i < N ; i++){
        int temp;
        cin >> temp ;
        nums[i] = temp;

    }
    */
   vector<int>nums= {1,2,3};
    int resu = find_lost_num(nums);
    cout << "resu= " << resu << endl;
    return 0;
}