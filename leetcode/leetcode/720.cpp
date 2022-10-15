#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_set<string> set;
        for(int i = 0 ; i < words.size() ; i++){
            if(words[i].length() == 1){
                set.insert(words[i]);
            }else{
                if(find(set.begin(),set.end(), words[i].substr(0,words[i].length()-1)) != set.end()){ // find
                    set.insert(words[i]);
                    resu = resu.length() >= words[i].length() ? resu : words[i];
                }
            }
        }

        return resu;

    }
private:
    string resu ="";
};

int main()
{
    Solution s1;
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    string resu = s1.longestWord(words);
    cout << "resu= " << resu << endl;
    return 0;
}