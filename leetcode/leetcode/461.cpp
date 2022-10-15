#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int resu = x ^ y;
       // cout << "resu= " << resu << endl;
        int times = 0;
        while(resu != 0){
           // cout << "resu= " << resu << " resu& 1= " << (resu & 1) << endl;
            if(resu & 1 ){
                times++;
            }
           resu =  resu >> 1;
        
        }
        return times;

    }
};

int main()
{
    int x = 1;
    int y = 4;
    Solution s1;
    int times = s1.hammingDistance(x,y);
    cout << "times= " << times << endl;
    return 0;
}