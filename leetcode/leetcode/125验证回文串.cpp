#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0 ; i< s.length();i++){
            if( 'A' <=  s[i] && s[i] <= 'Z' ){
                str += (char)(s[i] - 'A' + 'a');
            }else if( 'a' <=  s[i] && s[i] <= 'z' ){
                str += s[i];
            }else if( '0' <=  s[i] && s[i] <= '9' ){
                str += s[i];
            }
        }
        cout << "str= " << str << endl;
        int left = 0;
        int right = str.length()-1;
        while(left <= right){
            if(str[left] != str[right]){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;


    }

};

int main()
{
    Solution s1;
    string str = "0P";
    if(s1.isPalindrome(str)){
        cout << "Yes" <<endl;
    }else {
        cout << "No" << endl;
    }
    return 0;
}