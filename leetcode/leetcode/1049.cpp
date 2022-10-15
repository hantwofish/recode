#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {

        return resu;
    }
private:
    int resu = 0;
};

int main()
{
    Solution s1;
    vector<int> stones = {12,3,4,7};
    int resu = s1.lastStoneWeightII(stones);
    cout << "resu = " << resu << endl;  
    return 0;
}

/*
一个问题分解成多个子问题 ，动态规划
[ 2 7 4 1 8 1]


*/