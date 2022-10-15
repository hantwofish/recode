#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int lenth = s.length();
        vector<vector<int>>dp(lenth,vector<int>(lenth,0));
        for(int i = 0 ; i < lenth ; i++){
            dp[i][i] = 1;
        }

        for(int i = lenth -2  ; i >=0 ; i-- ){
            for(int j = i + 1; j < lenth ; j++){
                if( s[i] == s[j]){
                    if(j - i == 1){
                        dp[i][j] = 2;
                    }else{
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }else if(s[i] != s[j]){
                    if(j - i == 1){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j]= max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }


        return dp[0][lenth -1];
    }
};
int main()
{
    Solution s1;
    string s = "bbbab";
    int resu = s1.longestPalindromeSubseq(s);
    cout << "resu= " << resu << endl;
    return 0;
}