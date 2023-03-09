#include"STLCOMMON.h"
#define MAXNUM 100
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        return 0;
    }
    int fa_init(int n)
    {
        for(int i = 1; i<= n; i++){
            fa[i] = i;
        }

    }
    int find_fa(int i)
    {
        if( i == fa[i]){
            return i;
        }else{
            fa[i] = find_fa(fa[i]);
            return fa[i];
        }
    }
    void Union(int i ,int j)
    {
        int i_fa= find_fa(i);
        int j_fa = find_fa(j);
        fa[i_fa] = j_fa;
    }
    int fa[MAXNUM];
};


int main()
{
    Solution s1;
    
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    int resu = s1.makeConnected(n, connections);
    cout << "resu= " << resu << endl;
}