#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pri_size = prices.size(); 
        int max_k = 2;
        int dp[pri_size][max_k][2] ={0,0,0};
        for(int i = 0 ; i < pri_size ; i++)
        {
            for(int k = max_k; k >= 1 ; k--)
            {
                if(i==0)
                {
                    dp[0][k][0] = 0 ; // 第0 天 手里没有股票
                    dp[0][k][1] = -prices[i]; // 买入股票
                }
                else
                {
                    dp[i][k][0] = max( dp[i-1][k][ 0] , dp[i-1][k][1] + prices[i] );
                    dp[i][k][1] = max( dp[i-1][k][1] , dp[i-1][k-1][0] - prices[i] );

                }
           
            }
 //cout << "i= " << i << "  dp[][0]= " << dp[i][0] << " dp[i][1]= " << dp[i][1] << endl;
        }
        
        for(int i=0 ; i< pri_size ; i++)
            for( )
        res = dp[pri_size -1 ][0][0];



        return res;
    }
private:
    int res;
};


int main()
{
    Solution s1;
    vector<int>prices = {7,1,5,3,6,4};
    int res = s1.maxProfit(prices);

    cout <<  "res = " << res << endl;
    return 0;
}
