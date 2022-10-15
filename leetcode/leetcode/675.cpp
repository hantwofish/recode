#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
bool m_sort(pair<int,pair<int,int>>&A,pair<int,pair<int,int>>&B)
{
    return A.first < B.first;
}

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int row = forest.size();
        int col = forest[0].size();
        unordered_map<int,pair<int,int>> m_map;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(forest[i][j] == 0){
                    continue;
                }
                m_map[forest[i][j]] = {i,j};
            }
        }
        // 排序
        vector<pair<int,pair<int,int>>> m_vec(m_map.begin(),m_map.end());
        sort(m_vec.begin(),m_vec.end(),m_sort);

        m_print(m_vec);

        // BFS 
        pair<int,int>start ={0,0};
        int sum = distance(forest,start,m_vec[0].second); // 从(0,0)出发到到第一个位置
        cout << "m_vec.size()= " << m_vec.size() << endl;
        for(int i =0; i < m_vec.size()-1; i++){
            sum += distance(forest,m_vec[i].second, m_vec[i+1].second);
        }

        //
        return sum;

    }
private:
    int distance(vector<vector<int>>& forest, pair<int,int>&Src , pair<int, int >&Target){
        if(Src.first == 0 && Src.second == 0){
            

        }




    }




    void m_print(vector<pair<int,pair<int,int>>>& m_vec)
    {
        for(auto i = m_vec.begin(); i != m_vec.end() ; i++){
            cout << " " << (*i).first << " " << (*i).second.first << " " << (*i).second.second ;
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>>forest= {{1,2,3},{0,0,4},{7,6,5}};
    int resu = s1.cutOffTree(forest);
    cout << "resu= " << resu << endl;
    return 0;
}