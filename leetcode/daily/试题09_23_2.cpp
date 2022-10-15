#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
public:
    int cal(vector<char>&nums , int N)
    {
        vector<bool> isvisited(nums.size(),0);
        backtracing(nums, N, temp , 0, isvisited);
        print_(resu);
        return resu.size();

    }
    void backtracing(vector<char>&nums, int N , string temp, int index ,
                        vector<bool> &isvisited )
    {
        if(temp.length() == N && find(resu.begin(),resu.end(),temp) == resu.end()){
            resu.push_back(temp);
           // cout << "temp= " << temp << endl;
           return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1] && !isvisited[i-1]){
                continue;
            }else if( isvisited[i] )
                continue;
            else{
                temp += (nums[i] );
                isvisited[i] = true;
                backtracing(nums,N,temp, index+1, isvisited);
                temp.pop_back();
                isvisited[i] = false;
            }
        }

    }
    // 测试打印
    void print_(vector<string >& str)
    {
        for(int i = 0 ; i < str.size() ; i++){
            cout << " " << str[i];
        }
        cout << endl;
    }
private:    
    vector<string >resu;
    string temp = "";


};


int main()
{
    vector<char>nums = {'0','1','2','3','A'};
    int N = 3;
    Solution s1;
    int resu =  s1.cal(nums, N);
    cout << "resu = " << resu << endl;
    
    return 0;
}

