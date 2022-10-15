#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char ,int> need ,windows;
        for(char a : s1)
            need[a]++;
        int left = 0;
        int right = 0;
        int valid = 0;
        while( right < s2.size() )
        {
            char c= s2[right];
            right++;
            if( need.count(c) )
            {
                windows[c]++;
                if(need[c] == windows[c])
                    valid++;
            }

            // 窗口收缩
            while( right - left >= s1.size() )
            {
                if(valid == need.size())
                    return true;
                char d = s2[left];
                left ++;
                if(need.count(d))
                {
                    if(need[d] == windows[d])
                        valid--;
                    windows[d]--;
                }
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    string s1 = "ab";
    string s2 = "eidboaooo";
    bool re = s.checkInclusion(s1,s2);
    cout << "res=   " << re <<endl; 
    return 0;
}