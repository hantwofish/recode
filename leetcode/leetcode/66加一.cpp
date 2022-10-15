#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> add_num(digits.size(),0);
        add_num[digits.size()-1] = 1;

        for(int i = digits.size()-1; i >=0  ; i--){
            int resu = digits[i] + add_num[i];
            digits[i] = resu % 10;
            if(i == 0 && (resu / 10 != 0)){
                digits.insert(digits.begin(), resu/10);
            }else{
                add_num[i-1] = resu / 10;
            }
            
        }

        
        return digits;

    } 
};

int main()
{
    Solution s1;

    cout << (29 & 224) << endl;
    cout << (30 & 224) << endl;
    cout << (32 & 224) << endl;
    cout << (31 & 224) << endl;

    return 0;
    
}