#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i = 0 ; i< m ; i++)
            for(int j= 0; j < n ; j++)
            {
                if(i==0  || j ==0)
                {
                    dp[i][j] += 0;
                }
                else
                    dp[i][j] += 2;
            }
        return dp[m-1][n-1];
    }
};

int main()
{


    return 0;
}