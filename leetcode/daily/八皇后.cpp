#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void myprint( vector<vector<string>> &resu)
{
    for(int i=0; i < resu.size();i++)
    {
        for(int j= 0; j< resu[i].size(); j++)
        {
            cout << resu[i][j] << " ";
        }
        cout <<endl;
    }


}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        string init="";
        for(int i= 0 ; i< n; i++)
            init += ".";
        vector<string> mid(n,init); // 一种解法
        backtracing(n,mid,0);
        return resu;

    }
    void backtracing( int n  ,vector<string> &mid , int row ) // 第 row 行
    {
        if(row == n)
        {
            resu.push_back(mid);
            return;
        }
        for(int i = 0 ; i< n ; i++) // 对当前行的列开始放置
        {
            if(!isValid(n,mid,row,i))
                continue;
            mid[row][i] = 'Q';
            backtracing(n , mid , row+1) ;
            mid[row][i] = '.';
        
        }


    }
    bool isValid( int n  ,vector<string> &board , int row, int col   ) // 当前位置可以放置 皇后
    {
            for (int i = 0; i < n; i++) // 列是否冲突
            {
                if (board[i][col] == 'Q')
                    return false;
            }
            // 检查右上方是否有皇后互相冲突
            for (int i = row - 1, j = col + 1;  i >= 0 && j < n; i--, j++) 
            {
                if (board[i][j] == 'Q')
                    return false;
            }
            // 检查左上方是否有皇后互相冲突
            for (int i = row - 1, j = col - 1;
                    i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q')
                    return false;
            }
            return true;
    }

private:
    vector<vector<string>> resu; // 全部解法
    
};


int main()
{
    Solution s1;
    int n = 4;
    vector<vector<string>> resu = s1.solveNQueens(n);
  
    myprint(resu);
    return 0;
}