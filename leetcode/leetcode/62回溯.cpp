#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        DFS(m, n, 0 ,0,visited);
        return result;

    }
    void DFS(int M,int N , int cur_Row , int cur_Col , vector<vector<bool>>&visited)
    {
        //cout << "**  ";
        if(cur_Row < 0 || cur_Row >= M || cur_Col <0 || cur_Col >= N  ){
            return;

        }
        if( visited[cur_Row][cur_Col] ){
            return;
        }
        if(cur_Row == M -1 && cur_Col == N -1){
            result++;
           // cout << "**  " << result << endl;
            return;
        }
        visited[cur_Row][cur_Col] = true;
        // 四个方向
      //  DFS(M,N,cur_Row - 1, cur_Col + 0,visited); // 往上
        DFS(M,N,cur_Row + 1, cur_Col + 0,visited); // 下
        DFS(M,N,cur_Row + 0 ,cur_Col + 1,visited); // 右
      //  DFS(M,N,cur_Row + 0 ,cur_Col - 1,visited); // 左

        visited[cur_Row][cur_Col] = false;




    }
public:
    int result = 0;
};


int main()
{
    int m = 23;
    int n = 12;
    Solution s1;
    int resu= s1.uniquePaths(m,n);
    cout << "main resu= " << resu << endl;


    return 0;
}
