#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if(s.length() < 10){
            return resu;
        }
        unordered_map<string, int> m_map;
        for(int i = 0; i <= s.length()-10 ;i++){
            m_map[s.substr(i,10)]++;
        }
        unordered_map<string, int>::iterator it = m_map.begin();
        while(it != m_map.end()){
            if(it->second > 1){
                resu.push_back(it->first);
            }
            it++;
        }
        return resu;


    }
public:
    vector<string> resu;
};

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution s1;
    vector<string> resu = s1.findRepeatedDnaSequences(s);
    for (string str : resu)
    {
        cout << str << " ";
    }
    return 0;
    

}