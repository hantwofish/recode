#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>m_stk;
        int left = 0;
        int right = 1;
        while(right < path.length()){
            while(right < path.length() &&path[right] != '/'){
                right++;
            }
            if(right - left == 1){
                left = right;
                right++;
                continue;
            }


            string cur = path.substr(left+1, right - left + 1 -2);
            cout << "cur= " << cur << endl;
            if(cur == "."){
                left = right;
                right++;
            }else if(cur == ".."){
                if(!m_stk.empty()){
                    m_stk.pop();
                }
                left = right;
                right++;
            }else {
                m_stk.push(cur);
                left = right;
                right ++;
            }
        }


        string output = "";
        while(!m_stk.empty()){
            output = "/"+m_stk.top() + output;
            m_stk.pop();
        }
        if(output == ""){
            return "/";
        }
        return output;
    }
};

int main()
{
    Solution s1;
    string path = "/../";
    string resu = s1.simplifyPath(path);
    cout << "main resu=" << resu << endl;
    return 0;
}