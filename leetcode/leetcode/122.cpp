
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/* 动态规划
dp[] 当前买入状态或者无股票状态下的最大利润
dp[i][j][k]: 天数，当天允许交易的最大次数，当前持有的状态(1:表示持有，0表示未持有)

*/
class Solution { // 动态规划，状态转移进行解决 K= 正无穷
public:
    int maxProfit(vector<int>& prices) {
        int pri_size = prices.size();  //
        int dp[pri_size][2] ;// 在第 i 天，有无股票的状态下，获取的最大利润；
        for(int i = 0 ; i < pri_size ; i++)
        {
            if(i == 0 )
            {
                dp[0][0] = 0; //第 0 天,没有买入，则利润为 0；
                dp[0][1] = -prices[i] ; // 第 0 天，买入了股票，则利润为 - prices[i];
                cout << "i= " << i << " " << dp[i][0] << "  " << dp[i][1] << endl;

                continue;
            }
            dp[i][0] = max( dp[i-1][0] , dp[i-1][1] + prices[i]   ); // i-1天没有股票， i-1天有股票，第i天 卖出
            dp[i][1] = max( dp[i-1][1] ,   dp[i-1][0] - prices[i] );  // i-1天有股票， i-1天没有股票，第i天买入
            cout << "i= " << i << " " << dp[i][0] << "  " << dp[i][1] << endl;
        
        }
        
        res = dp[pri_size -1 ][0];
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