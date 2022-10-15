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
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int result =0;
        int row = dungeon.size();
        int cal = dungeon[0].size();
        vector<vector<int>>dp(row+1,vector<int>(cal+1,INT_MAX));
        for (int i = row-1; i >=0; i--)
        {   
            for(int j = cal-1; j>=0; j--)
            {
                int data= min(dp[i+1][j],dp[i][j+1]  );
                if(data - dungeon[i][j] < 0 )
                    dp[i][j] = 1;
                else
                    dp[i][j] = data - dungeon[i][j];
            }
           
        }
        

        return dp[0][0];
    }
};


int main()
{


    return 0;
}