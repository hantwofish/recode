#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n >= 0 && n <= 3){
            if(n == 1){
                return 0;
            }
            return n;
        }
        vector<int>dp(n+1, 0);
        for(int i = 1; i <= n ; i++){
            if( i== 1){
                dp[i] = 0;
                continue;
            }
            if(i >1 &&i <= 3){
                dp[i] = i;
                continue;
            }
            int tep_min = INT32_MAX;
            for(int j = 1 ; j < i ; j++){
                if( i % j == 0){
                    tep_min = min(tep_min , dp[j] + 1 + (i-j)/j); // 1 次复制，加上 (i-j)/j 的粘贴
                }
            }
            dp[i] = tep_min ;
        }       
        for(int i =0 ; i < dp.size(); i++){
            //cout << " " << dp[i];
        }
        //cout << endl;
        return dp[n];
    }
};

int main()
{
    int n =8;
    Solution s1;
    int resu = s1.minSteps(n);
    cout << "main resu= " << resu << endl;
    return 0;
}