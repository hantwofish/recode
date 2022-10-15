#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        return 0;

    }
};

int main()
{
    vector<vector<int>>grid = {{1, 0}, {0, 1}};
    Solution s1;
    int resu = s1.largestIsland(grid);   
    cout << "main resu= " << resu << endl;
    return 0;
}