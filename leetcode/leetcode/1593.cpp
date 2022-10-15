#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {

        return 0;
    }
    void backtracing(string& str, int index)
    {
        if(index == str.length()){
            
        }
    }

private:

};
class Solution2 {
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int pos) {
        if (s.size() - pos + us.size() <= ans) 
            return;
        if (pos == s.size()) {
            ans = max(ans, (int)us.size());
            return;
        }

        string temp;
        for (int i = pos; i < s.size(); i++) {
            temp += s[i];
            if (us.find(temp) == us.end()) {
                us.insert(temp);
                dfs(s, i + 1);
                us.erase(temp);
            }
        }
    }
private:
    int ans = 0;
    unordered_set<string> us;
};


int main()
{
    Solution s1;
    string s = "ababccc";
    int resu = s1.maxUniqueSplit(s);
    cout << "main resu= " << resu << endl;
    return 0;
}