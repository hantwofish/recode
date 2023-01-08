#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        PrintVec(board);
        int rowMaxIndex = board.size() -1;
        int colMaxIndex = board[0].size()-1;
        for(int row = 0; row < board.size(); row++){
            for(int col = 0 ; col < board[0].size(); col++){
                //cout << "row= " << row << " col= " << col << endl;
               if(row ==0 || row == rowMaxIndex || col == 0 || col ==colMaxIndex){
                    if(board[row][col] == 'O'){
                        // 进行DFS修改
                       DFs(row,col,board);
                    }
               }
            }
        }

        cout << "++" << endl;
        PrintVec(board);
        cout << "++" << endl;
        ModiFY(board);
        PrintVec(board);

    }
    void ModiFY(vector<vector<char>>& board) 
    {
        cout << "***" << endl;
        // int rowMaxIndex = board.size() -1;
        // int colMaxIndex = board[0].size()-1;
        for(int row = 0; row < board.size(); row++){
            for(int col = 0 ; col < board[0].size(); col++){
                if(board[row][col] == 'A'){
                    board[row][col] = 'O';
                }else  if(board[row][col] == 'O'){
                    board[row][col] = 'X';
                }

            }
        }
    }
    void DFs(int row, int col, vector<vector<char>>& board)
    {
        //cout << "Dfs" << endl;
        if(row <0 || row >= board.size() || col <0 || col >= board[0].size()){
            return;
        }
        if( board[row][col] != 'O'){
            return;
        }
        board[row][col] = 'A';
        // int rowMaxIndex = board.size() -1;
        // int colMaxIndex = board[0].size()-1;
        // 对四个方向进行搜素
        for(int i = 0; i< 4; i++){
            int x = row + direct[i][0];
            int y = col + direct[i][1];
            //cout << "x= " << x << " y= " << y << endl;
            // if(board[x][y] == 'O'){
            //     board[x][y] = 'A';
            // }
            DFs(x,y,board);
        }
    }
    // void ModifyArray(int row, int col, vector<vector<int>>& board)
    // {
    //     int rowMaxIndex = board.size() -1;
    //     int colMaxIndex = board[0].size()-1;
    //     // 对四个方向进行搜素
    //     for(int i = 0; i< 4; i++){
    //         int x = row + direct[i][0];
    //         int y = col + direct[i][1];
    //         if(x == 0 || x == rowMaxIndex || y == 0 || y == colMaxIndex){
    //             continue;
    //         }
    //     }
    // }
public:
    int direct[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    void PrintVec(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    Solution s1;
    vector<vector<char>>board= {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
        };   

    s1.solve(board);
    return 0;
}