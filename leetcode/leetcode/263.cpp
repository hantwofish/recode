#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {

        while(n > 1){
            if(n % 2 == 0 ){
                n = n /2;
            }else if(n % 3 ==0 ){
                n = n /3;
            }else if(n % 5 == 0){
                n = n /5;
            }else{
                return false;
            }
        }
        return n == 1 ? true : false ;
        
    }
};

int main()
{
    Solution s1;
    int n  = 6;
    cout << s1.isUgly(n) << endl;
    return 0;

}