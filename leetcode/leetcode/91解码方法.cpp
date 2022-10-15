#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int s_len  = s.length();
        vector<int>dp(s_len , 0);
        if(s_len <=0 || s[0] == '0'){
            return 0;
        }
        if( s[0] >= '1' && s[0] <= '9'  ){
            dp[0] = 1;
        }
        for(int i =1 ; i < s_len ; i++){
            // 分两种情况，一种单组放在后面，一种和上一个字母组合
            int case_one = 0;
            int case_two = 0;
            if(s[i] == '0'){
                case_one  = 0;
            }else{
                case_one = dp[i-1];
            }
            string str_sub = s.substr(i-1,2);
            if(stoi(str_sub) > 26 || str_sub[0] == '0'){
                case_two = 0;
            }else {
                if(i==1){
                    case_two = 1;
                }else{
                    case_two = dp[i-2];
                }
                
            }
            dp[i] = case_one + case_two;
        }
        for(int i = 0 ; i < s_len ; i++){
            cout << "i= " <<  i << " " << dp[i] << endl; 
        }


        return dp[s_len-1];
    }
private:
    int result = 0;
};

int main()
{
    Solution s1;
    string str = "2101";
    int result = s1.numDecodings(str);
    cout << "main result= " << result << endl;
    return 0;
}