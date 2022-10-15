#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int right = 0;
        int count = 0;
        int left = 0;
        while(right < s.length()){
            // 找到单词的第一个字符
            while(s[right] == ' ' && right < s.length()){
                right++;
            }
            left = right;
            if(s[right] != ' ' &&  right < s.length()){
                count++;
            } 
            while(s[right] != ' ' && right < s.length()){
                right++;
            }
            cout << "right= " << right << "count= " << count <<  endl;

        }
        return count;

    }
};

int main()
{
    Solution s1;
    string s = "  goo  hello  hh";
    int resu = s1.countSegments(s);
    cout << "main resu= " << resu << endl;
    return 0;

}