#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int cal(int n )
{
    if(n == 0 || n ==1){
        return 1;
    }
    vector<int>dp(n+1, 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1 ; i <= n ; i++){
        int mid = 0;
        for(int j = 1 ; j <= i ; j++){
            mid += dp[j-1]*dp[i-j];
        } 
        dp[i] =  mid;
    }
    return dp[n];

}
int cal2(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1,1));
    // 边界初始化
    for(int i = n ; i >= 1 ; i--){
        for(int j = i-1 ;  j <= n ; j++){
            int mid = 0;
            if( i > j ){
               continue;
            }
            
            for(int k = i ; k <= j ; k++){
                int mid1 = k-1 < i ? 1 : dp[i][k-1];
                int mid2 = k+1 > j ? 1 : dp[k+1][j];
                mid += mid1 * mid2;
            }
            dp[i][j] = mid > 0 ? mid : 1;
           // cout << "dp["<< i << "]["<< j << "]= "<< dp[i][j] << endl;
        }
    }

    return dp[1][n];
}

int main()
{
    int n  = 0;
    while(n < 19){
        cout << "n= " << n << " " << cal(n) << " " << cal2(n) << (cal(n) == cal2(n) ? "yes" : "no") << endl;
        n++;
    }

    return 0;
}