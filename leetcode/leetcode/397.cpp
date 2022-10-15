#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n== 1){
            return 0;
        }
        if(n==2){
            return 1;
        }   
        vector<int>dp(n+1,0);
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n ; i++){
            if(i % 2 == 0){
                dp[i] = dp[i >> 1] + 1;
            }else 
            {
                dp[i] = min(dp[i >> 1] ,  dp[(i >> 1) + 1] ) + 2;
            }
            
        }
        return dp[n];

    }
};
int main()
{
    Solution s1;
    int n = 200000000;
    cout << " " << n << endl;
    cout << " " << INT32_MAX << endl;
    int resu = s1.integerReplacement(n);
    cout << "resu= " << resu << endl;
    return 0;
}