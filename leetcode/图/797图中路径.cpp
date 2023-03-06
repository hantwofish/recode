#include"STLCOMMON.h"

using namespace std;



class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        figureData.resize(N,vector<int>(N,0));
        // 存储数据
        for(int i = 0; i< graph.size(); i++){
            vector<int>temp = graph[i];
            for(int j  = 0; j < temp.size(); j++){
                figureData[i][temp[j]] = 1;
            }
        }

        PrintVec(figureData);

        DfsSearch(figureData, 0, N-1, tempPath);

        return resultPath;

    }
    void DfsSearch(vector<vector<int>>&figureData, int cur, int dest,vector<int>& tempPath)
    {
        int nodeNumber = figureData.size();
        if(cur == dest){
            tempPath.push_back(dest);
            resultPath.push_back(tempPath);
            tempPath.pop_back();
            return;
        }


        for(int i = 0; i < nodeNumber; i++){
            if(figureData[cur][i] == 0){
                continue;
            }
            tempPath.push_back(cur);
            DfsSearch(figureData,i, dest, tempPath);
            tempPath.pop_back();

        }     
    }
    void PrintVec(vector<vector<int>>& testVec)
    {
        for(int i = 0; i < testVec.size(); i++){
            vector<int>temp = testVec[i];
            for(int j = 0; j < temp.size();j++){
                cout << temp[j] << " ";
            }
            cout << endl;
        }
    }

public:
    vector<vector<int>>figureData;
    vector<vector<int>>resultPath;
    vector<int>tempPath;
};


int main()
{
    Solution s1;
    vector<vector<int>> graph ={
        {1,2},{3},{3},{}
    };
    vector<vector<int>> resu = s1.allPathsSourceTarget(graph);
    s1.PrintVec(resu);
    cout << "2hello" << endl;
    return 0;

}