#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include"tree.h"
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()){
            return 0;
        }


        vector<bool>isVisited(wordList.size(),0);
        queue<string> que;

        que.push(beginWord);
        //isVisited.insert(beginWord);

        int resu = 1;
        while (!que.empty()){

            int que_size =que.size();
            
            for(int i =0 ; i< que_size ; i++){
                string top_ele = que.front();
                que.pop();
                for(int j = 0 ; j <  wordList.size(); j++){
                    string str = wordList[j];
                    if(isVisited[j]){
                        continue;
                    }
                    if(isVaild(str, top_ele)){
                        if(str == endWord){
                            return resu+1;
                        }
                        que.push(str);
                        isVisited[j] = true;

                    }
                }
            }
            resu++;
            
        }
        

        
        return 0;
    }


public:
    bool isVaild(string str1, string str2)
    {
        if(str1.length() != str2.length()){
            return false;
        }
        if(str1 == str2){
            return false;
        }
        int diff = 0;
        for(int i = 0; i <  str1.length() ; i++){
            if(str1[i] != str2[i]){
                if(diff == 0){
                    diff++;
                }else{
                    return false;
                }
            }
        }
      
        return true;
        
    }
};

int main()
{
    Solution s1;
    string beginWord = "hit"; 
    string endWord = "log"; 
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    int resu = s1.ladderLength(beginWord,endWord,wordList);
    //cout << s1.isVaild("hit","hii")<< endl;
    cout << "main resu= " << resu << endl;
    return 0;


}