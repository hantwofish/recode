#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int resu = BFS(maze,entrance);
        return resu;
    }
    int BFS(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int row = maze.size();
        int col = maze[0].size();
        queue<pair<int,int>> m_que;
        vector<vector<bool>> visited(row,vector<bool>(col, false));
      
        m_que.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int step = 0;
        //cout << "))))" <<endl;
        while( !m_que.empty()){
            int qu_Size = m_que.size();
            //cout << "qusize= " << qu_Size << endl ;
            for(int i = 0 ; i< qu_Size ; i++){
                pair<int , int> cur = m_que.front();
                m_que.pop();
                cout << "cur_first= " << cur.first << " " << cur.second << endl;
                if( (cur.first == 0 || cur.first == row -1 || cur.second == 0 || cur.second == col -1 ) &&
                      (cur.first != entrance[0] || cur.second != entrance[1] )  ){// 到达目标值
                    
                    return step;
                } 
                // 将相邻的节点加入队列
                for(int k =0 ; k < 4 ; k++){ // 将上下左右位置加入
                    int cur_x = cur.first + dx[k];
                    int cur_y = cur.second + dy[k];
                    cout <<"k= " << k <<  " cur_x= " << cur_x << " cur_y= " << cur_y << endl;
                    if(cur_x < 0 || cur_x >= row || cur_y < 0  || cur_y >= col){
                        continue;
                    }
                    if(  !visited[cur_x][cur_y] && maze[cur_x][cur_y] =='.'  ){
                        m_que.push({cur_x, cur_y});
                        visited[cur_x][cur_y] = true;
                        cout << "****" << endl;
                    }
                }

            }
            step++;
            //cout << "step= " << step << endl;
        }
        return -1;

    }
private:
    int times = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
};

int main()
{
    vector<vector<char>>maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int>entrance = {1,0};
    Solution s1;
    int resu = s1.nearestExit(maze,entrance);
    cout << "main resu= " << resu << endl;
    return 0;
}