#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int result =INT32_MIN;
        vector<vector<int>>resu(grid.size(),vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    continue;
                }
                DFS(grid, i, j, i ,j ,resu);

            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                result = max(result , resu[i][j]);

            }
        }
        
        

        return result;
    }
    // 从 [start_row , start_col ]开始搜索
    void DFS(vector<vector<int>>& grid , int start_row , int start_col , int i , int j  , vector<vector<int>>&resu)
    {
        int row = grid.size();
        int col = grid[0].size();
        if(start_row < 0 || start_row >= row || start_col < 0 || start_col >= col){
            return ;
        }
        if(grid[start_row ][start_col ] == 0){
            return;
        }
        if( grid[start_row][start_col] == 1){
            grid[start_row][start_col] = 0;
            pair<int, int> A = {i,j};
            resu[i][j]++;
            
        }
        // 上下左右四个方向进行遍历
        for(int k = 0 ; k< 4 ; k++){
            int cur_row  = start_row + dx[k];
            int cur_col  = start_col + dy[k];
            DFS(grid, cur_row , cur_col, i , j , resu);
        }


    }

private:
    int number = 0;
    int dx[4] = {-1 ,1 ,0 ,0};
    int dy[4] = {0, 0 , -1, 1};
    //unordered_map< vector<int> , int> m_map;
    
};

int main()
{
    Solution s1;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int resu = s1.maxAreaOfIsland(grid);
    cout << "main resu= " << resu << endl;



    
    return 0;
}