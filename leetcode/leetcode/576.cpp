#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        DFS(m,n,startRow,startColumn,maxMove);
         
        return 0;
    }
    void DFS(int m ,int n , int curtRow, int curColumn ,int leave_times)
    {
        
        if((curtRow <0 || curtRow >= m || curColumn <0 || curColumn >= n )){
            resu++;
            return;
        }
        if( leave_times == 0 ){
            return;
        }
        // 向前后左右四个方向
        DFS(m, n, curtRow -1 ,curColumn + 0 , leave_times -1);
        DFS(m, n, curtRow +1 ,curColumn + 0 , leave_times -1);
        DFS(m, n, curtRow +0 ,curColumn + 1 , leave_times -1);
        DFS(m, n, curtRow +0 ,curColumn - 1 , leave_times -1);

    }
public:
    int resu = 0;
    
};

int main()
{
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow  = 0;
    int startColumn  = 0;
    Solution s1;
    int temp = s1.findPaths(m,n,maxMove,startRow,startColumn);
    cout << "main resu= " << s1.resu << endl;
    
    
    return 0;
}

/*
https://leetcode-cn.com/problems/out-of-boundary-paths/solution/yi-ti-wu-jie-dfs-jian-zhi-ji-yi-hua-sou-k4dtg/
*/