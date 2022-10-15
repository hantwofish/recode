#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max_lenth = 1;
        int resu  = 1;
        int left = 0;
        int right = left +1;
        while(right < s.length()){
            if(s[right ] == s[left]){
                max_lenth ++;
                right++;
                if(right > s.length()-1){
                    resu = max(resu , max_lenth);
                }
            }else{
                resu = max(resu , max_lenth);
                max_lenth = 1;
                left = right;
                right++;
            }
        }
        return resu;

    }
};

int main()
{
    Solution s1;
    string str = "bbdddddffffffffff";
    int resu = s1.maxPower(str);
    cout << "resu = " << resu << endl;

    return 0;
}