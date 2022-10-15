#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size_len = s.length();
        vector<bool>dp(size_len,0);
        if(find(wordDict.begin(),wordDict.end() , s.substr(0,1))    != wordDict.end())    
            dp[0] = 1;
        else 
            dp[0] =0;


        for(int i = 1; i <= size_len-1; i++)
        {
            bool check = false;
            for(int j = 0; j <= i ; j++)
            {
                cout << "sunstr= " << s.substr(j+1,i-j) <<endl;
                if( dp[j] && 
                    ( find(wordDict.begin(),wordDict.end() , s.substr(j+1,i-j))    != wordDict.end())   )
                {
                    dp[i]=true;
                    break;
                    
                }
                    
            }
            cout << "i= " << i <<" " << dp[i] << endl;
            
        }
        return dp[size_len];
  
  
  
  
    }
};


int main()
{
    vector<string> nums={ "le","et", "code" };
    string s= "leetcode";
    Solution s1;
    bool resu= s1.wordBreak(s,nums);
    cout <<"resu= " << resu << endl;
    return 0;
}