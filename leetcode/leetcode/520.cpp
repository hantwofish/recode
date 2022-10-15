#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() <=1){
            return true;
        }

        if( id_A(word[0]) && id_A(word[1]) ){ // 第一个字母大写 第二个大写
            for(int i = 2; i< word.length() ; i++){
                if( word[i] >= 'a' && word[i] <= 'z' )
                    return false;

            }
        }else if(id_A(word[0]) &&  ~id_A(word[1]) ){ // 第一个字母大写 第二个小写
            for(int i = 2; i< word.length() ; i++){
                if( word[i] >= 'A' && word[i] <= 'Z' )
                    return false;

            }

        }else if(~id_A(word[0]) && ~id_A(word[1])){ // 第一个小写，第二个小写
            for(int i = 2; i< word.length() ; i++){
                if( word[i] >= 'A' && word[i] <= 'Z' )
                    return false;

            }
        }
        return true;
    }
    bool id_A( char a )
    {
        if( a >= 'a' && a <= 'z' ){
            return false;
        }else if( a >= 'A' && a <= 'Z' ){
            return true;
        }


        return true;
    }
};

