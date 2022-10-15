#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
分治思想：对于一个出现次数 大于0 小于k 的字符，则一定不包含在结果字符串里面
*/

class Solution {
public:
    int dfs(const string& s, int l, int r, int k) {
        // 记录每个字符出现的次数
        vector<int> cnt(26, 0);
        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']++;
        }
        // 找出不符合 出现次数的 字符
        char split = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        // 所有字符出现次数均 大于等于 k 
        if (split == 0) {
            return r - l + 1;
        }
        // 
                           
        int i = l;
        int ret = 0; //字符串最大长度
        while (i <= r) {
            while (i <= r && s[i] == split) {
                i++;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s[i] != split) {
                i++;
            }

            int length = dfs(s, start, i - 1, k);
            ret = max(ret, length);
        }
        return ret;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        return dfs(s, 0, n - 1, k);
    }

};

int main
{
    string s = "aababc";
    int k =2;
}