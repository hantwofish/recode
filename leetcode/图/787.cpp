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
            //cout<< temp[0] << " " << temp[1] << " " << temp[2] << endl;
            figureData[temp[0]][temp[1]] = temp[2]; 
        }
        isVisited.resize(n,false);

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
        if(pathNode > k+ 2){
            return;
        }

        if(cur == dest){
            
            totalCost = min(totalCost, tempCost);
            //tempPath.push_back(dest);
            //resuPath.push_back(tempPath);
            //tempPath.pop_back();
            cout << "pathNode= " << pathNode << endl;

            cout << "cur == dst  tempCost = "<< tempCost <<" totalCost= "  << totalCost <<  endl;
            return;
        }
        for(int i = 0; i< nodeNumber; i++){
            //cout << "DfsSearch " << " cur= " << cur << " i= " << i << endl;
            if(figureData[cur][i] == 0){
                //cout << "figureData[" << cur<<"]"<<"[" << i << "]" << " = " << figureData[cur][i] << endl;
                continue;
            }
            if(isVisited[cur] == true){
                continue;
            }
            if(pathNode > k+ 2){
                continue;
            }
            isVisited[cur] = true;
            tempCost += figureData[cur][i];
            pathNode++;
            // tempPath.push_back(cur);
            DfsSearch(n,figureData,i,dest, k, tempPath);
            tempCost -= figureData[cur][i];
            // tempPath.pop_back();
            isVisited[cur] = false;
            pathNode--;
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
    int tempCost = 0;
    vector<int>tempPath;
    vector<bool>isVisited;
    int pathNode = 1;
};

int main()
{
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout << "start" << endl;
    Solution s1;
    int resu = s1.findCheapestPrice(4, flights, 0, 3, 1);
    cout << "resu=  " << resu <<  endl;
    return 0;
}