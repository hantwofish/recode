#include"STLCOMMON.h"
using namespace std;

#define N 100

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 初始化表邻接矩阵
        figureData.resize(n, vector<int>(n,0));
        for(int i =0; i < flights.size(); i++){
            vector<int>temp = flights[i];
            cout<< temp[0] << " " << temp[1] << " " << temp[2] << endl;
            figureData[temp[0]][temp[1]] = temp[2]; 
        }

        //PrintVec(figureData);

        DfsSearch(n, figureData, src, dst, k, tempPath);

        //cout<< "resuyPath.size()= " << resuPath.size() << endl;
        //PrintVec(resuPath);


        // 选取花费最小的
        for(int i = 0; i < resuPath.size(); i++){
            if(resuPath[i].size() > k +2){
                continue;
            }
            int tempresi = 0;
            vector<int> path = resuPath[i];
            for(int j = 1; j <path.size(); j++){
                int first = path[j-1];
                int sec = path[j];
                tempresi = tempresi + figureData[first][sec];
            }
            //cout << "price= " << tempresi << endl;
            if(tempresi < totalCost){
                totalCost = tempresi;
            }
        }

        if(totalCost == INT32_MAX){
            return -1;
        }


        return totalCost;
    }
    void DfsSearch(int n ,vector<vector<int>>&figureData , int cur, int dest, int k, vector<int>&tempPath)
    {
        //cout << "DfsSearch " << " cur= " << cur << endl;
        int nodeNumber = figureData.size();
        if(cur == dest){
            cout << "cur == dst "  << endl;
            tempPath.push_back(dest);
            resuPath.push_back(tempPath);
            tempPath.pop_back();
            return;
        }
        for(int i = 0; i< nodeNumber; i++){
            //cout << "DfsSearch " << " cur= " << cur << " i= " << i << endl;
            if(figureData[cur][i] == 0){
                //cout << "figureData[" << cur<<"]"<<"[" << i << "]" << " = " << figureData[cur][i] << endl;
                continue;
            }
            tempPath.push_back(cur);
            DfsSearch(n,figureData,i,dest, k, tempPath);
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
    int totalCost = INT32_MAX;
    vector<vector<int>>resuPath;
    vector<int>tempPath;
};

int main()
{
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << "start" << endl;
    Solution s1;
    int resu = s1.findCheapestPrice(3, flights, 0, 2, 1);
    cout << "resu=  " << resu <<  endl;
    return 0;
}