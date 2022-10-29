#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        unordered_map<char,int> mapChar;
        for(auto i: allowed){
            mapChar[i]++;
        }
        for(int i = 0; i < words.size(); i++){
            if(isVaild( mapChar, words[i])){
                cout << "str= " << words[i] << endl;
                result++;
            }
           
        }
        return result;
    }
    bool isVaild(unordered_map<char,int>& mapChar, string str)
    {
        for(int j = 0; j< str.size(); j++){
               // cout << " j= " << j << "  " << str[j] << endl;
                if(mapChar[str[j]] == 0){
                    return false;
                }
        }
        return true;

    }
};

int main()
{
    Solution s1;
    string allowed = "cad";
    vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
    int resu = s1.countConsistentStrings(allowed,words);
    cout << "main::result = " << resu << endl;
    return 0;
}