#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int s_lenth = s.length();
        int i = 0;
        for(i = 0 ; i< s_lenth ; i++){
            if(s[i]== 'E'|| s[i] == 'e'){
                break;
            }
            
        }
        string s_left = s.substr(0,i);
        string s_right = s.substr(i+1, s.length()-1 - (i+1)+1);
        cout << "left= " << s_left << " right= " << s_right << endl;
        if(check_int(s_right) && (check_int(s_left) || check_float(s_right))){
            return true;
        }


        return false;

    }
    bool check_int(string str)
    {
        for(int i = 0 ; i < str.length() ; i++){
            if(i== 0 && (str[i] == '+' || str[i] == '-')){
                continue;
            }
            if( '0' <= str[i] && str[i] <= '9'){
                continue;
            }else {
                return false;
            }
            
        }
        return true;
    }
    bool check_float(string str)
    {
        int i = 0;
        for( i = 0; i < str.length(); i++){
            if(str[i] == '.'){
                break;
            }
        }

        if( i== 0 && check_int(str.substr(i, str.length()-1))){
            return true;
        }else if(i == str.length()-1  && check_int(str.substr(0, str.length()-1)) ) {
            return true;
        }else if(  (i > 0 && i < str.length()) &&  (check_int(str.substr(0,i))) && check_int(str.substr(i+1, str.length()-1-(i+1)+1))    ){
            return true;
        }
        return false;
    }

};

int main()
{
    Solution s1;
    string s = ".1";
   // cout << s1.check_int("+10") << endl;
    cout << (s1.isNumber(s) ? "ok": "no") << endl;
    return 0;

}