#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int cal(int N, int M)
{
    if(N <=3){
        if(N == 1){
            return 1 % M;
        }else if(N == 2){
            return 1 % M;
        }else if(N == 3){
            return 2 % M;
        }
    }
    vector<long long>dp(N+1,0);
    vector<bool>visited(N+1,0);
    dp[1] = 1;
    dp[2] = 1 ;
    dp[3] = 2;
    for(int i = 4 ; i <= N  ;i++){
        if(visited[i] == true){
            dp[i] = dp[i-1] + dp[i-2];
        }else if(visited[i] == false){
            dp[i] = dp[i-1] + dp[i-2] + 1;

        }
    }
    return dp[N]% M;
}

int main()
{
    int N = 5;
    int M = 10;
    cin >> N >> M;
    long resu = cal(N,M);
    cout << resu << endl;
    return 0;
}