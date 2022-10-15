#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        vector<int>dp;
        if(n <= 0 ){
            return 0;
        }else if(n == 1){
            return 1;
        }
        int sum = 0;
        int i = 1;
        while(sum <= n){
            dp.push_back(sum);
            sum += i;
            i++;


        }
        for(int i : dp){
            cout << " " << i;
        }
        cout << endl;
     
        return dp.size()-1;

    }
};

int main()
{
    Solution s1;
    int n = 21;
    int resu = s1.arrangeCoins(n);
    cout << "main resu= " << resu << endl;
    return 0;
}