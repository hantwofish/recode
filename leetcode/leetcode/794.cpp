#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;
/*
class Solution2 {
public:
    bool validTicTacToe(vector<string>& board) {
        unordered_map<char,int> m_map;
        char ret;
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < 3; j++){
                m_map[board[i][j]]++;
            }
        }
        cout << "*** " << is_Vaild(board,ret) << endl;
        if(m_map['X'] < m_map['O']){
            return false;
        }
        if(is_Vaild(board,ret) ){
            if(ret == 'X' && m_map['X'] > m_map['O']){
                return true;
            }else if(ret == 'O' && m_map['X'] == m_map['O']){
                return true;
            }

        }



        return false;
    }
    bool is_Vaild(vector<string>& board, char & ret)
    {
        char temp;
        // 行
        for(int i = 0 ;i < 3 ; i++){
            temp = board[i][0];
            if(board[i][1] == temp && board[i][2] == temp){
                ret = temp;
                return true;
            }
        }
        // 列
        for(int j = 0 ; j < 3; j++){
            temp = board[0][0];
            if(board[1][j] == temp && board[2][j] == temp){
                ret = temp;
                return true;
            }

        }
        // 斜
        if(board[0][0] == board[1][1] && board[0][0]== board[2][2]){
            ret = board[0][0];
            return true;
        }
        if(board[0][2] == board[1][1] && board[0][2]== board[2][1]){
            ret = board[0][2];
            return true;
        }
        return false;

    }
};
*/
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        unordered_map<char,int> m_map;
        char ret;
        int N = board.size();
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < 3; j++){
                m_map[board[i][j]]++;
            }
        }
        if(m_map['X'] == 0 && m_map['O'] ==0){
            return true;
        }
        if(m_map['X'] < m_map['O']){
            return false;
        }
        cout << "***" << is_Vaild(board,ret) << endl;
        if(is_Vaild(board,ret) ){
            if(ret == 'X' &&  m_map['X'] - m_map['O'] ==1 ){
                return true;
            }else if(ret == 'O' && m_map['X'] == m_map['O']){
                return true;
            }

        }else if(!is_Vaild(board,ret)  ){
            if (m_map['X'] == m_map['O']){
                return true;
            }else if(m_map['X'] > m_map['O'] && (m_map['X'] <= m_map['O'] +1 )) {
                return true;
            }
            
        }


        cout << "((((())))))" << endl;
        return false;
    }
    bool is_Vaild(vector<string>& board, char & ret)
    {
        char temp;
        // 行
        for(int i = 0 ;i < 3 ; i++){
            temp = board[i][0];
            if(temp != ' '&& board[i][1] == temp && board[i][2] == temp){
                ret = temp;
                return true;
            }
        }
        // 列
        for(int j = 0 ; j < 3; j++){
            temp = board[0][j];
            if(temp != ' '&& board[1][j] == temp && board[2][j] == temp){
                ret = temp;
                return true;
            }

        }
        // 斜
        temp = board[0][0];
        if(temp != ' '&& temp == board[1][1] && temp== board[2][2]){
            ret = board[0][0];
            return true;
        }
        temp = board[0][2];
        if(temp != ' '&& temp == board[1][1] && temp == board[2][0]){
            ret = board[0][2];
            return true;
        }
        return false;

    }
};

int main()
{
    Solution s1;
    vector<string> board = {"  "," X","X "};
    //board.push_back(" ");
    //cout << board.size();
    bool resu = s1.validTicTacToe(board);
    return 0;

}
