#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
int cal_distance(vector<pair<int, int>>&data , int num_1 , int num_2);
bool cal(vector<pair<int, int>>&data)
{
    if(data.size()!= 4){
        return false;
    }
    int distance[4] = {0};
    for(int i = 1 ; i < data.size() ; i++){
        distance[i] = cal_distance(data, 0 , i);
        cout << "distance<< " << distance[i] << endl;
    } 
    int index[4] ; // 分别存放，顶点，两边，对点的索引
    index[0] = 0;
    if( distance[1] != distance[2] && distance[1] != distance[3] ){
        return false;
    }else if( distance[1] == distance[2]){
        index[1] = 1;
        index[2] = 2;
        index[3] = 3;
    }else if( distance[1] == distance[3]){
        index[1] = 1;
        index[2] = 3;
        index[3] = 2;
    }
    // 直接距离
    int dis_1 = cal_distance(data, index[0] , index[1]);
    int dis_2 = cal_distance(data, index[0] , index[2]);
    int dis_3= cal_distance(data, index[3] , index[1]);
    int dis_4 = cal_distance(data, index[3] , index[2]);
    cout << dis_1 << " " << dis_2 << " " << dis_3 << " " << dis_4 << endl;
    
    if( dis_1 == dis_2 && dis_3 == dis_4 && dis_1 == dis_3 )
        return true;
    else 
        return false;




    /*


    //int first = distance[1];
    pair<int,int> vec_A;
    pair<int, int> vec_B;
    if( distance[1] != distance[2] && distance[1] != distance[3] ){
        return false;
    }else if( distance[1] == distance[2]){
        if(distance[1] != cal_distance(data,1,3)){
            return false;
        }
        vec_A.first = data[1].first - data[2].first;
        vec_A.second = data[1].second - data[2].second;

        vec_B.first = data[0].first - data[3].first;
        vec_B.second = data[0].second - data[3].second;

    }else if(distance[1] == distance[3]){
        if(distance[1] != cal_distance(data,1,2)){
            return false;
        }

        vec_A.first = data[1].first - data[3].first;
        vec_A.second = data[1].second - data[3].second;

        vec_B.first = data[0].first - data[2].first;
        vec_B.second = data[0].second - data[2].second;
    }
    cout << "vec_A= " << vec_A.first << " " << vec_A.second << " " << vec_B.first << " " << vec_B.second << endl;

    if(vec_A.first * vec_B.first + vec_A.second * vec_B.second != 0){
        cout << "Not ChuiZhi" << endl;
        return false;
    }
    return true;
    */
}

int cal_distance(vector<pair<int, int>>&data , int num_1 , int num_2)
{
    int distance = 0;
    distance =  (data[num_1].first - data[num_2].first) *  (data[num_1].first - data[num_2].first)  +
                (data[num_1].second - data[num_2].second) *  (data[num_1].second - data[num_2].second );
    return distance;

}
int main()
{
    vector<pair<int, int>> data;
    data.push_back({1,0});  
    data.push_back({0,3});
    data.push_back({3,-3});
    data.push_back({-1,0});
    
    if(cal(data)){
        cout << "TRue" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
    
}