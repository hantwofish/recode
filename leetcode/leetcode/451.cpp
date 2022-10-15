#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<vector>


using namespace std;
bool compare(pair<char, int>&s1, pair<char, int>&s2)
{
    if(s1.second == s2.second){
        return s1.first > s2.first;
    }
    else
    {
        return s1.second > s2.second;
    }
    
}

class Solution {
public:

    string frequencySort(string s) {
        int lenth = s.length();
        unordered_map<char ,int > m_map;
        for(int i = 0; i < lenth; i++){
            m_map[s[i]]++;
        }

        // vector<pair<char, int>> m_vec (m_map.begin(),m_map.end());
        vector<pair<char, int>> m_vec;
        unordered_map<char ,int >::iterator it = m_map.begin();
        for(int i =0 ; i < m_map.size(); i++){
            /*
            pair<char,int> a ;
            a.first =  (*it).first ;
            a.second = (*it).second;
            m_vec.push_back( a );
            it++;
            */
           m_vec.push_back( pair<char,int>(it->first,it->second) );
           it++;

        }
        
        sort(m_vec.begin(), m_vec.end(),compare);
        string resu;
        for(int i = 0; i < m_vec.size(); i++){
            for(int j = 0 ; j < m_vec[i].second;j++){
                resu += m_vec[i].first;
            }
            
        }
        return resu;

    }
    
};

int main()
{
    string s = "tree";
    Solution s1;
    string resu = s1.frequencySort(s);
    cout << "main resu= "<< resu << endl;
    return 0;
}