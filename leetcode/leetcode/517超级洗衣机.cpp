// 每次选择洗衣机，并传递衣服算一步
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot = accumulate(machines.begin(),machines.end(),0);
        return 0;
    }
};

int main()
{
    Solution s1;
    vector<int>machines = {1,0,5};
    int resu = s1.findMinMoves(machines);
    cout << "main resu= " << resu << endl;
    return 0;
}