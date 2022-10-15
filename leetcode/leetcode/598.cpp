#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = m, minb = n;
        for(int i = 0 ; i < ops.size(); i++){
            mina  = min(mina, ops[i][0]);
            minb  = min(minb, ops[i][1]);
        }
        return mina * minb;
    }

};

int main()
{
    Solution s1;
    int m = 3;
    int n = 3;
    vector<vector<int>> ops = {{2,2},{3,3}};
    int resu = s1.maxCount(m,n,ops);
    cout << "resu= " << resu << endl;
    return 0;
}