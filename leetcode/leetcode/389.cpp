#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int data[26] = {0};
        for(int i = 0 ; i < s.length(); i++){
           data[ s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            data[ t[i] - 'a']--;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(data[i]  < 0){
                return (char)(i+'a');
            }
        }
        return ' ';

    }
};

int main()
{
    Solution s1;
    string s ="abcd";
    string t = "abcde";
    cout << "resu= " << s1.findTheDifference(s,t) << endl;
    return 0;
}