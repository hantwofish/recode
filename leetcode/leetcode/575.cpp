#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int N = candyType.size();
        unordered_map<int,int> m_map;
        for(auto& i: candyType){
            m_map[i]++;
        }
        return (N/2)>(m_map.size()) ? m_map.size() : N/2;

        

    }
};