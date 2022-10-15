#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

#define N 20

class Solution{
public:
    void SolMain(vector<vector<int>>&data, int startIndex)
    {
        Init();
        makeFigure(data);
        dfsSearch(figureData,startIndex, visited);
    }

    void Init()
    {
        figureData.resize(N,vector<int>(N,0));
        visited.resize(N,false);
    }
    void makeFigure(vector<vector<int>>data)
    {
        for(int i =0 ; i <data.size(); i++){
            int start = data[i][0];
            int end = data[i][1];
            figureData[start][end] = 1;
        }

    }
    // 深度优先搜素遍历
    void dfsSearch(vector<vector<int>>& figure, int startIndex, vector<bool>&visited)
    {
        if(visited[startIndex] == true){
            return;
        }
        cout << "Index= " << startIndex << endl;
        visited[startIndex] = true;
        for(int i = 0; i < N; i++){
            if(figure[startIndex][i] == 1){
                dfsSearch(figure, i, visited);
            }
        }

    }
    // 找到当前节点的所有上游节点
    void findBehindNode(vector<vector<int>>&figureData, int index, vector<int>behindNode)
    {


    }

    // 找到当前节点的所有下游节点


public:
    vector<vector<int>> figureData;
    vector<bool>visited;

};  

int main()
{
    Solution s1;
    vector<vector<int>>data = {
        {1,2},{1,6},{2,6},{2,3},{3,4},{6,7},{7,4},{7,9},{9,6},{9,3}
    };
    s1.SolMain(data, 1);

    cout << "hello" << endl;
    return 0;
}