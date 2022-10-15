#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> resu;
        for(int i = 1 ; i <= n ; i++){
            string str = "";
            if(i % 3 == 0 && i % 5 ==0){
                str += "FizzBuzz";
            }else if(i % 3 == 0){
                str += "Fizz";
            }else if(i % 5== 0){
                str += "Buzz";
            }else{
                str += to_string(i);
            }
            resu.push_back(str);

        }
        return resu;

    }
};
