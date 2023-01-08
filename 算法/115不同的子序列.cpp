#include"STLCOMMON.h"

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        int sLenth = s.length();
        int tLenth = t.length();
        dpVec.resize(sLenth+1,vector<int>(tLenth+1,0));
        PrintVec();
        cout << "******" << endl;
        // base case
        for(int i  = 0; i <sLenth; i++){
            dpVec[i][0]= 0;
        }
        for(int i =0; i < tLenth; i++){
            dpVec[0][i] = 0;
        }

        return 0;
    }
    void PrintVec()
    {
        for(int i = 0; i < dpVec.size(); i++){
            for(int j = 0; j < dpVec[0].size(); j++){
                cout << dpVec[i][j] << " ";
            }
            cout << endl;
        }
    }
public:
    vector<vector<int>> dpVec;
};

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    Solution s1;
    int resu = s1.numDistinct(s,t);
    cout << "resu= " << resu << endl;
    return 0;

}