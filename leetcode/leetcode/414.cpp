#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int>data(3,INT32_MIN);
        vector<bool>visited(3,false);
        int i = 0;
        for(i = 0 ; i < nums.size(); i++){
            int cur_num = nums[i];
           if(visited[2] == false || cur_num > data[2]){

           }else if( cur_num < data[2] && (visited[1] == false || data[1] < cur_num) ){


           }else if(visited[1]!= false && cur_num < data[1] && ( visited[0] == false || ))

        }




        for(auto i : visited){
            cout << i << " ";
            if(!i){
                return data[2];
            }
        }
        cout << endl;
        return data[0];

    }
};



int main()
{
    Solution s1;
    vector<int>nums = {3,2,1,4};
    int resu = s1.thirdMax(nums);
    cout << "main resu= " << resu << endl;
    return 0;
}