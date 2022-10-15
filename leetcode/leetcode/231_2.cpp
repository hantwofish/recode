#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n== 1 || n == 2){
            return true;
        }else if(n <= 0){
            return false;
        }
        while( n >= 0 && n % 2== 0 ){
            if(n % 2 == 0){
                n = n /2;
            }else{
                return false;
            }
        }
        if(n == 1){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s1;
    int n = 16;
    if(s1.isPowerOfTwo(n)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;

}