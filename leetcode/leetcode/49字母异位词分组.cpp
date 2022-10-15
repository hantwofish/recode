#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //vector<string> mid;
        if(strs.empty()){
            return resu;
        }
        for(int i = 0 ; i< strs.size(); i++){
            string cur_Str = strs[i];
            if(resu.empty()){
               // vector<string>mid(1,cur_Str);
                resu.push_back(vector<string>(1,cur_Str));
                continue;
            }
            int j = 0;
            for( j = 0; j < resu.size(); j++){
                if(one_class(cur_Str, resu[j][0])){
                    resu[j].push_back(cur_Str);
                    break;
                }
            }
            if(j == resu.size()){
               
                resu.push_back(vector<string>(1,cur_Str));
            }


        }


    
        return resu;
    }
    bool one_class(string str1, string str2)
    {
        if(str1.length() != str2.length()){
            return false;
        }
        unordered_map<char, int> map_1;
        unordered_map<char,int> map_2;
        for(int i = 0 ; i< str1.length(); i++){
            map_1[str1[i]]++;
            map_2[str2[i]]++;
        }
        return map_1 == map_2;


    }
   
    
public:
    vector<vector<string>>resu;
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m_map;
        for(int i = 0 ; i < strs.size() ;i++){
            string cur_str = strs[i];
            sort(cur_str.begin(),cur_str.end());
            m_map[cur_str].push_back(strs[i]);
        }
        vector<vector<string>> resu;
        auto it = m_map.begin();
        while(it != m_map.end()){
            resu.push_back(it->second);
            it++;
        }
        return resu;
    }
};

int main()
{
    Solution s1;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> resu = s1.groupAnagrams(strs);
    for(int i = 0 ; i < resu.size() ; i++){
        for(int j = 0 ; j < resu[i].size();j++){
            cout << resu[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    
}