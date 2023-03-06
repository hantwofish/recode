#include"STLCOMMON.h"

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        return 0;
    }
};


int main()
{
    Solution s1;
    
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    int resu = s1.makeConnected(n, connections);
    cout << "resu= " << resu << endl;
}