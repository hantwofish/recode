#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution2 {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        for(int i = 0 ; i< n; i++){
            for(int j = 0; j < n ; j++){
                for(int k = 0; k< n ; k++){
                    if( i == j || i ==k || j ==k){
                        continue;
                    }
                    if(distance(points[i] ,points[j]) == distance(points[i], points[k])){
                        resu++;
                    }
                }
            }
        }
        return resu;

    }
    int distance(vector<int>&A, vector<int>&B)
    {
        int dist = 0;
        dist = (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]);
        return dist;
    }
private:
    int resu;
};


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if( n < 3 ){
            return 0;
        }
        unordered_map<int, int> m_map; // 记录距离和数量
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if( i == j ){
                    continue;
                }
                m_map[distance(points[i],points[j])];
            }
            for(auto i = m_map.begin(); i != m_map.end(); i++){
                int num = i->second;
                resu += num * (num -1);
            }
            m_map.clear();
            
        }
        return resu;


    }
    int distance(vector<int>&A, vector<int>&B)
    {
        int dist = 0;
        dist = (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]);
        return dist;
    }
private:
    int resu = 0;
};