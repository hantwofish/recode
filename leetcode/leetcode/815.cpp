#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {


        return result;
    }
public:
    int result;
};

int main()
{
    vector<vector<int>> routes =  {{1,2,7},{3,6,7}};
    int source = 1, target = 6;
    Solution s1;
    int resu = s1.numBusesToDestination(routes , source , target);
    cout << "resu= " << resu << endl;
    return 0;
}