#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size(); // 行
        int N = board[0].size(); // 列
        if(M == 0){
            return;
        }
        // 从 边界开始
        for(int i = 0 ; i < M; i++){
            DFS(board,i,0);
            DFS(board,i, N-1);
        }
        for(int i =1 ; i< N -1; i++){
            DFS(board,0,i);
            DFS(board, M-1, i);
        }

        for(int i = 0 ; i < M ; i++ ){
            for(int j = 0 ; j < N; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                
            }
        }


    }
    // 从 [row, col] 开始深度遍历
    void DFS(vector<vector<char>>& board,int row ,int col) 
    {
        if(row <= 0 || row >=  board.size() || col <= 0 || col >= board[0].size() || board[row][col] != 'O' ){
            return;
        }
        // 所有与边界连通的都标记为 "A"
        board[row][col] = 'A';
        // 上下左右四个方向进行
        for(int i = 0 ; i < 4 ; i++){
            int x = dx[i];
            int y = dy[i];
            DFS(board,row + x,col + y);
        }

    }
private:
    int dx[4] ={0,0,-1,1};
    int dy[4] ={1,-1,0,0};

};

int main()
{
    Solution s1;
    vector<vector<char>>board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s1.solve(board);
    for(int i = 0 ; i < board.size();i++){
        for(int j = 0 ; j < board[i].size(); j++ ){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


}