#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int cal(int N ,int M, vector<int>&W , vector<int>&P , vector<vector<int>>&way_data ,int start_num , int end_num)
    {
        
    }

};


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>W(n,0);
    vector<int>P(n,0);
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        W[i] = a;
    }
    for(int i =0 ; i< n ; i++){
        int a;
        cin >> a;
        P[i] = a;
    }
    // 接收 道路信息
    vector<vector<int>>way_data(m, vector<int>(3,0));
    for(int i = 0 ; i < m ; i++){
        int a ,b , c;
        cin >> a >> b >> c;
        way_data[i] = {a,b,c};
    }
    // 将道路连通信息转化成二维矩阵形式
    vector<vector<int>>data_of_way(n,vector<int>(n,0));
    for (int  i = 0; i < way_data.size(); i++)
    {
        data_of_way[way_data[i][0]-1][way_data[i][1]-1] = way_data[i][2]; 
        data_of_way[way_data[i][1]-1][way_data[i][0]-1] = way_data[i][2]; 
    }
    
    int start_num ;
    int end_num;
    cin >> start_num >> end_num ;

    


    return 0;

}