#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void myprint(vector<vector<string>> board)
{
    for(int i= 0; i< board.size(); i++)
    {
        for(int j= 0 ;j< board[i].size(); j++)
        {
             cout << board[i][j] << " " ;
        }
        cout <<endl;
    }


}


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        int size_lenth = board.size();
        backtracing(board,0,0);
    }
    // 从 i 行，j 列开始填充
    bool backtracing( vector<vector<char>>& board , int r ,int c )
    {
       // int size_len = board.size();
       // int m = 9, n = 9;
        // 终止条件
        if( c== 9 )
        {
            return backtracing(board,r+1,0);
        }
        if( r == 9   )
            return true;

        //
        for(int i= r ; i <  9 ; i++ )
        {    for(int j= c ; j< 9 ; j++)
            {
                // 
                if( board[i][j] != '.' )
                {
                   return  backtracing( board, i, j+1 );
                   
                }
                for (char ch = '1'; ch <= '9'; ch++) 
                {
                    // 如果遇到不合法的数字，就跳过
                    if (!isValid(board, i, j, ch))
                        continue;

                    board[i][j] = ch;
                    // 如果找到一个可行解，立即结束
                    if (backtracing(board, i, j + 1)) 
                    {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;

                

            }
        }
        return false;

    }
    // 判断 board[i][j] 是否可以填入 n
    bool isValid( vector<vector<char>>&board , int r, int c, char n  )
    {
        
        for(int i = 0; i <9 ; i++)
        {
            // 判断行
            if(board[r][i] == n)    return false;
            // 判断列
            if(board[i][c] == n ) return false;
            // 判断小九宫格
            if( board[(r/3)*3+ r /3][(c/3)*3+ c%3]  == n  )
                return false;

        }
        return true;
    }
};

int main()
{
    Solution S1;
    vector<vector<char>> board= 
        {
        {'5',"3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
        };

    myprint(board);
    S1.solveSudoku(board);
    myprint(board);
    return 0;
}