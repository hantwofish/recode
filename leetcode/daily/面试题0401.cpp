#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> grap_data(n,vector<int>(n,0));
        vector<bool>visited(n,false);
        bool resu = false;
        for(int i = 0 ; i < n ; i++){                      
            grap_data[ graph[i][0] ] [ graph[i][1] ] = 1;
            grap_data[i][i] = 1;
        }
        DFS(grap_data, start , target, resu ,visited);
        return resu;

    }
    void DFS(vector<vector<int>>& grap_data , int start , int end , bool& resu  , vector<bool>&visited)
    {
        cout << "start= " << start << " end= "<< end << endl;
        if(start == end){
            resu = true;
            return;
        }
        if(visited[start]){
            return;
        }
        for(int i = start +1 ; i < grap_data.size() ; i++){
            if(grap_data[start][i] != 1){ // 未连通
                continue;
            }
            visited[i] = true;
            DFS(grap_data, i , end, resu,visited);
            visited[i] = false;
        }

    }
};

int main()
{
    Solution s1;
    vector<vector<int>> grap = {{0, 1}, {0, 2}, {0, 4}, {0, 4}, {0, 1}, {1, 3}, {1, 4}, {1, 3}, {2, 3}, {3, 4}};
    int start = 0;
    int target = 4;
    int n = 5;
    bool resu =s1.findWhetherExistsPath(5 , grap , start , target);
    cout << "resu= " << resu << endl;


    return 0;
}