#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string result = "";
        if(num == 0){
            return "0";
        }
        for(int i = 7 ; i>=0 ; i--){
            int cur = (num >> (4* i)) & 0xf;
            if( result.length() > 0 || cur > 0){
                char digit = cur < 10 ? (char) ('0' + cur) : (char) ('a' + cur - 10);
                result += digit;
            }
        }

        return result;
    }

};

int main()
{
    Solution s1;
    int num  = 123;
    string resu = s1.toHex(num);
    cout << "main resu= " << resu << endl;
    return 0;
}