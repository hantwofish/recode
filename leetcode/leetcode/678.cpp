#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution2 {
public:
    bool checkValidString(string s) {
        int lenth = s.length();
        stack<char> stk;
        if(s[0] == ')' || lenth == 1){
            return false;
        }
        stk.push(s[0]);
        int i = 1;
        while ( !stk.empty() && i < lenth)
        {
            int cur = s[i];
            int top = stk.top();
            if(top == '('){
                if(cur == '('){
                    stk.push(cur);
                }else if(cur == '*'){
                    stk.pop();
                }else if(cur == ')'){
                    stk.pop();
                }
            }else if(top == '*'){
                if(cur == '('){
                    stk.push(cur);
                }else if(cur == '*'){
                    stk.pop();
                }else if(cur == ')'){
                    stk.pop();
                }
            }else if(top == ')'){
                return false;
            }
            i++;
        }
        return true;
        

    }
};


class Solution {
public:
    bool checkValidString(string s) {
        int lenth = s.length();
        cout << "lenth= " << lenth << endl;

        vector<vector<bool>>dp(lenth,vector<bool>(lenth, 0)); // 定义 [i,j] 是否有效
        for(int i = 0 ; i< lenth ; i++){
            if(s[i] == '*'){
                dp[i][i] = true;
            }
        }
        // 计算相邻的两个
        for(int i = 0 ; i < lenth - 1; i++){
            string str = "";
            str += s[i];
            str += s[i+1];
            if(str == "()" || str == "*)" || str == "(*" || str == "**"){
                dp[i][i+1] = true;
            }
        }
        for(int i = lenth - 3 ; i >= 0 ; i--){
            for(int j = i + 2 ; j < lenth ; j++){
                if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' ||s[j] == '*')) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                for (int k = i; k < j && !dp[i][j]; k++) {
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }
            }
        }
        return dp[0][lenth -1];



    }
public:
    void my_print(vector<vector<bool>>&dp)
    {
        for(int i = 0 ; i< dp.size() ; i++){
            for(int j = 0 ; j < dp.size() ; j++){
                cout << " " << dp[i][j] ;
            }
            cout << endl;
        }

    }
};

int main()
{
    Solution s1;
    string str = "(*)";
    bool resu = s1.checkValidString(str);
    cout << "resu= " << resu << endl;
    return 0;

}