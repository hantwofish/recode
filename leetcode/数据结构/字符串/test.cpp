#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

namespace std{
    int find_substr_index(string S, string T)
    {
        int T_len = T.length();
        int i = 0 ; 
        int j = 0;
        while(i < S.length() && j < T.length()){
            if( S[i] == T[j]  ){
                i++;
                j++;
                
            }else{
                // 不相等
                i = i - j + 1;
                j  = 0;
            }
        }
        cout << "j= " << j << endl;
        return ( (j >= T.length()) ? (i-T.length()) : -1 );
    }

};

int main()
{
    std:: string S= "abcdefgh";
    std:: string T = "fgh"; 
    int index = std::find_substr_index(S,T);
    std::cout << "index= " << index << std::endl;
    return 0;
}
