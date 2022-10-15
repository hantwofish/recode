#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        if(words.size() > board.size()*board[0].size()){
            return result;
        }
        
        for(int i = 0 ; i < words.size(); i++){
            vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
            char target_char = words[i][0];
            string cur= "";
            
            for(int j = 0 ; j < board.size(); j++){
                for(int k = 0 ;  k < board[0].size(); k++){
                    if(board[j][k] == target_char){
                        cout << "i= " << i << " j= " << j << " k= " << k << endl;
                        cur = "";
                        
                        DFS(board, j, k,  cur , words[i], 0 , visited);
                    }
                }
            }
        }
        return result;
    }
    void DFS(vector<vector<char>>&board , int start_row , int start_col , 
            string& cur_str , string target, int tar_index , vector<vector<bool>>&visited )
    {
        if(cur_str == target){
            if(find(result.begin(),result.end(),target) == result.end()){ // 不存在
                result.push_back(cur_str);
            }
            
            return;
        }
        // 数组越界 return
        if(start_row <0 || start_row >= board.size() || start_col < 0 || start_col >= board[0].size()){
            return;
        }
        // 已经访问过 或者不相等
        if(visited[start_row][start_col] || board[start_row][start_col] != target[tar_index]){
            return;
        }

        visited[start_row][start_col] = true;
        if(board[start_row][start_col] == target[tar_index]){
            cur_str += board[start_row][start_col];
        }
        // 四个方向搜索
        for(int k = 0; k< 4 ; k++){
            DFS(board, start_row + dx[k] , start_col+ dy[k], cur_str , target, tar_index+1, visited);
        }
        visited[start_row][start_col] = false;


    }
private:
    vector<string> result;
    // 上下左右四个方向
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
};

int main()
{
    Solution s1;
    vector<vector<char>> board = {{'a','b','c'},{'a','e','d'},{'a','f','g'}};
    vector<string> words = {"eaafgdcba"};
    vector<string> resu = s1.findWords(board, words);
    for(auto i : resu){
        cout << " " << i << " ";
    }
    cout << endl;


}