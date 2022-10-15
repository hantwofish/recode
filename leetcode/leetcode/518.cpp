#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N  = coins.size();
        vector<vector<int>>dp( N+1 ,vector<int>(amount+1 , 0) );
        // base case
        for(int i = 0; i <= N ;i++)
            dp[i][0]= 1;

        for(int  i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= amount ; j++)\
            {
                // 当前 硬币 值 为 coins[i-1];
                if(j < coins[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];  // 不选择 与 选择 两种情况
            }

        return dp[N][amount];
    }
};

int main()
{
    int amount = 5;
    vector<int>coins = {1,2,5};
    Solution s1;
    int resu = s1.change(amount , coins);
    cout << "main resu= " << resu << endl;
    return 0;
}