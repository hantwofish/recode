#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        if(s1.length() != s2.length()){
            return false;
        }
        unordered_map<char, int> s1_map;
        unordered_map<char, int> s2_map;
        for(int i = 0; i < s1.length() ;i++){
            s1_map[s1[i]]++;
            s2_map[s2[i]]++;
        }
        if(s1_map != s2_map){
            return false;
        }
        // 进行比较


        return compare(s1,s2);
    }  
    bool compare(string str1,string str2)
    {
        int n = str1.length();
        vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n, vector<bool>(n+1,0)));
        // 初始化单个字符串
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < n ; j++){
                dp[i][j][1] = (str1[i] == str2[j]);
            }
        }
        // 枚举区间长度 2～n
        for (int len = 2; len <= n; len++) {
            // 枚举 S 中的起点位置
            for (int i = 0; i <= n - len; i++) {
                // 枚举 T 中的起点位置
                for (int j = 0; j <= n - len; j++) {
                    // 枚举划分位置
                    for (int k = 1; k <= len - 1; k++) {
                        // 第一种情况：S1 -> T1, S2 -> T2
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                        // 第二种情况：S1 -> T2, S2 -> T1
                        // S1 起点 i，T2 起点 j + 前面那段长度 len-k ，S2 起点 i + 前面长度k
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];

    } 


};

int main()
{
    string str1 = "great";
    string str2 = "rgeat";
    Solution s1;
    bool resu = s1.isScramble(str1,str2);
    cout << "resu= " << resu << endl;

    
    return 0;
}