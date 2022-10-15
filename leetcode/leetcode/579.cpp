#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {


        return 0;   
    }
};

int main()
{
    int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
    int resu = 0;
    Solution s1;
    resu = s1.findPaths(m,n , maxMove,startRow , startColumn);
    cout << "main resu= " << resu << endl;
    cout << "**** " << endl;
    string str = "a";
    char* pa;
    cout << "size= " << sizeof("aas  ")  << " " << sizeof(pa) << endl;
    return 0;
}