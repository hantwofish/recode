#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int N  = max(first.length(), second.length());
        vector<vector<int>>dp(N+1, vector<int>(N+1,0)); // dp(i+1,i+1) 表示从 从 first 的到索引 i 个字符到 seconde 所需要的操作数
        dp[0][0] = 0;
        for(int i = 1; i <= second.length(); i++){
            dp[0][i] = i;
        }
        for(int j = 1 ; j <= first.length() ; j++){
            dp[j][0]= j;
        }
                               
        for(int i = 0 ; i < first.size() ; i++){
            for(int j = 0 ; j < second.size(); j++){
                if(first[i] == second[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else{
                    int min1 = min(dp[i][j]+1 , dp[i+1][j] +1);
                    int min2 = min(min1 , dp[i][j+1]+1);

                    dp[i+1][j+1] = min2;
                }
            }
        }
        if(dp[first.length()][second.length()] <= 1){
            return true;
        }


        return false;
    }
};

int main()
{
    string first = "pale";
    string second = "ple";
    Solution s1;
    bool resu = s1.oneEditAway(first,second);
    cout << "resu= " << resu << endl;
    return 0;
}