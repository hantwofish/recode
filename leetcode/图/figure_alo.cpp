#include"STLCOMMON.h"
using namespace std;

#define N 30

// 邻接矩阵
class Figure{
public:
    void figureInit(vector<vector<int>>&inputData)
    {
        vector<int>zero(N,0);
        figureInfo.resize(N,vector<int>(N,0));
        for(int i = 0; i < inputData.size(); i++){
            int startIndex = inputData[i][0];
            int endIndex = inputData[i][1];
            figureInfo[startIndex][endIndex] = 1;
            figureInfo[endIndex][startIndex] = 1;
        }

    }

public:
    vector<vector<int>> figureInfo;

};

// 邻接表 复习一些 pair, trible
https://leetcode.cn/problems/network-delay-time/solution/by-dodo_1202-06x3/

unordered_map<int, vector<pair<int, int>>> adj;  // 临接表


class Figure_{
public:
    void figureInit(vector<vector<int>>&inputData)
    {
        for(int i = 0; i < inputData.size(); i++){
            int nodeID= inputData[i][0];
            figureData[nodeID].push_back(inputData[i][1]);
        }
    }
public:
    unordered_map<int, vector<int>> figureData;
};


int main()
{
    vector<vector<int>> inputData = {
        {0,1},
        {2,3},
        {6,7},
        {9,1}
    };
    cout << "hello" << endl;
    return 0;
}