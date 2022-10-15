#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    int n = 25;
    
}