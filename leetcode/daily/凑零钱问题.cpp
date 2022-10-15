#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 动态规划 //尚未测试
class Solution2 
{
public: 
    int coinChange(vector<int>&coins, int amount)
    {   
       // vector<int> dp(amount+1,0); // dp[amount] 表示 当金额为 amount 时，所需要的最少金币数
        if( amount == 0 ) return 0;
        if( amount < 0) return -1;

        return dp(coins,amount);

    }
    int dp( vector<int>&coins , int amount )
    {
        if( amount < 0  ) return -1;
        if( amount == 0) return 0;
        int res= INT_MAX;

        for(int i= 0 ; i< coins.size(); i++)
        {
            int subproblem = dp(coins,amount - coins[i]);
            if(subproblem == -1) continue;
            res = min(res , subproblem +1);
  //          cout << "amount = " << amount << " " << "subproblem= " <<subproblem <<endl;
        }
        
    
        if( res != INT_MAX )
            return res;
        else
            return -1;
    }

public:
   // int res = INT_MAX;


};

/** 层序遍历 */ /// 尚未测试
class Solution
{
public: 
    int coinChange(vector<int>&coins, int amount)
    {
        if(amount == 0) return 0;
        if(amount < 0 ) return -1;
        return BFS(coins,amount , 0);
    }
    int BFS( vector<int>&coins , int amount , int target )
    {
        queue<int> my_que;
        int step = 0;
        my_que.push(amount);

        while( !my_que.empty() )
        {
            int qu_size = my_que.size();
            for(int i = 0 ; i< qu_size ; i++)
            {
                int top_ele = my_que.front();
                my_que.pop();

                if( top_ele == target )
                    return step;
                for(int j = 0 ; j < coins.size(); j++)
                {
                    my_que.push(top_ele - coins[j]);
                }
                
            }
            step++;



        }
        return step;
    }
};

int main()
{
    //cout << "hello " << endl;
    Solution s1;
    vector<int> coins = {1,2,5};
    int amount = 11;
    int resu = s1.coinChange(coins,amount);
    cout << "resu = " << resu << endl;

    return 0;
}