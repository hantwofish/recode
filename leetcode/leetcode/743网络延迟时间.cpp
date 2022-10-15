#include"STLCOMMON.h"

using namespace std;

#define INVAILD_VALUE 0X3f3f3f3f
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int rsvNodeId) {
        int resu = -1;
        // 初始化邻接矩阵
        figureDATA.resize(N+1,vector<int>(N+1,INVAILD_VALUE));
        for(int i =0 ; i< times.size(); i++){
            figureDATA[ times[i][0]][ times[i][1]] = times[i][2];
        }
        // 初始化 源节点到每个节点的距离
        distance.resize(N+1,INVAILD_VALUE);
        distance[rsvNodeId] = 0;
        Print_vac();

        DfsNode(figureDATA, N, rsvNodeId);
        Print_vac();

        for(int i = 1; i< distance.size(); i++){
            resu = max(resu, distance[i]);
        }


        
        if(resu == INVAILD_VALUE){
            return -1;
        }


        return resu;
    }
    // 将每个节点都遍历一遍
    void DfsNode(vector<vector<int>>& m_figureDATA, int N, int rsvNodeId)
    {
        // 对所有 相邻的节点 进行遍历
        for(int j  = 1; j <= N; j++){
            if(m_figureDATA[rsvNodeId][j] == INVAILD_VALUE){
                //continue;
            }
            int temp = distance[rsvNodeId] + m_figureDATA[rsvNodeId][j];
            
            if(temp < distance[j]){
                //cout << "rsvNodeId= "  <<rsvNodeId << " j= " << j << " TEMP= "<< temp << " dis[]= " << distance[j] << endl;
                distance[j] = temp;
                DfsNode(m_figureDATA,N, j);
            }
        }

    }
    void Print_vac()
    {
        for(auto i : distance){
            cout << i << " ";
        }
        cout<< endl;
    }
public:
    vector<int> distance;
    vector<vector<int>> figureDATA;
};

int main()
{
    Solution s1;
    vector<vector<int>>times = {{2,7,63},{4,3,60},{1,3,53},{5,6,100},{1,4,40},{4,7,95},{4,6,97},{3,4,68},{1,7,75},{2,6,84},{1,6,27},{5,3,25},{6,2,2},{3,7,57},{5,4,2},{7,1,53},{5,7,35},{4,1,60},{5,2,95},{3,5,28},{6,1,61},{2,5,28}};
    int n = 7;
    int k = 3;
    int resu = s1.networkDelayTime(times, n, k);
    cout << "main resu= " << resu << endl;
    return 0;
}