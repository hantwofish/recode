#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        unordered_map<char,int> m_data;

        // 两个字符串相等时，有重复字符则为真
        if( s == goal){
            for(int i =0 ; i < s.length() ; i++){
                m_data[s[i]]++;

            }
            for(auto it = m_data.begin() ; it != m_data.end(); it++){
                if(it ->second >= 2) {
                    return true;
                }
            }
            return false;
        }
       
       // 当两个字符串不相等时
        vector<char>data;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != goal[i]){
                data.push_back(s[i]);
                data.push_back(goal[i]);
            }
        }
        if(data.size() != 4 ){
            return false;
        }
        if( (data[0]==data[3]) && (data[1] == data[2]) ){
            return true;
        }
        return false;
    }
};