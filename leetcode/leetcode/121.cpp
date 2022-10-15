#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution2 { // o(n^2)
public:
    int maxProfit(vector<int>& prices) { // 固定买入时机，遍历，卖出时间
        int pri_size = prices.size();
        for(int i = 0 ; i < pri_size -1  ; i++)
            for(int j = i+ 1 ; j < pri_size ; j++)
            {
                cout << prices[i] <<  " " << prices[j] << endl;
                res = max(res,prices[j] - prices[i]);
            }
        
        return res;
    }
private:
    int res;
};
class Solution3 { // o(n)
public:
    int maxProfit(vector<int>& prices) {
        int pri_size = prices.size();  // 固定卖出时间，寻求买入时候的最小值
        int pre_min = prices[0];
        for(int i = 1 ; i < pri_size ; i++) // 卖出时间
        {
            pre_min = min(pre_min,prices[i-1]);
            res =max(res, prices[i] - pre_min);

        }
        
        
        return res;
    }
private:
    int res;
};

class Solution { // 动态规划，状态转移进行解决
public:
    int maxProfit(vector<int>& prices) {
        int pri_size = prices.size();  
        int dp[pri_size][2] = {0};// 在第 i 天，有无股票的状态下，获取的最大利润；
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
            dp[i][1] = max( dp[i-1][1] ,  - prices[i] );  // i-1天有股票， 前面所有天均未买入，第i天买入
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