#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int Lremove = 0; //需要删除 左括号的 个数
        int Rremove = 0; //需要删除 右括号的 个数
        for(int i= 0; i < s.length(); i++){
            if(s[i] == '('){
                Lremove++;
            }else if(s[i] == ')'){
                if(Lremove == 0){
                    Rremove++;
                }else{
                    Lremove--;
                }
            }
        }

        DFS(s, 0, Lremove, Rremove);
        vector<string>result(resu.begin(),resu.end());
        return result;
    }
private:
    // 回溯
    // DFS(str, 开始索引，剩余左括号个数，剩余右括号个数)
    void DFS(string str, int start_index, int Lleft_num ,int Rright_num)
    {
        if(Lleft_num == 0 && Rright_num == 0){
            if(isVaild(str)){
                resu.insert (str);
                return;
            }
        }
        for(int i = start_index; i < str.length() ; i++){
            // 删除左括号
            if(Lleft_num > 0 && str[i] == '(') {
                DFS(str.substr(0, i) + str.substr(i + 1, str.length() - i - 1), i, Lleft_num - 1, Rright_num);
            }
            // 删除右括号
            if(Rright_num > 0 && str[i] == ')') {
                DFS(str.substr(0, i) + str.substr(i + 1, str.length() - i - 1), i, Lleft_num, Rright_num - 1);
            }


        }
    }
    bool isVaild(string str)
    {
        stack<int> stk;
        for(int i= 0 ; i < str.length(); i++){
            if(str[i] == '(' ){
                if(stk.empty()){
                    stk.push(str[i]);
                }else if(stk.top() ==  '('){
                    stk.push(str[i]);
                }else if(stk.top() == ')'){
                    stk.push(str[i]);
                }

            }else if(str[i] == ')'){
                if(stk.empty()){
                   return false;
                }else if(stk.top() ==  '('){
                    stk.pop();
                }else if(stk.top() == ')'){
                    return false;
                }
            }
        }
        return stk.empty()? true : false;
    }

public:
    unordered_set<string>resu;
};

int main()
{
    Solution s1;
    string s = "()(())()";
    vector<string> resu = s1.removeInvalidParentheses(s);
    cout << "size= " << resu.size() << endl;
    for(auto& i : resu){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}