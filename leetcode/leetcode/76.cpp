#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char , int > need, windows;
        // need 记录 T 中每个字符出现的 次数
        // windows 记录 窗口中 T 中字符出现的次数
        for(int i= 0 ; i< t.length(); i++)
        {   
            need[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0 , len = INT_MAX;//记录子串起始位置和子串长度
        while(right < s.length())
        {
            char c = s[right];
            right ++;
            if( need.count(c )     )
            {
                windows[c]++;
                if( windows[c] ==  need[c] )
                    valid++;
            }
            // 窗口中字符串包含了T所有的字符，进行 优化 收缩
            while( valid == need.size() )
            {
                if(right-left <len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left ++;
                if(need.count(d))
                {
                    if(windows[d] == need[d])
                        valid--;
                    windows[d]--;
                }
            }

        }
        // 返回 子串
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};

int main()
{
    Solution s1;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string resu = s1.minWindow(s,t);
    cout << "resu= " << resu << endl; 


    return 0;
}